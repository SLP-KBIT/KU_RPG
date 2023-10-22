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

#include <string>
#include <cstring>

#include "DxLib.h"
#include "Picture.h"
#include "Sub.h"
#include "Title.h"
#include "Stage.h"
#include "Player.h"

// �ǉ�
#include "Status.h"
#include "Enemy.h"
#include "Battle.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);
	DxLib_Init();
    
    SetWindowText("ADVENTURE");
    SetGraphMode(WIN_X, WIN_Y, 32); //�E�B���h�E�̉𑜓x
    SetBackgroundColor(0, 0, 0); //�E�B���h�E�̔w�i�F
    SetDrawScreen(DX_SCREEN_FRONT); //����ʕ`��

    Picture.Load();
    Color.Load();
    Font.Load();
    Stage.Read();

    STATUS user(Title.InputName(), 100, 50, 10, 10);
    STATUS enemy("�X���C��", 20, 5, 5, 5);

    SetDrawScreen(DX_SCREEN_BACK); //����ʕ`��

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
            user = Battle.FightDraw(Picture.Slime, Picture.BackGraound_Forest, user, enemy);
            break;
        };
    }

    DxLib_End();
    return 0;
}