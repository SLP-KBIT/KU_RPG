#pragma once
class BATTLE
{
public:
    STATUS FightDraw(int MonsterGH, int BackGraound, STATUS User, STATUS Monster);

    // 攻撃(MP使用無し)メソッド:個々の機能追加はこれを継承する
    // なお以下はテスト用の機能
    int Attack(STATUS Offense, STATUS Defense)
    {
        int ATK;
        int pre_ATK = Offense.getATK();
        int DEF = Defense.getDEF();
        int HP = Defense.getHP();

        bool hit = Check_hit(Offense);

        int X = 20;
        int Y = WIN_Y * 3 / 4 + 10;

        if (hit == TRUE) {
            Offense.setATK(check_critical(Offense));
            ATK = Offense.getATK();
            Defense.setHP(HP - ATK);
            if (Defense.getHP() < 0) {
                Defense.setHP(0);
            }
            if (ATK == pre_ATK) {
                DrawBox(12, 352, 330, 420, GetColor(0, 0, 0), TRUE);
                DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "%s から %s への攻撃\n %d ダメージ!!\n", Offense.getNAME(), Defense.getNAME(), Offense.getATK());
            }
            else {
                DrawBox(12, 352, 330, 420, GetColor(0, 0, 0), TRUE);
                DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "クリティカル!! %s から %s への攻撃\n %d ダメージ!!\n", Offense.getNAME(), Defense.getNAME(), Offense.getATK());
                Offense.setHP(pre_ATK);
            }
        }
        else {
            DrawBox(12, 352, 330, 420, GetColor(0, 0, 0), TRUE);
            DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "ミス!! %sから%sへの攻撃は外れた\n", Offense.getNAME(), Defense.getNAME());
        }

        return Defense.getHP();
    }

    // 守り選択
    STATUS Shield(STATUS Defense) {
        Defense.setDEF(Defense.getDEF() * 1.2);
        return Defense;
    }

    // コマンドの表示
    // 命令内容もそれぞれ利用しやすいようにする
    void ShowCommand(int X, int Y, int command_num)
    {
        // 空白ぞろえ(要/不要)
        char order[4][64] = { "たたかう","どうぐ","まもる","にげる" };
        DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[15], "%s\n%s\n%s\n%s", order[0], order[1], order[2], order[3]);
        DrawFormatStringToHandle(X - 20, Y + 17 * (command_num % 4), Color.BLUE, Font.Meiryo[15], "→");
    }

    // コマンド選択
    int SelectCommand(int command_num)
    {
        // SPACEキーが選択ボタン
        if (Key[KEY_INPUT_DOWN] == 1)
        {
            command_num++;
        }
        else if (Key[KEY_INPUT_UP] == 1 && 0 < command_num)
        {
            command_num--;
        }
        else if (Key[KEY_INPUT_SPACE] == 1)
        {
            switch (command_num) {
            case 0: return -1; break;
            case 1: return -2; break;
            case 2:
            case 3: return -1; break;
            }
        }
        return (command_num % 4);
    }

    // 戦闘の終了判定
    bool BreakBattle(STATUS User, STATUS Monster)
    {
        // true  : 勝敗未確定(戦闘継続)
        // false : 勝敗確定(戦闘終了)

        int flag = false;
        if (0 >= User.getHP())
        {
            // ここに敗北メッセージを表示する関数
            //            DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "ミス!! %sから%sへの攻撃は外れた\n", Offense.getNAME(), Defense.getNAME());
            
            ;
        }
        else if (0 >= Monster.getHP())
        {
            // ここに勝利メッセージを表示する関数
            ;
        }
        else
        {
            flag = true;
        }
        if (flag == false) {
            Scene = COURCE::WORLD;
        }
        return flag;
    }

    void displayEnemy_You(STATUS User, STATUS Monster, int MonsterGH, int BackGraound) {
        // 敵画像, 敵味方のステータス, コマンド を表示
        Enemy.ShowEnemy(MonsterGH, BackGraound);
        User.displayStatus(WIN_X / 4, WIN_Y - 60);
        Monster.displayStatus(WIN_X / 2 - 30, WIN_Y / 4 - 60);
        ShowCommand(WIN_X / 2 + WIN_X / 8, WIN_Y * 3 / 4, command_num);
    };

    std::tuple<STATUS, STATUS, bool> Turn_1(STATUS Faster, STATUS Later, int MonsterGH, int BackGraound, bool flag) {

        command_num = 0;
        // 先制をどちらにするか: ステータスを増やす
        ClearDrawScreen();
        Later.setHP(Attack(Faster, Later));
        if (user_num == 1) {
            displayEnemy_You(Faster, Later, MonsterGH, BackGraound);
        }
        else {
            displayEnemy_You(Later, Faster, MonsterGH, BackGraound);
        }
        ScreenFlip();
        WaitTimer(1000);
        flag = BreakBattle(Faster, Later);

        if (flag)
        {
            ClearDrawScreen();
            Faster.setHP(Attack(Later, Faster));
            if (user_num == 1) {
                displayEnemy_You(Faster, Later, MonsterGH, BackGraound);
            }
            else {
                displayEnemy_You(Later, Faster, MonsterGH, BackGraound);
            }
            ScreenFlip();
            WaitTimer(1000);
            flag = BreakBattle(Faster, Later);
        }
        if (user_num == 1) {
            return { Faster, Later, flag };
        }
        else {
            return { Later, Faster, flag };
        }
    }

    bool Check_hit(STATUS Attacker) {
        std::random_device rnd;
        int luk = Attacker.getLUK();
        int r = rnd() % 100;

        if (r < 0) {
            r = r * (-1);
        }

        if (r <= luk) {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }

    int check_critical(STATUS Attacker) {
        std::random_device rnd;
        int r = rnd();
        int ATK = Attacker.getATK();
        if (r <= Attacker.getLUK() / 2) {
            Attacker.setATK(ATK * 1.5);
        }
        return Attacker.getATK();
    }


    //アイテム選択
    int Item_SelectCommand(int item_arrow)
    {
        if (Key[KEY_INPUT_DOWN] == 1)
        {
            item_arrow++;
        }
        else if (Key[KEY_INPUT_UP] == 1 && 0 < item_arrow)
        {
            item_arrow--;
        }
        else if (Key[KEY_INPUT_SPACE] == 1)
        {
            return -(item_arrow + 1);
        }
        return (item_arrow % item_num);
    }

    //アイテム実行
    void Item_Use(int X, int Y)
    {
        // DrawBox(20, 350, WIN_X, 460, GetColor(0, 0, 0), true);
        // DrawFormatStringToHandle(X, Y, Color.WHITE, Font.Meiryo[15], "%s を使用した !", item_dict[inventory[item_arrow]].c_str());
        // DrawFormatStringToHandle(X, Y+40, Color.WHITE, Font.Meiryo[15], item_used_message[item_dict[item_arrow]].c_str());
        Item[item_arrow]->Used();
        //user.setHP(user.getHP() + Item[item_arrow]->level * 10);
        //user.setMP(Item[item_arrow]->level * 10);
        //user.setATK(user.getATK() + Item[item_arrow]->level * 5);
        //user.setDEF(Item[item_arrow]->level * 10);
        //user.setLUK(user.getLUK() + 5);
        ScreenFlip();
        WaitTimer(1000);
    }

    void Show_item_Command(int X, int Y, int item_allow, int inventory[])
    {
        for (int i = 0; i < item_num; i++) {
            DrawFormatStringToHandle(X, Y + i * 10, Color.WHITE, Font.Meiryo[15], "%s", item_dict[inventory[i]].c_str());
        }
        DrawFormatStringToHandle(X - 20, Y + 12 * (item_allow % ITEM_MAX_NUM), Color.WHITE, Font.Meiryo[15], "→");
    }


private:
    int command_num = 0;  // コマンド選択のための変数
    int item_arrow = 0;  // アイテム選択時の矢印
    int user_num = 1; //1が先行　2が後攻
};


