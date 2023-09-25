#pragma once
class TITLE
{
public:
	// タイトル画面の表示
	void Draw()
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK); //裏画面描画
		//影付き
		DrawFormatStringToHandle(22, 34, Color.WHITE, Font.MS[50], "Dx\nRPG");
		DrawFormatStringToHandle(18, 30, Color.BLUE, Font.MS[50], "Dx\nRPG");
		//影付き
		DrawFormatStringToHandle(20, 152, Color.RED, Font.Meiryo[16], "Press Enter to MAP or 1 to FIGHT");
		DrawFormatStringToHandle(18, 150, Color.WHITE, Font.Meiryo[16], "Press Enter to MAP or 1 to FIGHT");

		ScreenFlip();
		Key[KEY_INPUT_RETURN] = 0;

		if (Key[KEY_INPUT_RETURN] == 1)
		{
			Scene = COURCE::WORLD;
		}
		else if (Key[KEY_INPUT_1] == 1)
		{
			Scene = COURCE::FIGHT;
		}
	}

	// 名前の入力を求める
	const char* InputName()
	{
		// 名前入力指示文字列の描画
		DrawString(0, 0, "名前を入力してください", GetColor(255, 255, 255));

		// 名前の入力
		KeyInputString(0, 16, 30, Name, FALSE);

		// 画面の初期化
		ClearDrawScreen();

		// 名前の表示
		DrawString(0, 0, "あなたの名前は", GetColor(255, 255, 255));
		DrawString(0, 16, Name, GetColor(255, 255, 255));

		// キー入力待ち    
		//WaitKey();
		return Name;
	}

private:
	char Name[32];
};

TITLE Title;