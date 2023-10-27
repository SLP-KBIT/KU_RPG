enum COURCE
{
    START,
    WORLD,
    FIGHT,
};
int Scene = COURCE::START;

#define WIN_X 480
#define WIN_Y 480
#define STAGE_MAX_X 17
#define STAGE_MAX_Y 49
#define FIXED_X 15
#define FIXED_Y 15
#define CELL 16
#define WARP_NUM 3
#define ITEM_MAX_NUM 7
#define ENEMY_MAX_NUM 8

#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <tuple>
#include <random>

using namespace std;
map <int, string> item_dict;
map <string, string> item_used_message;
int inventory[ITEM_MAX_NUM] = {};
int item_num = 0;

#include "DxLib.h"
#include "Picture.h"
#include "Sound.h"
#include "Sub.h"
#include "Title.h"
#include "Status.h"
#include "Object.h"
#include "Item.h"
#include "Enemy.h"
#include "Stage.h"
#include "Player.h"

// 追加
#include "Battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    for (int i = 0; i < ITEM_MAX_NUM; i++)
    {
        item_dict[i] = "";
        inventory[i] = i;
        item_used_message[item_dict[i]] = "";
    }

	ChangeWindowMode(TRUE);
	DxLib_Init();
    
    SetWindowText("KU RPG");
    SetGraphMode(WIN_X, WIN_Y, 32); //ウィンドウの解像度
    SetBackgroundColor(0, 0, 0); //ウィンドウの背景色
    SetDrawScreen(DX_SCREEN_BACK); //裏画面描画

    enemy[0] = new STATUS("VR_DANCERS", 20, 5, 5, 5, 5, 20);
    enemy[1] = new STATUS("夢四国カンパニー", 50, 20, 8, 8, 8, 25);
    enemy[2] = new STATUS("ミスター・ミスター", 20, 5, 5, 5, 5, 100);
    enemy[3] = new STATUS("SQL Injector", 20, 5, 5, 5, 5, 100);
    enemy[4] = new STATUS("R4-P17", 20, 5, 5, 5, 5, 100);
    enemy[5] = new STATUS("電王", 20, 5, 5, 5, 5, 100);
    enemy[6] = new STATUS("Sキュア愛", 20, 5, 5, 5, 5, 100);
    enemy[7] = new STATUS("Unchain", 20, 5, 5, 5, 5, 100);

    Picture.Load();
    Color.Load();
    Font.Load();
    Stage.Read();
    Sound.Load();

    while (ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
    {
        switch (Scene)
        {
        case COURCE::START:
            Title.Draw();
            break;
        case COURCE::WORLD:
            PlayerDraw.RealScreenDraw();
            user.displayInfo();
            break;
        case COURCE::FIGHT:
            for (int i = 0; i < ENEMY_MAX_NUM; i++)
            {
                if (Stage.floor < 7)
                {
                    if (i != Stage.floor - 3)
                    {
                        continue;
                    }
                    user = Battle.FightDraw(Picture.Enemy[i][1], Picture.BackGraound[0], user, *enemy[i]);
                }
                else
                {
                    if (i != Stage.floor - 4)
                    {
                        continue;
                    }
                    user = Battle.FightDraw(Picture.Enemy[i][1], Picture.BackGraound[0], user, *enemy[i]);
                }
            }
            break;
        };
    }

    DxLib_End();
    return 0;
}