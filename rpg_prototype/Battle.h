#pragma once
class BATTLE
{
public:
    STATUS FightDraw(int MonsterGH, int BackGraound, STATUS User, STATUS Monster);

    // �U��(MP�g�p����)���\�b�h:�X�̋@�\�ǉ��͂�����p������
    // �Ȃ��ȉ��̓e�X�g�p�̋@�\
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
                DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "%s ���� %s �ւ̍U��\n %d �_���[�W!!\n", Offense.getNAME(), Defense.getNAME(), Offense.getATK());
            }
            else {
                DrawBox(12, 352, 330, 420, GetColor(0, 0, 0), TRUE);
                DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "�N���e�B�J��!! %s ���� %s �ւ̍U��\n %d �_���[�W!!\n", Offense.getNAME(), Defense.getNAME(), Offense.getATK());
                Offense.setHP(pre_ATK);
            }
        }
        else {
            DrawBox(12, 352, 330, 420, GetColor(0, 0, 0), TRUE);
            DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "�~�X!! %s����%s�ւ̍U���͊O�ꂽ\n", Offense.getNAME(), Defense.getNAME());
        }

        return Defense.getHP();
    }

    // ���I��
    STATUS Shield(STATUS Defense) {
        Defense.setDEF(Defense.getDEF() * 1.2);
        return Defense;
    }

    // �R�}���h�̕\��
    // ���ߓ��e�����ꂼ�ꗘ�p���₷���悤�ɂ���
    void ShowCommand(int X, int Y, int command_num)
    {
        // �󔒂��낦(�v/�s�v)
        char order[4][64] = { "��������","�ǂ���","�܂���","�ɂ���" };
        DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[15], "%s\n%s\n%s\n%s", order[0], order[1], order[2], order[3]);
        DrawFormatStringToHandle(X - 20, Y + 17 * (command_num % 4), Color.BLUE, Font.Meiryo[15], "��");
    }

    // �R�}���h�I��
    int SelectCommand(int command_num)
    {
        // SPACE�L�[���I���{�^��
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

    // �퓬�̏I������
    bool BreakBattle(STATUS User, STATUS Monster)
    {
        // true  : ���s���m��(�퓬�p��)
        // false : ���s�m��(�퓬�I��)

        int flag = false;
        if (0 >= User.getHP())
        {
            // �����ɔs�k���b�Z�[�W��\������֐�
            //            DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.WHITE, Font.Meiryo[15], "�~�X!! %s����%s�ւ̍U���͊O�ꂽ\n", Offense.getNAME(), Defense.getNAME());
            
            ;
        }
        else if (0 >= Monster.getHP())
        {
            // �����ɏ������b�Z�[�W��\������֐�
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
        // �G�摜, �G�����̃X�e�[�^�X, �R�}���h ��\��
        Enemy.ShowEnemy(MonsterGH, BackGraound);
        User.displayStatus(WIN_X / 4, WIN_Y - 60);
        Monster.displayStatus(WIN_X / 2 - 30, WIN_Y / 4 - 60);
        ShowCommand(WIN_X / 2 + WIN_X / 8, WIN_Y * 3 / 4, command_num);
    };

    std::tuple<STATUS, STATUS, bool> Turn_1(STATUS Faster, STATUS Later, int MonsterGH, int BackGraound, bool flag) {

        command_num = 0;
        // �搧���ǂ���ɂ��邩: �X�e�[�^�X�𑝂₷
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


    //�A�C�e���I��
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

    //�A�C�e�����s
    void Item_Use(int X, int Y)
    {
        // DrawBox(20, 350, WIN_X, 460, GetColor(0, 0, 0), true);
        // DrawFormatStringToHandle(X, Y, Color.WHITE, Font.Meiryo[15], "%s ���g�p���� !", item_dict[inventory[item_arrow]].c_str());
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
        DrawFormatStringToHandle(X - 20, Y + 12 * (item_allow % ITEM_MAX_NUM), Color.WHITE, Font.Meiryo[15], "��");
    }


private:
    int command_num = 0;  // �R�}���h�I���̂��߂̕ϐ�
    int item_arrow = 0;  // �A�C�e���I�����̖��
    int user_num = 1; //1����s�@2����U
};


BATTLE Battle;

// ���̐퓬�̏I�n�𐧌�
STATUS BATTLE::FightDraw(int MonsterGH, int BackGraound, STATUS User, STATUS Monster)
{
    // ������
    command_num = 0;
    bool flag = true;
    STATUS tmp = User;

    SetBackgroundColor(255, 255, 255); //�E�B���h�E�̔w�i�F

    // �퓬BGM�Đ�
    PlaySoundMem(Sound.B_1[0], DX_PLAYTYPE_LOOP);

    // 1�^�[���̌J��Ԃ�
    while (flag && ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
    {
        command_num = SelectCommand(command_num);
        while (CheckHitKey(KEY_INPUT_SPACE) == 1) {
            Key[KEY_INPUT_SPACE] = 0;
        }
        if (0 <= command_num && command_num < 4)
        {
            // �R�}���h�I����̈ړ�
            displayEnemy_You(User, Monster, MonsterGH, BackGraound);
            ScreenFlip();
        }
        // �������� ���I�����ꂽ
        else if (command_num == -1)
        {
            if (User.getSPD() > Monster.getSPD())
            {
                // ������U
                user_num = 1;
                std::tie(User, Monster, flag) = Turn_1(User, Monster, MonsterGH, BackGraound, flag);
            }
            else
            {
                // �G��U
                user_num = 2;
                std::tie(User, Monster, flag) = Turn_1(Monster, User, MonsterGH, BackGraound, flag);
            }
            command_num = 0;
        }
        // �ǂ��� ���I�����ꂽ
        else if (command_num == -2)
        {
            do {
                // ���̓�����g���� or �߂�
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
    // �퓬BGM�̍Đ����~
    StopSoundMem(Sound.B_1[0]);
    PlayerDraw.outside = true;

    return User;
}