#pragma once
class TITLE
{
public:
	// �^�C�g����ʂ̕\��
	void Draw()
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK); //����ʕ`��
		//�e�t��
		DrawFormatStringToHandle(22, 34, Color.WHITE, Font.MS[50], "Dx\nRPG");
		DrawFormatStringToHandle(18, 30, Color.BLUE, Font.MS[50], "Dx\nRPG");
		//�e�t��
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

	// ���O�̓��͂����߂�
	const char* InputName()
	{
		// ���O���͎w��������̕`��
		DrawString(0, 0, "���O����͂��Ă�������", GetColor(255, 255, 255));

		// ���O�̓���
		KeyInputString(0, 16, 30, Name, FALSE);

		// ��ʂ̏�����
		ClearDrawScreen();

		// ���O�̕\��
		DrawString(0, 0, "���Ȃ��̖��O��", GetColor(255, 255, 255));
		DrawString(0, 16, Name, GetColor(255, 255, 255));

		// �L�[���͑҂�    
		//WaitKey();
		return Name;
	}

private:
	char Name[32];
};

TITLE Title;