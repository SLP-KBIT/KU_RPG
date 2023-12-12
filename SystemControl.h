#pragma once
class SystemControl
{
public:
	SystemControl();
	~SystemControl();
private:
	void MainLoop();
	void Window_Init();
};

SystemControl::SystemControl()
{
	DxLib_Init();
	Window_Init();

	MainLoop();
}

SystemControl::~SystemControl()
{
	DxLib_End();
}

void SystemControl::MainLoop()
{
	while (!ProcessMessage() && !isPress(KEY_INPUT_ESCAPE))
	{
		GetKey();

		ClearDrawScreen();

		DrawBox(10, 10, 20, 20, color->white, true);

		ScreenFlip();
	}
}

void SystemControl::Window_Init()
{
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("KURPG");
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
}