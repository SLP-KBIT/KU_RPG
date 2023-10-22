#pragma once
#define LOOP_COUNT_RESET 50

struct WARPZONE
{
	int xup, xdown, xo;
	int yup, ydown, yo;
	int floor;
};

class PLAYERDRAW
{
public:
	void RealScreenDraw();

	int loopNum = 0;
	int PicMode = 1;

	struct WARPZONE WarpZone[15];

	// 時計回りの方向でカウントアップ
	enum DIR {
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};
	int dir = DIR::DOWN;

	struct {
		int PicMaxD = 2;
		int PicMaxL = 5;
		int PicMaxR = 8;
		int PicMaxU = 11;

		int PicMinD = 0;
		int PicMinL = 3;
		int PicMinR = 6;
		int PicMinU = 9;
	}AniFla;

	int m = 1;

	int Origin_X = -5;
	int Origin_Y = -5;
	int Prev_Origin_X = 0;
	int Prev_Origin_Y = 0;

	PLAYERDRAW();
	void BackScreenDraw();
	void Move();
	void MoveAnime();
	void CheckCIE();
	void fade_in();
	void showMsg(std::string);
private:
};

PLAYERDRAW PlayerDraw;

PLAYERDRAW::PLAYERDRAW()
{
	for (int i = 3; i <= 11; i++)
	{
		WarpZone[i].xo = 15;
		WarpZone[i].yo = 13;
		WarpZone[i].xup = 14;
		WarpZone[i].yup = 11;
		WarpZone[i].xdown = 15;
		WarpZone[i].ydown = 11;
		WarpZone[i].floor = i;
	}
}

void PLAYERDRAW::RealScreenDraw()
{
	Move();
	BackScreenDraw();
}

void PLAYERDRAW::Move()
{
	if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_W] == 1)
	{
		dir = DIR::UP;
		Origin_Y--;
		loopNum += LOOP_COUNT_RESET;
	}

	if (Key[KEY_INPUT_LEFT] == 1 || Key[KEY_INPUT_A] == 1)
	{
		dir = DIR::LEFT;
		Origin_X--;
		loopNum += LOOP_COUNT_RESET;
	}

	if (Key[KEY_INPUT_DOWN] == 1 || Key[KEY_INPUT_S] == 1)
	{
		dir = DIR::DOWN;
		Origin_Y++;
		loopNum += LOOP_COUNT_RESET;
	}

	if (Key[KEY_INPUT_RIGHT] == 1 || Key[KEY_INPUT_D] == 1)
	{
		dir = DIR::RIGHT;
		Origin_X++;
		loopNum += LOOP_COUNT_RESET;
	}

	if (Key[KEY_INPUT_E] == 1)
	{
		DrawBox(50, 50, 150, 200, GetColor(0, 0, 0), true);
	}
}

void PLAYERDRAW::MoveAnime()
{
	if (loopNum < 50)
	{
		loopNum++;
		return;
	}
	loopNum = 0;
	switch (dir)
	{
	case DIR::UP:
		if (PicMode == 9)
		{
			PicMode++;
			m *= -1;
		}
		else if (PicMode == 10)
		{
			PicMode += m;
		}
		else if (PicMode == 11)
		{
			PicMode--;
			m *= -1;
		}
		else if (PicMode < AniFla.PicMinU)
		{
			PicMode = 10;
		}
		else if (AniFla.PicMaxU < PicMode)
		{
			PicMode = 10;
		}
		break;
	case DIR::LEFT:
		if (PicMode == 3)
		{
			PicMode++;
			m *= -1;
		}
		else if (PicMode == 4)
		{
			PicMode += m;
		}
		else if (PicMode == 5)
		{
			PicMode--;
			m *= -1;
		}
		else if (PicMode < AniFla.PicMinL)
		{
			PicMode = 4;
		}
		else if (AniFla.PicMaxL < PicMode)
		{
			PicMode = 4;
		}
		break;
	case DIR::DOWN:
		if (PicMode == 0)
		{
			PicMode++;
			m *= -1;
		}
		else if (PicMode == 1)
		{
			PicMode += m;
		}
		else if (PicMode == 2)
		{
			PicMode--;
			m *= -1;
		}
		else if (PicMode < AniFla.PicMinD)
		{
			PicMode = 1;
		}
		else if (AniFla.PicMaxD < PicMode)
		{
			PicMode = 1;
		}
		break;
	case DIR::RIGHT:
		if (PicMode == 6)
		{
			PicMode++;
			m *= -1;
		}
		else if (PicMode == 7)
		{
			PicMode += m;
		}
		else if (PicMode == 8)
		{
			PicMode--;
			m *= -1;
		}
		else if (PicMode < AniFla.PicMinR)
		{
			PicMode = 7;
		}
		else if (AniFla.PicMaxR < PicMode)
		{
			PicMode = 7;
		}
		break;
	}
}

