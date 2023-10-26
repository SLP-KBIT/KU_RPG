#pragma once
class PICTURE
{
public:
	// int Map[16];
	int Grace_River[4];
	int Grace_River2[4];
	int Fill_Grace[4];
	int Player[12];
	int Slime[2];
	int SlimeBeth[2];
	int BackGraound_Forest[1];

	// 新マップ
	int Toilet;
	int Item[ITEM_NUM];
	int Map[128];
	int Elevator[88];
	int Carpet[192];

	void Load()
	{
		// 用意した画像を読み込んでプログラム上で扱えるようにしている
		// CELLはサイズ
		// LoadDivGraph("./Picture/Maps/MapChip.png", 16, 4, 4, CELL, CELL, Map); //マップ読み込み
		LoadDivGraph("./Picture/Maps/grass_near_river.png", 4, 2, 2, CELL, CELL, Grace_River);
		LoadDivGraph("./Picture/Maps/grass_near_river2.png", 4, 2, 2, CELL, CELL, Grace_River2);
		LoadDivGraph("./Picture/Maps/Fill_grass.png", 4, 2, 2, CELL, CELL, Fill_Grace);
		LoadDivGraph("./Picture/Players/akane2.png", 12, 3, 4, CELL, CELL, Player);
		LoadDivGraph("./Picture/Enemys/Slime.png", 2, 2, 1, CELL, CELL, Slime);
		LoadDivGraph("./Picture/Enemys/SlimeBeth.png", 2, 2, 1, CELL, CELL, SlimeBeth);
		BackGraound_Forest[0] = LoadGraph("./Picture/Backgrounds/pure_forest.png");

		// 新マップ
		Toilet = LoadGraph("./Picture/Items/toilet.png");
		Item[0] = LoadGraph("./Picture/Items/potion.png");
		Item[1] = LoadGraph("./Picture/Items/usb.png");
		LoadDivGraph("./Picture/Maps/SF_A5_32(VX_XP).png", 128, 8, 16, CELL, CELL, Map);
		LoadDivGraph("./Picture/Maps/elevator.png", 88, 11, 8, CELL, CELL, Elevator);
		LoadDivGraph("./Picture/Maps/carpet.png", 192, 16, 12, CELL, CELL, Carpet);
	};
private:
};

PICTURE Picture;