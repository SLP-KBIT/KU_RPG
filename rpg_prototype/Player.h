#pragma once
#define LOOP_COUNT_RESET 50

class PLAYERDRAW
{
public:
	void RealScreenDraw();

	int loopNum = 0;
	int PicMode = 1;

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
		int PicMaxR = 5;
		int PicMaxL = 8;
		int PicMaxU = 11;

		int PicMinD = 0;
		int PicMinR = 3;
		int PicMinL = 6;
		int PicMinU = 9;
	}AniFla;

	struct {
		int xi, yi;
		int xo, yo;
	}WarpZone;

	int m = 1;

	int Origin_X = 0;
	int Origin_Y = 0;
	int Prev_Origin_X = 0;
	int Prev_Origin_Y = 0;

	PLAYERDRAW();
	void WarpPointSet(int xi, int yi, int xo, int yo);
	void BackScreenDraw();
	void Move();
	void MoveAnime();
	void CheckCIE();
	void Warp();
private:
};

PLAYERDRAW PlayerDraw;

PLAYERDRAW::PLAYERDRAW()
{
	WarpPointSet(26, 12, 5, 35);
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
	case DIR::RIGHT:
		if (PicMode == AniFla.PicMaxR || PicMode > AniFla.PicMaxR || PicMode < AniFla.PicMinR)PicMode = 3;
		else PicMode++;
		break;
	case DIR::DOWN:
		if (PicMode == AniFla.PicMaxD || PicMode > AniFla.PicMaxD || PicMode < AniFla.PicMinD)PicMode = 0;
		else PicMode++;
		break;
	case DIR::LEFT:
		if (PicMode == AniFla.PicMaxL || PicMode > AniFla.PicMaxL || PicMode < AniFla.PicMinL)PicMode = 6;
		else PicMode++;
		break;
	}
}

void PLAYERDRAW::CheckCIE()
{
	int Chip = Stage.Chip.Type[Origin_X + FIXED_X][Origin_Y + FIXED_Y];

	if (Chip == 0 || Chip == 1 || Chip == 2 || Chip == 15)
	{
		Origin_X = Prev_Origin_X;
		Origin_Y = Prev_Origin_Y;
	}

	if (Chip == 7)
	{
		Warp();
	}
}

void PLAYERDRAW::BackScreenDraw()
{
	CheckCIE();

	MoveAnime();

	Stage.Draw(Origin_X, Origin_Y);
	DrawGraph(FIXED_X * CELL, FIXED_Y * CELL, Picture.Player[PicMode], TRUE);

	Prev_Origin_X = Origin_X;
	Prev_Origin_Y = Origin_Y;
}

void PLAYERDRAW::WarpPointSet(int xi, int yi, int xo, int yo)
{
	WarpZone.xi = xi - FIXED_X;
	WarpZone.yi = yi - FIXED_Y;
	WarpZone.xo = xo - FIXED_X;
	WarpZone.yo = yo - FIXED_Y;
}

void PLAYERDRAW::Warp()
{
	Origin_X = WarpZone.xo;
	Origin_Y = WarpZone.yo + 1;
	WarpZone.xo = WarpZone.xi;
	WarpZone.yo = WarpZone.yi;
	WarpZone.xi = Origin_X;
	WarpZone.yi = Origin_Y - 1;
	dir = DIR::DOWN;
}