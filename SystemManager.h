#pragma once
class SystemManager
{
public:
	SystemManager();
	~SystemManager();
private:
	void Window_Init();
	void exe();
};

SystemManager::SystemManager()
{
	DxLib_Init();
	Window_Init();

	exe();
}

SystemManager::~SystemManager()
{
	DxLib_End();
}

void SystemManager::Window_Init()
{
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("KURPG");
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
}

void SystemManager::exe()
{
	while (!ProcessMessage() && !isPress(KEY_INPUT_ESCAPE))
	{
		GetKey();
		ClearDrawScreen();

		switch (GameScene)
		{
			case SCENE::TITLE: break;
			case SCENE::WORLD: break;
			case SCENE::FIGHT: break;
		}

		ScreenFlip();
	}
}