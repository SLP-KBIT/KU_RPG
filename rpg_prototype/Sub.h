#pragma once
class
{
public:
	int MS[50 + 1];
	int Meiryo[50 + 1];

	void Load()
	{
		for (int i = 0; i < 50 + 1; i++)
		{
			MS[i] = CreateFontToHandle("ＭＳ ゴシック", i, 6, DX_FONTTYPE_NORMAL);
			Meiryo[i] = CreateFontToHandle("メイリオ", i, 6, DX_FONTTYPE_NORMAL);
		}
	}
private:
}Font;

class
{
public:
	int WHITE;
	int RED;
	int GREEN;
	int BLUE;
	int BLACK;

	void Load()
	{
		WHITE = GetColor(255, 255, 255);
		RED = GetColor(255, 0, 0);
		GREEN = GetColor(0, 255, 0);
		BLUE = GetColor(0, 0, 255);
		BLACK = GetColor(0, 0, 0);
	}
private:
}Color;

int Key[256] = { 0 };
int GetKey()
{
	char allKey[256];
	GetHitKeyStateAll(allKey);

	for (int i = 0; i < 256; i++)
	{
		if (allKey[i] != 0)
		{
			Key[i]++;
		}
		else
		{
			Key[i] = 0;
		}
	}
	return 0;
}

bool pushFlag[256] = { 0 };
bool isPush(int keyIndex)
{
	if (Key[keyIndex] && !pushFlag[keyIndex])
	{
		pushFlag[keyIndex] = true;
		return true;
	}
	if (!Key[keyIndex])
	{
		pushFlag[keyIndex] = false;
	}
	return false;
}

// フェードアウト
void fade_out()
{
	//フェード値の設定（0～255の値が有効）
	int i = 0;

	for (int alpha = 0; alpha <= 255; alpha += 255 * i / 100, i++) {

		//フェードの設定
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

		//黒で塗りつぶし
		DrawBox(0, 0, WIN_X, WIN_Y, GetColor(0, 0, 0), TRUE);
		ScreenFlip();
		WaitTimer(100);
	}
	//デフォルトに戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}