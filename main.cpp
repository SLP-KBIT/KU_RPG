#include "Dxlib.h"
#include "MyLib.h"
#include "SystemControl.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SystemControl* sc = new SystemControl;
    delete sc;
    return 0;
}