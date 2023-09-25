#pragma once
class PLAYERDRAW
{
public:
	void RealScreenDraw();

	int loopNum = 0;
	int PicMode = 10;
	int dir = 4;
	// 上=4、左=2、右=3、下=1

	struct {
		int PicMaxU = 2;
		int PicMaxL = 5;
		int PicMaxR = 8;
		int PicMaxD = 11;

		int PicMinU = 0;
		int PicMinL = 3;
		int PicMinR = 6;
		int PicMinD = 9;
	}AniFla;

	int Player_X = 0;
	int Player_Y = 0;
	int Prev_Player_X = 0;
	int Prev_Player_Y = 0;

	void BackScreenDraw();
	void Move();
	void MoveAnime();
	void CheckCIE();

private:
};

PLAYERDRAW PlayerDraw;

void PLAYERDRAW::RealScreenDraw()
{
	Move();
	BackScreenDraw();
}

void PLAYERDRAW::Move()
{
	if (Key[KEY_INPUT_DOWN] == 1 || Key[KEY_INPUT_S] == 1)
	{
		dir = 4;
		Player_Y++;
		loopNum += 50;
	}

	if (Key[KEY_INPUT_LEFT] == 1 || Key[KEY_INPUT_A] == 1)
	{
		dir = 2;
		Player_X--;
		loopNum += 50;
	}

	if (Key[KEY_INPUT_RIGHT] == 1 || Key[KEY_INPUT_D] == 1)
	{
		dir = 3;
		Player_X++;
		loopNum += 50;
	}

	if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_W] == 1)
	{
		dir = 1;
		Player_Y--;
		loopNum += 50;
	}
};

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
	case 1:
		if (PicMode == AniFla.PicMaxD || PicMode > AniFla.PicMaxD || PicMode < AniFla.PicMinD)PicMode = 9;
		else PicMode++;
		break;
	case 2:
		if (PicMode == AniFla.PicMaxL || PicMode > AniFla.PicMaxL || PicMode < AniFla.PicMinL)PicMode = 3;
		else PicMode++;
		break;
	case 3:
		if (PicMode == AniFla.PicMaxR || PicMode > AniFla.PicMaxR || PicMode < AniFla.PicMinR)PicMode = 6;
		else PicMode++;
		break;
	case 4:
		if (PicMode == AniFla.PicMaxU || PicMode > AniFla.PicMaxU || PicMode < AniFla.PicMinU)PicMode = 0;
		else PicMode++;
		break;
	}
}

void PLAYERDRAW::CheckCIE()
{
	int Chip = Stage.Chip.Type[8 + Player_X][9 + Player_Y];

	if (Chip == 0 || Chip == 1 || Chip == 2 || Chip == 15)
	{
		Player_X = Prev_Player_X;
		Player_Y = Prev_Player_Y;
	}
}

void PLAYERDRAW::BackScreenDraw()
{
	CheckCIE();

	MoveAnime();

	Stage.Draw(Player_X, Player_Y);
	DrawGraph(8 * CELL, 9 * CELL, Picture.Player[PicMode], TRUE);

	Prev_Player_X = Player_X;
	Prev_Player_Y = Player_Y;
};