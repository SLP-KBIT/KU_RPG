#pragma once
class BATTLE
{
public:
	void EnemyDraw(int Enemy[])
	{
		;//SetDrawScreen(DX_SCREEN_BACK);
	}

	// 攻撃(MP使用無し)メソッド:個々の機能追加はこれを継承する
	// なお以下はテスト用の機能
	void Attack(STATUS Offense, STATUS Defense)
	{
		int ATK = Offense.getATK();
		int DEF = Defense.getDEF();
		int HP = Defense.getHP();
		Defense.setHP(HP - (ATK - DEF));

	}

	// コマンドの表示(引数が座標なのはテストだから)
	// 命令内容もそれぞれ利用しやすいようにする
	void ShowCommand(int X, int Y)
	{
		// 空白ぞろえ
		char order1[64] = "たたかう";
		char order2[64] = "  どうぐ";
		char order3[64] = "  まもる";
		char order4[64] = "  にげる";
		DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[16], " %s  %s\n %s  %s", order1, order2, order3, order4);
	}

	// 


	// ダメージを受けるメソッド
//	void takeDamage(int damage) {
//		// 防御力を考慮して実際のダメージを計算
//		int actualDamage = damage - DEF;
//		if (actualDamage > 0) {
//			HP -= actualDamage;
//		}
//	}

private:
};

BATTLE Battle;