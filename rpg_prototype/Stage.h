#pragma once
class STAGE
{
public:
	struct
	{
		int Type[STAGE_MAX_X][STAGE_MAX_Y];
	}Chip;

	void Read()
	{
		FILE* stage;
		fopen_s(&stage, "./CourceFile/WorldMap.txt", "r");

		for (int y = 0; y < STAGE_MAX_Y; y++)
		{
			for (int x = 0; x < STAGE_MAX_X; x++)
			{
				fscanf_s(stage, "%d", &Chip.Type[x][y]);
			}
		}
	};

	void Draw(int Player_X, int Player_Y)
	{
		int pic = 0;

		for (int y = 0; y < STAGE_MAX_Y; y++)
		{
			for (int x = 0; x < STAGE_MAX_X; x++)
			{
				switch (Chip.Type[x + Player_X][y + Player_Y])
				{
				case 0:
					pic = Picture.Map[0];
					break;
				case 1:
					pic = Picture.Map[1];
					break;
				case 2:
					pic = Picture.Map[2];
					break;
				case 3:
					pic = Picture.Map[3];
					break;
				case 4:
					pic = Picture.Map[4];
					break;
				case 5:
					pic = Picture.Map[5];
					break;
				case 6:
					pic = Picture.Map[6];
					break;
				case 7:
					pic = Picture.Map[7];
					break;
				case 8:
					pic = Picture.Map[8];
					break;
				case 9:
					pic = Picture.Map[9];
					break;
				case 10:
					pic = Picture.Map[10];
					break;
				case 11:
					pic = Picture.Map[11];
					break;
				case 12:
					pic = Picture.Map[12];
					break;
				case 13:
					pic = Picture.Map[13];
					break;
				case 14:
					pic = Picture.Map[14];
					break;
				case 15:
					pic = Picture.Map[15];
					break;
				case 16:
					pic = Picture.Grace_River[0];
					break;
				case 17:
					pic = Picture.Grace_River[1];
					break;
				case 18:
					pic = Picture.Grace_River[2];
					break;
				case 19:
					pic = Picture.Grace_River[3];
					break;
				case 20:
					pic = Picture.Grace_River2[0];
					break;
				case 21:
					pic = Picture.Grace_River2[1];
					break;
				case 22:
					pic = Picture.Grace_River2[2];
					break;
				case 23:
					pic = Picture.Grace_River2[3];
					break;
				case 24:
					pic = Picture.Fill_Grace[0];
					break;
				case 25:
					pic = Picture.Fill_Grace[1];
					break;
				case 26:
					pic = Picture.Fill_Grace[2];
					break;
				case 27:
					pic = Picture.Fill_Grace[3];
					break;
				}
				DrawGraph(CELL * x, CELL * y, pic, false);
			}
		};
	};
private:
};

STAGE Stage;