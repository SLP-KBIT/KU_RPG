enum COURCE
{
    START,
    WORLD,
    FIGHT,
};
int Scene = COURCE::START;

#define WIN_X 480
#define WIN_Y 480
#define STAGE_MAX_X 38
#define STAGE_MAX_Y 48
#define CELL 16

#include "DxLib.h"
#include "Picture.h"
#include "Sub.h"
#include "Title.h"
#include "Stage.h"
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
    
    SetWindowText("ADVENTURE");
    SetGraphMode(WIN_X, WIN_Y, 32); //ウィンドウの解像度
    SetBackgroundColor(0, 0, 0); //ウィンドウの背景色
    SetDrawScreen(DX_SCREEN_BACK); //裏画面描画

    Picture.Load();
    Color.Load();
    Font.Load();
    Stage.Read();

    while (ScreenFlip() == 0 && ClearDrawScreen && ProcessMessage() == 0 && GetKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
    {
        switch (Scene)
        {
        case COURCE::START:
            Title.Draw();
            break;
        case COURCE::WORLD:
            PlayerDraw.RealScreenDraw();
            break;
        };
    }

    DxLib_End();
    return 0;
}