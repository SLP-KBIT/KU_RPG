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
	int BackGraound[8];

	// 新マップ
	int Toilet;
	int Antena;
	int Item[ITEM_MAX_NUM];
	int Enemy[ENEMY_MAX_NUM][2];

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
		BackGraound[0] = LoadGraph("./Picture/Backgrounds/pure_forest.png");

		// 新マップ
		Toilet = LoadGraph("./Picture/Items/toilet.png");
		Antena = LoadGraph("./Picture/Items/antena.png");

		Item[6] = LoadGraph("./Picture/Items/potion.png");
		Item[5] = LoadGraph("./Picture/Items/toilet.png");
		Item[4] = LoadGraph("./Picture/Items/usb.png");
		Item[3] = LoadGraph("./Picture/Items/pc.png");
		Item[2] = LoadGraph("./Picture/Items/kakomon.png");
		Item[1] = LoadGraph("./Picture/Items/glass.png");
		Item[0] = LoadGraph("./Picture/Items/sabakan.png");
		
		Enemy[7][0] = LoadGraph("./Picture/Enemys/ando.png");
		Enemy[6][0] = LoadGraph("./Picture/Enemys/kida_map.png");
		Enemy[5][0] = LoadGraph("./Picture/Enemys/kamei_map.png");
		Enemy[4][0] = LoadGraph("./Picture/Enemys/kagawa_map.png");
		Enemy[3][0] = LoadGraph("./Picture/Enemys/saisho.png");
		Enemy[2][0] = LoadGraph("./Picture/Enemys/takagi.png");
		Enemy[1][0] = LoadGraph("./Picture/Enemys/yaegashi_map.png");
		Enemy[0][0] = LoadGraph("./Picture/Enemys/solo_vr_dancer.png");

		Enemy[7][1] = Enemy[7][0];
		Enemy[6][1] = LoadGraph("./Picture/Enemys/kida_battle.png");
		Enemy[5][1] = LoadGraph("./Picture/Enemys/kamei_battle.png");
		Enemy[4][1] = LoadGraph("./Picture/Enemys/kagawa_battle.png");
		Enemy[3][1] = Enemy[3][0];
		Enemy[2][1] = Enemy[2][0];
		Enemy[1][1] = LoadGraph("./Picture/Enemys/yaegashi_battle.png");
		Enemy[0][1] = LoadGraph("./Picture/Enemys/duo_vr_dancers.png");

		LoadDivGraph("./Picture/Maps/SF_A5_32(VX_XP).png", 128, 8, 16, CELL, CELL, Map);
		LoadDivGraph("./Picture/Maps/elevator.png", 88, 11, 8, CELL, CELL, Elevator);
		LoadDivGraph("./Picture/Maps/carpet.png", 192, 16, 12, CELL, CELL, Carpet);
	};
private:
};

PICTURE Picture;