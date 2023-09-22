#pragma once
class PICTURE
{
public:
	int Map[16];
	int Grace_River[4];
	int Grace_River2[4];
	int Fill_Grace[4];
	int Player[12];
	int Slime[2];
	int SlimeBeth[2];

	void Load()
	{
		LoadDivGraph("./Picture/Maps/MapChip.png", 16, 4, 4, CELL, CELL, Map); //É}ÉbÉvì«Ç›çûÇ›
		LoadDivGraph("./Picture/Maps/grass_near_river.png", 4, 2, 2, CELL, CELL, Grace_River);
		LoadDivGraph("./Picture/Maps/grass_near_river2.png", 4, 2, 2, CELL, CELL, Grace_River2);
		LoadDivGraph("./Picture/Maps/Fill_grass.png", 4, 2, 2, CELL, CELL, Fill_Grace);
		LoadDivGraph("./Picture/Players/akane2.png", 12, 3, 4, CELL, CELL, Player);
		LoadDivGraph("./Picture/Enemys/Slime.png", 2, 2, 1, CELL, CELL, Slime);
		LoadDivGraph("./Picture/Enemys/SlimeBeth.png", 2, 2, 1, CELL, CELL, SlimeBeth);
	};
private:
};

PICTURE Picture;