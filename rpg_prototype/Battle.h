#pragma once
class BATTLE
{
public:
	void EnemyDraw(int Enemy[])
	{
		;//SetDrawScreen(DX_SCREEN_BACK);
	}

	// �U��(MP�g�p����)���\�b�h:�X�̋@�\�ǉ��͂�����p������
	// �Ȃ��ȉ��̓e�X�g�p�̋@�\
	void Attack(STATUS Offense, STATUS Defense)
	{
		int ATK = Offense.getATK();
		int DEF = Defense.getDEF();
		int HP = Defense.getHP();
		Defense.setHP(HP - (ATK - DEF));

	}

	// �R�}���h�̕\��(���������W�Ȃ̂̓e�X�g������)
	// ���ߓ��e�����ꂼ�ꗘ�p���₷���悤�ɂ���
	void ShowCommand(int X, int Y)
	{
		// �󔒂��낦
		char order1[64] = "��������";
		char order2[64] = "  �ǂ���";
		char order3[64] = "  �܂���";
		char order4[64] = "  �ɂ���";
		DrawFormatStringToHandle(X, Y, Color.BLUE, Font.Meiryo[16], " %s  %s\n %s  %s", order1, order2, order3, order4);
	}

	// 


	// �_���[�W���󂯂郁�\�b�h
//	void takeDamage(int damage) {
//		// �h��͂��l�����Ď��ۂ̃_���[�W���v�Z
//		int actualDamage = damage - DEF;
//		if (actualDamage > 0) {
//			HP -= actualDamage;
//		}
//	}

private:
};

BATTLE Battle;