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

	// �V�}�b�v
	int Toilet;
	int Map[128];
	int Elevator[88];
	int Carpet[192];

	void Load()
	{
		// �p�ӂ����摜��ǂݍ���Ńv���O������ň�����悤�ɂ��Ă���
		// CELL�̓T�C�Y
		// LoadDivGraph("./Picture/Maps/MapChip.png", 16, 4, 4, CELL, CELL, Map); //�}�b�v�ǂݍ���
		LoadDivGraph("./Picture/Maps/grass_near_river.png", 4, 2, 2, CELL, CELL, Grace_River);
		LoadDivGraph("./Picture/Maps/grass_near_river2.png", 4, 2, 2, CELL, CELL, Grace_River2);
		LoadDivGraph("./Picture/Maps/Fill_grass.png", 4, 2, 2, CELL, CELL, Fill_Grace);
		LoadDivGraph("./Picture/Players/akane2.png", 12, 3, 4, CELL, CELL, Player);
		LoadDivGraph("./Picture/Enemys/Slime.png", 2, 2, 1, CELL, CELL, Slime);
		LoadDivGraph("./Picture/Enemys/SlimeBeth.png", 2, 2, 1, CELL, CELL, SlimeBeth);
		BackGraound_Forest[0] = LoadGraph("./Picture/Backgrounds/pure_forest.png");

		// �V�}�b�v
		Toilet = LoadGraph("./Picture/Maps/toilet.png");
		LoadDivGraph("./Picture/Maps/SF_A5_32(VX_XP).png", 128, 8, 16, CELL, CELL, Map);
		LoadDivGraph("./Picture/Maps/elevator.png", 88, 11, 8, CELL, CELL, Elevator);
		LoadDivGraph("./Picture/Maps/carpet.png", 192, 16, 12, CELL, CELL, Carpet);
	};
private:
};

PICTURE Picture;