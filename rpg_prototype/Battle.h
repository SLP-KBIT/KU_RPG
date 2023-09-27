#pragma once
class BATTLE
{
public:
	void FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster);

	// 攻撃(MP使用無し)メソッド:個々の機能追加はこれを継承する
	// なお以下はテスト用の機能
	void Attack(STATUS Offense, STATUS Defense)
	{
		int ATK = Offense.getATK();
		int DEF = Defense.getDEF();
		int HP = Defense.getHP();
		Defense.setHP(HP - (ATK - DEF));
	}

	// コマンドの表示
	// 命令内容もそれぞれ利用しやすいようにする
	int ShowCommand(int X, int Y, int command_num)
	{
		// 空白ぞろえ
		char order[4][64] = { "たたかう","どうぐ","まもる","にげる" };
		DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[15], "%s\n%s\n%s\n%s", order[0], order[1], order[2], order[3]);
		DrawFormatStringToHandle(X - 20, Y + 17 * (command_num), Color.BLUE, Font.Meiryo[15], "→");
		command_num = this->SelectCommand(command_num);
		return command_num;
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
		return (command_num % 4);
	}


	// ダメージを受けるメソッド
//	void takeDamage(int damage) {
//		// 防御力を考慮して実際のダメージを計算
//		int actualDamage = damage - DEF;
//		if (actualDamage > 0) {
//			HP -= actualDamage;
//		}
//	}

	// 戦闘の終了判定
	bool BreakBattle(STATUS User, STATUS Monster)
	{
		// true  : 勝敗未確定(戦闘継続)
		// false : 勝敗確定(戦闘終了)

		int flag = true;
		if (0 >= User.getHP())
		{
			// ここに敗北メッセージを表示する関数
			flag = false;
		}
		else if (0 >= Monster.getHP())
		{
			// ここに勝利メッセージを表示する関数
			flag = false;
		}
		return flag;
	}

private:
};

BATTLE Battle;

// 一回の戦闘の終始を制御
void BATTLE::FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster)
{
	int command_num = 0;  // コマンド選択のための変数
	bool flag = true;

	while (ScreenFlip() == 0 && ClearDrawScreen && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0 && flag)
	{
		// 敵画像と敵/味方のステータス表示
		Enemy.ShowEnemy(MonsterGH, BackGraound);
		User.displayStatus(WIN_X / 4, WIN_Y - 60);
		Monster.displayStatus(WIN_X / 2 - 30, WIN_Y / 4 - 60);

		command_num = Battle.ShowCommand(WIN_X / 2 + WIN_X / 8, WIN_Y * 3 / 4, command_num);
		flag = BreakBattle(User, Monster);
	}
}