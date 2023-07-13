#include <iostream>
#include <string>
#define SIZE 6
using namespace std;

class Object
{
    public:
    int x;
    int y;
    int z;
    Object()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

class System
{
    public:
    bool gamefin;
    Object p;
    System()
    {
        gamefin = false;
        game();
    }
    void game(void)
    {
        while(!gamefin)
        {
            string cmd;
            printmap();
            printcmd();
            cout << "command : ";
            cin >> cmd;
            readcmd(cmd);
        }
    }
    void printmap()
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(i == p.y && j == p.x)
                {
                    cout << "p";
                }
                else
                {
                    cout << "#";
                }
            }
            cout << endl;
        }
    }
    void printcmd(void)
    {
        cout << "↑:w / ←:a / ↓:s / →:d / MENU:e / QUIT:q" << endl;
    }
    void readcmd(string cmd)
    {
        if(!cmd.compare("w"))
        {
            p.move(0, -1);
        }
        else if(!cmd.compare("a"))
        {
            p.move(-1, 0);
        }
        else if(!cmd.compare("s"))
        {
            p.move(0, 1);
        }
        else if(!cmd.compare("d"))
        {
            p.move(1, 0);
        }
        else if(!cmd.compare("q"))
        {
            this->gamefin = true;
        }
        else
        {
            cout << "error" << endl;
        }
    }
};

int main(void)
{
    System launch;
    return 0;
}