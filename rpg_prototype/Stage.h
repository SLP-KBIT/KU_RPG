#pragma once
class STAGE
{
public:
	struct
	{
		int Type[12][STAGE_MAX_X][STAGE_MAX_Y];
	}Chip;

	int floor = 1;
	bool viewItem = false;
	int arrow_y = 0;

	ITEM* Antena;
	ITEM* Toilet[12];
	ENEMY* Stage_Enemy[ENEMY_MAX_NUM];

	void ItemSelect();
	void showItemName();
	void moveArrow();

	void Read()
	{
		FILE* stage[12];
		fopen_s(&stage[0], "./CourceFile/UnivMap0.txt", "r");
		fopen_s(&stage[1], "./CourceFile/UnivMap1.txt", "r");
		fopen_s(&stage[2], "./CourceFile/UnivMap2.txt", "r");
		fopen_s(&stage[3], "./CourceFile/UnivMap3.txt", "r");
		fopen_s(&stage[4], "./CourceFile/UnivMap4.txt", "r");
		fopen_s(&stage[5], "./CourceFile/UnivMap5.txt", "r");
		fopen_s(&stage[6], "./CourceFile/UnivMap6.txt", "r");
		fopen_s(&stage[7], "./CourceFile/UnivMap7.txt", "r");
		fopen_s(&stage[8], "./CourceFile/UnivMap8.txt", "r");
		fopen_s(&stage[9], "./CourceFile/UnivMap9.txt", "r");
		fopen_s(&stage[10], "./CourceFile/UnivMap10.txt", "r");
		fopen_s(&stage[11], "./CourceFile/UnivMap11.txt", "r");
		for (int k = 0; k < 12; k++)
		{
			for (int y = 0; y < STAGE_MAX_Y; y++)
			{
				for (int x = 0; x < STAGE_MAX_X; x++)
				{
					fscanf_s(stage[k], "%d", &Chip.Type[k][x][y]);
				}
			}
		}

		Item[6] = new ITEM(8, 33, 10, Picture.Item[6], 6, "�G�i�h��", "���l�I�Ȑg�̔\�͂��擾����", 10);
		Item[5] = new ITEM(10, 10, 10, Picture.Item[5], 5, "�g�C���̃}�[�N", "�}�[�N�̗����ɉB����Ă��������������g����", 6);
		Item[4] = new ITEM(8, 33, 8, Picture.Item[4], 4, "USB", "�p�\�R�����E�C���X�Ɋ������A��苭��ȗ͂���ɓ��ꂽ", 5);
		Item[3] = new ITEM(8, 33, 6, Picture.Item[3], 3, "�p�\�R��", "�l�b�g���[�N�V�X�e�����n�b�L���O����", 4);
		Item[2] = new ITEM(8, 33, 5, Picture.Item[2], 2, "�ߋ���", "�����ǂ��Ȃ���", 3);
		Item[1] = new ITEM(8, 33, 4, Picture.Item[1], 1, "�߂���", "����̎��E���L���Ȃ���", 2);
		Item[0] = new ITEM(8, 33, 3, Picture.Item[0], 0, "�T�o��", "�̗͂����サ��", 1);

		Stage_Enemy[7] = new ENEMY(7, 37, 11, Picture.Enemy[7][0], enemy[7]->getNAME(), "�������΂̒n���́A�v�Z�@�ň�ꂽ���E�ɔj�󂳂�邾�낤...\n���R�����B���̂��߂ɁA���̐��̑S�Ă̌v�Z�@��j�󂷂�B\n���l����Ƃ��ז��͂����Ȃ�...�I�I�I�I");
		Stage_Enemy[6] = new ENEMY(7, 37, 10, Picture.Enemy[6][0], enemy[6]->getNAME(), "�悭�����������������h���C�h���͂������Ă��ꂽ��ˁI\n����������I");
		Stage_Enemy[5] = new ENEMY(7, 37, 9, Picture.Enemy[5][0], enemy[5]->getNAME(), "����A���e�i�͎���������B\n���d�q�E�̉��ɍ��Ȃ��}�V���͖����̂���...\n�A���e�i�̔j��́A�����őj�~�����Ă��炤�I�I");
		Stage_Enemy[4] = new ENEMY(7, 37, 8, Picture.Enemy[4][0], enemy[4]->getNAME(), "> WARNING�I Activates the plan protection system�I\n> Are you sure you want to continue? [y/N]yyyyyyyyyy\nyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
		Stage_Enemy[3] = new ENEMY(7, 37, 6, Picture.Enemy[3][0], enemy[3]->getNAME(), "���t�t...���V�̃X�N���v�g�́A���E�����ׂɊׂ��...\n�J�I�X�Ȑ��E��...�N�����҂��Ă��̃T...�I�I�I");
		Stage_Enemy[2] = new ENEMY(7, 37, 5, Picture.Enemy[2][0], enemy[2]->getNAME(), "���H�N�ł��A�N�́B\n���H��w�Ő搶�����Ă����ʐl�ł����B\n.......�N�̂悤�Ȋ��̂����K�L�͌�������...");
		Stage_Enemy[1] = new ENEMY(7, 37, 4, Picture.Enemy[1][0], enemy[1]->getNAME(), "�ӂ����������I�I�I���̃{�X�͂Ȃ�đf���炵���l���I�I�I\n��n�߂ɂ��̑�w��Έ�F�ɐ��ߏグ�Ă��I�I�I");
		Stage_Enemy[0] = new ENEMY(7, 37, 3, Picture.Enemy[0][0], enemy[0]->getNAME(), "HEY!! HEY!!�@�g�D���b�^�b�^�@���b�^�b�^\nHEY!!HEY!!�V�ڂ����@�����ƁI\nHEY!!HEY!!�g�D���b�^�b�^�@���b�^�b�^");


		for (int i = 1; i < 12; i++)
		{
			Toilet[i] = new ITEM(13, 7, i, Picture.Toilet, -1, "�g�C���}�[�N", "�����̃g�C���̃}�[�N������...", 0);
		}
		Antena = new ITEM(7, 32, 11, Picture.Antena, -1, "����A���e�i", "���E���̌v�Z�@��j�󂵂�", 0);
	};

	void Draw(int Origin_X, int Origin_Y)
	{
		int pic = 0;

		for (int i = Origin_Y; i < Origin_Y + WIN_Y / CELL; i++)
		{
			for (int j = Origin_X; j < Origin_X + WIN_X / CELL; j++)
			{
				if (j < 0 || i < 0 || STAGE_MAX_X <= j || STAGE_MAX_Y <= i)
				{
					DrawGraph(CELL * (j - Origin_X), CELL * (i - Origin_Y), Picture.Map[19], false);
					continue;
				}
				switch (Chip.Type[floor][j][i])
				{
				case -4:
					pic = Picture.Map[42];
					break;
				case -3:
					pic = Picture.Carpet[55];
					break;
				case -2:
					pic = Picture.Map[42];
					break;
				case -1:
					pic = Picture.Elevator[0];
					break;
				case 0:
					pic = Picture.Map[0];
					break;
				case 1:
					pic = Picture.Elevator[1];
					break;
				case 11:
					pic = Picture.Elevator[11];
					break;
				case 12:
					pic = Picture.Elevator[12];
					break;
				case 13:
					pic = Picture.Fill_Grace[0];
					break;
				case 19:
					pic = Picture.Map[19];
					break;
				case 25:
					pic = Picture.Elevator[25];
					break;
				case 26:
					pic = Picture.Elevator[26];
					break;
				case 36:
					pic = Picture.Elevator[36];
					break;
				case 37:
					pic = Picture.Elevator[37];
					break;
				case 42:
					pic = Picture.Map[42];
					break;
				case 55:
					pic = Picture.Carpet[55];
					break;
				case 83:
					pic = Picture.Map[83];
					break;
				}
				DrawGraph(CELL * (j - Origin_X), CELL * (i - Origin_Y), pic, false);

				Toilet[floor]->Draw(j, i, floor, Origin_X, Origin_Y);

				for (int k = 0; k < ITEM_MAX_NUM; k++)
				{
					Item[k]->Draw(j, i, floor, Origin_X, Origin_Y);
					Item[k]->pickedUp(Origin_X + FIXED_X, Origin_Y + FIXED_Y, floor);
				}
			}
		}
		for (int i = Origin_Y; i < Origin_Y + WIN_Y / CELL; i++)
		{
			for (int j = Origin_X; j < Origin_X + WIN_X / CELL; j++)
			{
				for (int k = 0; k < ENEMY_MAX_NUM; k++)
				{
					Stage_Enemy[k]->Draw(j, i, floor, Origin_X, Origin_Y);
					Stage_Enemy[k]->Event(Origin_Y + FIXED_Y, floor);
				}
				Antena->Draw(j, i, floor, Origin_X, Origin_Y);
			}
		}
		ItemSelect();
	};
private:
};

void STAGE::ItemSelect()
{
	if (isPush(KEY_INPUT_M))
	{
		arrow_y = 0;
		viewItem = true;
	}
	if (viewItem)
	{
		DrawBox(WIN_X / 2 + 3 * CELL, 3 * CELL, WIN_X - 3 * CELL, WIN_Y / 2 + 3 * CELL, Color.BLACK, true);
		DrawFormatStringToHandle(WIN_X / 2 + 3 * CELL, 3 * CELL + arrow_y * CELL, Color.WHITE, Font.Meiryo[16], "��");
		showItemName();
		moveArrow();
		if (isPush(KEY_INPUT_B))
		{
			viewItem = false;
		}
	}
}

void STAGE::moveArrow()
{
	if (isPush(KEY_INPUT_UP)) arrow_y--;
	if (isPush(KEY_INPUT_DOWN)) arrow_y++;

	if (item_num < 2) arrow_y = 0;
	else
	{
		if (arrow_y < 0) arrow_y = 0;
		if (arrow_y == item_num) arrow_y = item_num - 1;
	}
}

void STAGE::showItemName()
{
	for (int i = 0; i < ITEM_MAX_NUM; i++)
	{
		DrawFormatStringToHandle(WIN_X / 2 + 4 * CELL, 3 * CELL + i * CELL, Color.WHITE, Font.Meiryo[16], item_dict[inventory[i]].c_str());
	}
}

STAGE Stage;