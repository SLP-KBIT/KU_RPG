#pragma once
class BATTLE
{
public:
	STATUS FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster);

	// �U��(MP�g�p����)���\�b�h:�X�̋@�\�ǉ��͂�����p������
	// �Ȃ��ȉ��̓e�X�g�p�̋@�\
	int Attack(STATUS Offense, STATUS Defense)
	{
		int ATK = Offense.getATK();
		int DEF = Defense.getDEF();
		int HP = Defense.getHP();
		Defense.setHP(HP - ATK);
		DrawFormatStringToHandle(20, WIN_Y * 3 / 4 + 10, Color.BLACK, Font.Meiryo[15], "%s ���� %s �ւ̍U��\n %d �_���[�W!!\n", Offense.getNAME(), Defense.getNAME(), Offense.getATK());
		return Defense.getHP();
	}

	// �R�}���h�̕\��
	// ���ߓ��e�����ꂼ�ꗘ�p���₷���悤�ɂ���
	void ShowCommand(int X, int Y, int command_num)
	{
		// �󔒂��낦(�v/�s�v)
		char order[4][64] = { "��������","�ǂ���","�܂���","�ɂ���" };
		DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[15], "%s\n%s\n%s\n%s", order[0], order[1], order[2], order[3]);
		DrawFormatStringToHandle(X - 20, Y + 17 * (command_num % 4), Color.BLUE, Font.Meiryo[15], "��");
	}

	// �R�}���h�I��
	int SelectCommand(int command_num)
	{
		// SPACE�L�[���I���{�^��
		if (Key[KEY_INPUT_DOWN] == 1)
		{
			command_num++;
		}
		else if (Key[KEY_INPUT_UP] == 1 && 0 < command_num)
		{
			command_num--;
		}
		else if (Key[KEY_INPUT_SPACE] == 1)
		{
			return -1;
		}
		return (command_num % 4);
	}


	// �_���[�W���󂯂郁�\�b�h
//	void takeDamage(int damage) {
//		// �h��͂��l�����Ď��ۂ̃_���[�W���v�Z
//		int actualDamage = damage - DEF;
//		if (actualDamage > 0) {
//			HP -= actualDamage;
//		}
//	}

	// �퓬�̏I������
	bool BreakBattle(STATUS User, STATUS Monster)
	{
		// true  : ���s���m��(�퓬�p��)
		// false : ���s�m��(�퓬�I��)

		int flag = false;
		if (0 >= User.getHP())
		{
			// �����ɔs�k���b�Z�[�W��\������֐�
			;
		}
		else if (0 >= Monster.getHP())
		{
			// �����ɏ������b�Z�[�W��\������֐�
			;
		}
		else
		{
			flag = true;
		}
		if (flag == false) {
			Scene = COURCE::WORLD;
		}
		return flag;
	}

	void display() {
		;
	}

private:
	int command_num = 0;  // �R�}���h�I���̂��߂̕ϐ�
};

BATTLE Battle;

// ���̐퓬�̏I�n�𐧌�
STATUS BATTLE::FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster)
{
	command_num = 0;  // ������
	bool flag = true;
	// �G�摜�ƓG/�����̃X�e�[�^�X�\��
	SetBackgroundColor(255, 255, 255); //�E�B���h�E�̔w�i�F

	// �G�摜�ƓG/�����̃X�e�[�^�X�\��
	auto displayEnemy_You = [&]() {
		Enemy.ShowEnemy(MonsterGH, BackGraound);
		User.displayStatus(WIN_X / 4, WIN_Y - 60);
		Monster.displayStatus(WIN_X / 2 - 30, WIN_Y / 4 - 60);
		Battle.ShowCommand(WIN_X / 2 + WIN_X / 8, WIN_Y * 3 / 4, command_num);
	};
	
	while (flag && ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
	{
		command_num = SelectCommand(command_num);
		if (0 <= command_num && command_num < 4)
		{
			ClearDrawScreen();
			displayEnemy_You();
			ScreenFlip();
		}
		else if (command_num == -1)
		{
			command_num = 0;
			// �搧���ǂ���ɂ��邩: �X�e�[�^�X�𑝂₷
			ClearDrawScreen();
			Monster.setHP(Battle.Attack(User, Monster));
			displayEnemy_You();
			ScreenFlip();
			WaitTimer(1000);
			flag = BreakBattle(User, Monster);

			if (flag)
			{
				ClearDrawScreen();
				User.setHP(Battle.Attack(Monster, User));
				displayEnemy_You();
				ScreenFlip();
				WaitTimer(1000);
				flag = BreakBattle(User, Monster);
			}
		}
	}
	fade_out();
	return User;
}