#pragma once
class TITLE
{
public:
	void Draw()
	{
		//‰e•t‚«
		DrawFormatStringToHandle(22, 34, Color.WHITE, Font.MS[50], "Dx\nRPG");
		DrawFormatStringToHandle(18, 30, Color.BLUE, Font.MS[50], "Dx\nRPG");
		//‰e•t‚«
		DrawFormatStringToHandle(20, 152, Color.RED, Font.Meiryo[16], "Press Enter to MAP or 1 to FIGHT");
		DrawFormatStringToHandle(18, 150, Color.WHITE, Font.Meiryo[16], "Press Enter to MAP or 1 to FIGHT");

		if (Key[KEY_INPUT_RETURN] == 1)
		{
			Scene = COURCE::WORLD;
		}
		else if (Key[KEY_INPUT_1] == 1)
		{
			Scene = COURCE::FIGHT;
		}
	}
private:
};

TITLE Title;