#pragma once
class STATUS
{
public:
    // コンストラクタ：キャラクターのステータスを初期化
    STATUS(int initialHP, int initialMP, int initialATK, int initialDEF) {
        HP = initialHP;
        MP = initialMP;
        ATK = initialATK;
        DEF = initialDEF;
    }

    // ゲッターメソッド：ステータスを取得
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

    // ダメージを受けるメソッド
    void takeDamage(int damage) {
        // 防御力を考慮して実際のダメージを計算
        int actualDamage = damage - DEF;
        if (actualDamage > 0) {
            HP -= actualDamage;
        }
    }

    // キャラクターの情報を表示
    void displayInfo(const char String[256]) {
        DrawFormatStringToHandle(0, 0, Color.GREEN, Font.Meiryo[16], "我が名は %s !", String);
        DrawFormatStringToHandle(0, 20, Color.GREEN, Font.Meiryo[16], "HP:%d  MP:%d", getHP(), getMP());

    }

private:
    int HP;   // 体力
    int MP;   // 魔法ポイント
    int ATK;  // 攻撃力
    int DEF;  // 防御力
};
