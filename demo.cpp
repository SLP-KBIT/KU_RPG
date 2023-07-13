#include <iostream>
#include <string>
using namespace std;

int map[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

class Object
{
    public:
    string name;
    int hp;
    int mp;
    int atk;
    int def;
    int x;
    int y;
    int z;
    Object(string n, int h, int a)
    {
        name = n;
        hp = h;
        atk = a;
        x = 0;
        y = 0;
        z = 0;
    }
    void status()
    {
        cout << name << "'s STATUS" << endl;
        cout << "NAME : " << name << endl;
        cout << "HP   : " << hp << endl;
        cout << "ATK  : " << atk << endl;
    }
    int attack()
    {
        return this->atk;
    }
    void damage(int hit)
    {
        this->hp -= hit;
    }
    bool death()
    {
        if(this->hp > 0)
            return false;
        else
            return true;
    }
    void encount(Object* enemy)
    {
        while(!this->death())
        {
            int hit = this->attack();
            enemy->damage(hit);
            if(enemy->death())
            {
                break;
            }
            enemy->status();
            
            hit = enemy->attack();
            this->damage(hit);
            if(this->death())
            {
                cout << "GAME OVER" << endl;
            }
            this->status();
        }
    }
};

int main(void)
{
    Object p("bob", 400, 50);
    p.status();
    return 0;
}