#pragma once
class TITLE
{
public:
	// �^�C�g����ʂ̕\��
	void Draw()
	{
		int akane_i = 7;
		int akane_dir = 1;
		int akane_X = WIN_X / 12 + 10;
		int akane_i_t = 8;
		int loop_Num = 0;

		while (Scene == COURCE::START && ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0) {
			ClearDrawScreen();
			//�^�C�g���e�t��
			DrawFormatStringToHandle(title_X, title_Y, Color.WHITE, Font.MS[80], "K  RPG");
			DrawFormatStringToHandle(title_X + 4, title_Y + 4, Color.BLUE, Font.MS[80], "K  RPG");
			// DrawFormatStringToHandle(title_X + 45, title_Y, Color.BLUE, Font.MS[83], "U");
			DrawFormatStringToHandle(title_X + 50, title_Y - 2, Color.WHITE, Font.MS[88], "U");

			// �e�t��
			DrawFormatStringToHandle(select_X, select_Y, Color.RED, Font.Meiryo[16], "Press 1 to MAP or 2 to FIGHT");
			DrawFormatStringToHandle(select_X + 1, select_Y + 1, Color.WHITE, Font.Meiryo[16], "Press 1 to MAP or 2 to FIGHT");
			// �����˂����
			DrawGraph(akane_X, WIN_Y * 4 / 5, Picture.Player[akane_i], TRUE);
			ScreenFlip();

			// �^�C�g����ʂ̏I��
			if (Key[KEY_INPUT_2] == 1)
			{
				Scene = COURCE::WORLD;
			}
			else if (Key[KEY_INPUT_1] == 1)
			{
				Scene = COURCE::FIGHT;
			}

			// akane�̑�����
			if (loop_Num < 15) {
				loop_Num++;
				if (akane_dir == -1) {
					akane_X--;
				}
				else {
					akane_X++;
				}
			}
			else {
				loop_Num = 0;
				if (akane_dir == -1) {
					if (akane_i == 3) {
						akane_i = 4;
					}
					else if (akane_i == 4) {
						if (akane_i_t == 3) {
							akane_i = 5;
						}
						else {
							akane_i = 3;
						}
					}
					else if (akane_i == 5) {
						akane_i = 4;
					}
				}
				else {
					if (akane_i == 6) {
						akane_i = 7;
					}
					else if (akane_i == 7) {
						if (akane_i_t == 6) {
							akane_i = 8;
						}
						else {
							akane_i = 6;
						}
					}
					else {
						akane_i = 7;
					}
				}
				akane_i_t = akane_i;
			}
			if (akane_X <= 0) {
				akane_dir = 1;
				akane_i = 7;
				akane_i_t = 6;

			}
			else if (WIN_X <= akane_X + 16) {
				akane_dir = -1;
				akane_i = 4;
				akane_i_t = 3;
			}
		}
	}

	// ����L�[�\�� ->�}�b�v�̕��ŕ\��
	void Put_Keyconfig() {
		// �㉺���E �������� �L�[ 1369
		// �I�� SPACE �L�[
		// ���j���[�\�� M �L�[
		// 1�O�ɖ߂� B �L�[
		// �����I�� ESC �L�[
		;
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

		WaitKey();

		return Name;
	}

private:
	int title_X = WIN_X / 4, title_Y = title_X;
	int select_X = WIN_X / 4, select_Y = WIN_Y * 2 / 3;
	char Name[32];
};

TITLE Title;