BATTLE Battle;

// 一回の戦闘の終始を制御
STATUS BATTLE::FightDraw(int MonsterGH, int BackGraound, STATUS User, STATUS Monster)
{
    // 初期化
    command_num = 0;
    bool flag = true;
    STATUS tmp = User;

    SetBackgroundColor(255, 255, 255); //ウィンドウの背景色

    // 戦闘BGM再生
    PlaySoundMem(Sound.B_1[0], DX_PLAYTYPE_LOOP);

    // 1ターンの繰り返し
    while (flag && ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
    {
        command_num = SelectCommand(command_num);
        while (CheckHitKey(KEY_INPUT_SPACE) == 1) {
            Key[KEY_INPUT_SPACE] = 0;
        }
        if (0 <= command_num && command_num < 4)
        {
            // コマンド選択矢印の移動
            displayEnemy_You(User, Monster, MonsterGH, BackGraound);
            ScreenFlip();
        }
        // たたかう が選択された
        else if (command_num == -1)
        {
            if (User.getSPD() > Monster.getSPD())
            {
                // 味方先攻
                user_num = 1;
                std::tie(User, Monster, flag) = Turn_1(User, Monster, MonsterGH, BackGraound, flag);
            }
            else
            {
                // 敵先攻
                user_num = 2;
                std::tie(User, Monster, flag) = Turn_1(Monster, User, MonsterGH, BackGraound, flag);
            }
            command_num = 0;
        }
        // どうぐ が選択された
        else if (command_num == -2)
        {
            do {
                // 何の道具を使うか or 戻る
                displayEnemy_You(User, Monster, MonsterGH, BackGraound);
                DrawBox(20, 350, 460, 460, GetColor(0, 0, 0), true);

                Show_item_Command(40, 350, item_arrow, inventory);
                ScreenFlip();
                item_arrow = Item_SelectCommand(item_arrow);
                if (item_arrow < 0) {
                    item_arrow = -(item_arrow + 1);
                    Item_Use(40, 350);
                    command_num = 0;
                    break;
                }
            } while (Key[KEY_INPUT_B] == 0 && flag && ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0);
            item_arrow = 0;
        }
    }
    fade_out();
    // 戦闘BGMの再生を停止
    StopSoundMem(Sound.B_1[0]);
    PlayerDraw.outside = true;

    return User;
}