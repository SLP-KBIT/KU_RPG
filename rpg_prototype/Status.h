#pragma once
class STATUS
{
public:
    // コンストラクタ：キャラクターのステータスを初期化
    STATUS(const char* initialNAME, int initialHP, int initialMP, int initialATK, int initialDEF) {
        strncpy_s(NAME, sizeof(NAME), initialNAME, _TRUNCATE);
        NAME[sizeof(NAME) - 1] = '\0'; // 念のためヌル終端文字を設定
        HP = initialHP;
        MP = initialMP;
        ATK = initialATK;
        DEF = initialDEF;
    }

    // ゲッターメソッド：ステータスを取得
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

    // セッターメソッド：ステータスを変更
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


    // キャラクターの情報を表示(テスト用)
    void displayInfo() {
        DrawFormatStringToHandle(0, 0, Color.GREEN, Font.Meiryo[16], "我が名は %s !", getNAME());
        DrawFormatStringToHandle(0, 20, Color.GREEN, Font.Meiryo[16], "HP:%d  MP:%d", getHP(), getMP());
    }

    // ステータス情報を表示する
    // X,Yは座標
    void displayStatus(int X, int Y)
    {
        DrawFormatStringToHandle(X, Y, Color.RED, Font.Meiryo[16], "%s\nHP:%d\nMP:%d", getNAME(), getHP(), getMP());
    }

    // 
    void encountEnemy() {
        ;
    }

private:
    char NAME[64];   // キャラや敵の名前
    int HP;   // 体力
    int MP;   // 魔法ポイント
    int ATK;  // 攻撃力
    int DEF;  // 防御力
};