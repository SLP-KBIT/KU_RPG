#pragma once
class ENEMY
{
public:
	// 敵のアイコンとその枠線を表示する
	void ShowEnemy(int Enemy[], int BackGraound[]) {
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK); //裏画面描画
		SetBackgroundColor(256, 256, 256);
		//DrawBox(WIN_X / 4, WIN_Y / 4, 3 * WIN_X / 4 + 1, 3 * WIN_Y / 4 + 1, Color.BLACK, TRUE);
		DrawExtendGraph(WIN_X / 4, WIN_Y / 4, 3 * WIN_X / 4 + 1, 3 * WIN_Y / 4 + 1, BackGraound[0], TRUE);
		// DrawGraph(WIN_X/2 - 8, WIN_Y/2 - 8, Enemy[0], TRUE);
		DrawExtendGraph(WIN_X / 3, WIN_Y / 3, 2 * WIN_X / 3 + 1, 2 * WIN_Y / 3 + 1, Enemy[0], TRUE);
		ScreenFlip();
	}
	
	// 太枠の四角を表示 ?

private:
};

ENEMY Enemy;