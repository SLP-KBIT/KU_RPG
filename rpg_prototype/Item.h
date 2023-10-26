#pragma once
class ITEM : public OBJECT
{
public:
	bool move;
	int id;
	std::string using_msg;
	ITEM(int, int, int, int, int, std::string, std::string);
	void Draw(int, int, int, int, int);
	void pickedUp(int, int, int);
};

ITEM::ITEM(int x, int y, int z, int img, int id, std::string name, std::string using_msg)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->img = img;
	this->id = id;
	this->name = name;
	this->using_msg = using_msg;

	exist = true;
	move = false;
}

void ITEM::Draw(int x, int y, int z, int O_x, int O_y)
{
	if (this->x == x && this->y == y && this->z == z && exist)
	{
		DrawGraph(CELL * (x - O_x), CELL * (y - O_y), img, false);
	}
}

void ITEM::pickedUp(int x, int y, int z)
{
	if (this->x == x && this->y == y && this->z == z && (exist || !move))
	{
		std::string msg = this->name + " ‚ðŽè‚É“ü‚ê‚½I";
		showMsg(msg);
		exist = false;
		
		item_dict[id] = name;
		inventory[id] = id;
		item_used_message[item_dict[id]] = using_msg;
	}
	if (!exist)
	{
		if (this->x != x || this->y != y)
		{
			move = true;
		}
	}
}