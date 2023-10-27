#pragma once
class ITEM : public OBJECT
{
public:
	bool move;
	bool countUp = true;
	int id;
	std::string using_msg;
	ITEM(int, int, int, int, int, std::string, std::string, int);
	void pickedUp(int, int, int);
	void Draw(int x, int y, int z, int O_x, int O_y)
	{
		if (this->x == x && this->y == y && this->z == z && exist)
		{
			DrawGraph(CELL * (x - O_x), CELL * (y - O_y), img, true);
		}
	}
	int level;
	void Used();
};

ITEM::ITEM(int x, int y, int z, int img, int id, std::string name, std::string using_msg, int level)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->img = img;
	this->id = id;
	this->name = name;
	this->using_msg = using_msg;
	this->level = level;

	exist = true;
	move = false;
}

void ITEM::pickedUp(int x, int y, int z)
{
	if (this->x == x && this->y == y && this->z == z && (exist || !move))
	{
		std::string msg = this->name + " を手に入れた！";
		showMsg(msg);
		exist = false;
		
		item_dict[id] = name;
		inventory[id] = id;
		item_used_message[item_dict[id]] = using_msg;

		if (countUp)
		{
			item_num++;
			countUp = false;
		}
	}
	if (!exist)
	{
		if (this->x != x || this->y != y)
		{
			move = true;
		}
	}
}

void ITEM::Used()
{
	std::string msg = name + " を使用した！\n" + using_msg;
	showMsg(msg);
}

ITEM* Item[ITEM_MAX_NUM];