#include "Dxlib.h"
#include "Define.h"
#include "SystemManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SystemManager* kurpg = new SystemManager;
    delete kurpg;
    return 0;
}