#pragma once
class STATUS
{
public:
    // �R���X�g���N�^�F�L�����N�^�[�̃X�e�[�^�X��������
    STATUS(int initialHP, int initialMP, int initialATK, int initialDEF) {
        HP = initialHP;
        MP = initialMP;
        ATK = initialATK;
        DEF = initialDEF;
    }

    // �Q�b�^�[���\�b�h�F�X�e�[�^�X���擾
    int getHP() const {
        return HP;
    }

    int getMP() const {
        return MP;
    }

    int getATK() const {
        return ATK;
    }

    int getDEF() const {
        return DEF;
    }

    // �Z�b�^�[���\�b�h�F�X�e�[�^�X��ύX
    void setHP(int newHP) {
        HP = newHP;
    }

    void setMP(int newMP) {
        MP = newMP;
    }

    void setATK(int newATK) {
        ATK = newATK;
    }

    void setDEF(int newDEF) {
        DEF = newDEF;
    }

    // �_���[�W���󂯂郁�\�b�h
    void takeDamage(int damage) {
        // �h��͂��l�����Ď��ۂ̃_���[�W���v�Z
        int actualDamage = damage - DEF;
        if (actualDamage > 0) {
            HP -= actualDamage;
        }
    }

    // �L�����N�^�[�̏���\��
    void displayInfo(const char String[256]) {
        DrawFormatStringToHandle(0, 0, Color.GREEN, Font.Meiryo[16], "�䂪���� %s !", String);
        DrawFormatStringToHandle(0, 20, Color.GREEN, Font.Meiryo[16], "HP:%d  MP:%d", getHP(), getMP());

    }

private:
    int HP;   // �̗�
    int MP;   // ���@�|�C���g
    int ATK;  // �U����
    int DEF;  // �h���
};