void PLAYERDRAW::CheckCIE()
{
	int Chip = Stage.Chip.Type[Stage.floor][Origin_X + FIXED_X][Origin_Y + FIXED_Y];

	if (Chip == 0 || Chip == 2 || Chip == 11 || Chip == 12 || Chip == 19)
	{
		Origin_X = Prev_Origin_X;
		Origin_Y = Prev_Origin_Y;
	}

	if (Origin_X + FIXED_X == WarpZone[Stage.floor].xup && Origin_Y + FIXED_Y == WarpZone[Stage.floor].yup)
	{
		fade_out();
		Stage.floor++;
		Origin_X = WarpZone[Stage.floor].xo - FIXED_X;
		Origin_Y = WarpZone[Stage.floor].yo - FIXED_Y;
		dir = DIR::DOWN;
		PicMode = 1;
		fade_in();
	}

	if (Origin_X + FIXED_X == WarpZone[Stage.floor].xdown && Origin_Y + FIXED_Y == WarpZone[Stage.floor].ydown)
	{
		fade_out();
		Stage.floor--;
		Origin_X = WarpZone[Stage.floor].xo - FIXED_X - 1;
		Origin_Y = WarpZone[Stage.floor].yo - FIXED_Y;
		dir = DIR::DOWN;
		PicMode = 1;
		fade_in();
	}

	if (Origin_X + FIXED_X == 12)
	{
		if (Origin_Y + FIXED_Y == 5 || Origin_Y + FIXED_Y == 6)
		{
			std::string msg = "男子大学生「キャーーーーー！！！」\n茜ちゃん「すんませんっ！！すんませんっ！！」";
			showMsg(msg);
		}
		else if (Origin_Y + FIXED_Y == 8 || Origin_Y + FIXED_Y == 9)
		{
			std::string msg = "茜ちゃん「たまには男子トイレで用を足してみたいな...」";
			showMsg(msg);
		}
	}
	if (Origin_Y + FIXED_Y == 12)
	{
		if (Origin_X + FIXED_X == 2 || Origin_X + FIXED_X == 3 || Origin_X + FIXED_X == 5)
		{
			std::string msg = "茜ちゃん「どうやらエレベーターは使えないらしい」";
			showMsg(msg);
		}
	}
	if (Chip == -2)
	{
		fade_out();
		Origin_X = 9 - FIXED_X;
		Origin_Y = 4 - FIXED_Y;
		fade_in();
	}

	if (Chip == 36 || Chip == 37)
	{
		fade_out();
		Origin_X = 8 - FIXED_X;
		Origin_Y = 47 - FIXED_Y;
		fade_in();
	}
}

void PLAYERDRAW::BackScreenDraw()
{
	MoveAnime();

	Stage.Draw(Origin_X, Origin_Y);
	DrawGraph(FIXED_X * CELL, FIXED_Y * CELL, Picture.Player[PicMode], TRUE);
	CheckCIE();

	Prev_Origin_X = Origin_X;
	Prev_Origin_Y = Origin_Y;
}

void PLAYERDRAW::fade_in()
{
	int i = 0;
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	for (int alpha = 255; alpha >= 0; alpha -= 255 * i / 100, i++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		Stage.Draw(Origin_X, Origin_Y);
		DrawGraph(FIXED_X * CELL, FIXED_Y * CELL, Picture.Player[PicMode], TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawBox(0, 0, WIN_X, WIN_Y, GetColor(0, 0, 0), TRUE);
		
		ScreenFlip();
		WaitTimer(30);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void PLAYERDRAW::showMsg(std::string msg)
{
	DrawBox(0, 390, WIN_X, WIN_Y, Color.BLACK, true);
	DrawFormatStringToHandle(15, 400, Color.WHITE, Font.Meiryo[16], msg.c_str());
}