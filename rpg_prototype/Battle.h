#pragma once
class BATTLE
{
public:
	void FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster);

	// �U��(MP�g�p����)���\�b�h:�X�̋@�\�ǉ��͂�����p������
	// �Ȃ��ȉ��̓e�X�g�p�̋@�\
	void Attack(STATUS Offense, STATUS Defense)
	{
		int ATK = Offense.getATK();
		int DEF = Defense.getDEF();
		int HP = Defense.getHP();
		Defense.setHP(HP - (ATK - DEF));
	}

	// �R�}���h�̕\��
	// ���ߓ��e�����ꂼ�ꗘ�p���₷���悤�ɂ���
	int ShowCommand(int X, int Y, int command_num)
	{
		// �󔒂��낦
		char order[4][64] = { "��������","�ǂ���","�܂���","�ɂ���" };
		DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[15], "%s\n%s\n%s\n%s", order[0], order[1], order[2], order[3]);
		DrawFormatStringToHandle(X - 20, Y + 17 * (command_num), Color.BLUE, Font.Meiryo[15], "��");
		command_num = this->SelectCommand(command_num);
		return command_num;
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

		int flag = true;
		if (0 >= User.getHP())
		{
			// �����ɔs�k���b�Z�[�W��\������֐�
			flag = false;
		}
		else if (0 >= Monster.getHP())
		{
			// �����ɏ������b�Z�[�W��\������֐�
			flag = false;
		}
		return flag;
	}

private:
};

BATTLE Battle;

// ���̐퓬�̏I�n�𐧌�
void BATTLE::FightDraw(int MonsterGH[], int BackGraound[], STATUS User, STATUS Monster)
{
	int command_num = 0;  // �R�}���h�I���̂��߂̕ϐ�
	bool flag = true;

	while (ScreenFlip() == 0 && ClearDrawScreen && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0 && flag)
	{
		// �G�摜�ƓG/�����̃X�e�[�^�X�\��
		Enemy.ShowEnemy(MonsterGH, BackGraound);
		User.displayStatus(WIN_X / 4, WIN_Y - 60);
		Monster.displayStatus(WIN_X / 2 - 30, WIN_Y / 4 - 60);

		command_num = Battle.ShowCommand(WIN_X / 2 + WIN_X / 8, WIN_Y * 3 / 4, command_num);
		flag = BreakBattle(User, Monster);
	}
}