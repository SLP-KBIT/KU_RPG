#pragma once
class ENEMY : public OBJECT
{
public:
	ENEMY(int, int, int, int, std::string, std::string);
	void Event(int, int);
	void Draw(int x, int y, int z, int O_x, int O_y);

	void ShowEnemy(int Enemy, int BackGraound) {
		DrawBox(WIN_X / 4 - 5, WIN_Y / 4 - 5, 3 * WIN_X / 4 + 1 + 5, 3 * WIN_Y / 4 + 1 + 5, Color.BLACK, TRUE);
		DrawExtendGraph(WIN_X / 4, WIN_Y / 4, 3 * WIN_X / 4 + 1, 3 * WIN_Y / 4 + 1, BackGraound, TRUE);
		DrawExtendGraph(WIN_X / 3, WIN_Y / 3, 2 * WIN_X / 3 + 1, 2 * WIN_Y / 3 + 1, Enemy, TRUE);
	}
private:
	std::string msg;
	bool goFight;
};

ENEMY::ENEMY(int x, int y, int z, int img, std::string name, std::string msg)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->img = img;
	this->name = name;
	this->msg = msg;
	exist = true;
	goFight = false;
}

void ENEMY::Draw(int x, int y, int z, int O_x, int O_y)
{
	if (this->x == x && this->y == y && this->z == z && !goFight)
	{
		DrawExtendGraph(CELL * (x - O_x), CELL * (y - O_y), CELL * (x - O_x) + 3 * CELL, CELL * (y - O_y) + 3 * CELL, img, true);
	}
}

void ENEMY::Event(int y, int z)
{
	if (this->y + 5 == y && this->z == z && !goFight)
	{
		showMsg("Åy " + name + " Åz\n" + msg);
		ScreenFlip();
		WaitTimer(500);
		goFight = true;
		fade_out();
		Scene = COURCE::FIGHT;
	}
}

ENEMY Enemy(0, 0, 0, 0, "", "");