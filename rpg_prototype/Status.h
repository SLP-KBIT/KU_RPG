#pragma once
class STATUS
{
public:
    // �R���X�g���N�^�F�L�����N�^�[�̃X�e�[�^�X��������
    STATUS(const char* initialNAME, int initialHP, int initialMP, int initialATK, int initialDEF) {
        strncpy_s(NAME, sizeof(NAME), initialNAME, _TRUNCATE);
        NAME[sizeof(NAME) - 1] = '\0'; // �O�̂��߃k���I�[������ݒ�
        HP = initialHP;
        MP = initialMP;
        ATK = initialATK;
        DEF = initialDEF;
    }

    // �Q�b�^�[���\�b�h�F�X�e�[�^�X���擾
    const char* getNAME() {
        return NAME;
    }

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


    // �L�����N�^�[�̏���\��(�e�X�g�p)
    void displayInfo() {
        DrawFormatStringToHandle(0, 0, Color.GREEN, Font.Meiryo[16], "�䂪���� %s !", getNAME());
        DrawFormatStringToHandle(0, 20, Color.GREEN, Font.Meiryo[16], "HP:%d  MP:%d", getHP(), getMP());
    }

    // �X�e�[�^�X����\������
    // X,Y�͍��W
    void displayStatus(int X, int Y)
    {
        DrawFormatStringToHandle(X, Y, Color.RED, Font.Meiryo[16], "%s\nHP:%d\nMP:%d", getNAME(), getHP(), getMP());
    }

    // 
    void encountEnemy() {
        ;
    }

private:
    char NAME[64];   // �L������G�̖��O
    int HP;   // �̗�
    int MP;   // ���@�|�C���g
    int ATK;  // �U����
    int DEF;  // �h���
};