#include <Dxlib.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    DxLib_Init();
    ChangeWindowMode(true);
    SetDrawScreen(DX_SCREEN_BACK);

    while (!ProcessMessage())
    {
        ClearDrawScreen();

        DrawBox(10, 10, 20, 20, GetColor(255, 255, 255), true);

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}