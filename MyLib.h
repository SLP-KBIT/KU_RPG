#pragma once
#define WINDOW_X 480
#define WINDOW_Y 480
#define JUST_NUM 256

struct ColorData
{
    int red = GetColor(255, 0, 0);
    int green = GetColor(0, 255, 0);
    int blue = GetColor(0, 0, 255);
    int black = GetColor(0, 0, 0);
    int white = GetColor(255, 255, 255);
};

struct ColorData* color = new struct ColorData;

int key[JUST_NUM] = { 0 };
char charKey[JUST_NUM] = { 0 };
bool pressFlag[JUST_NUM] = { 0 };

void GetKey()
{
    GetHitKeyStateAll(charKey);
    for (int i = 0; i < JUST_NUM; i++)
        if (charKey[i] != 0) key[i]++;
        else key[i] = 0;
}

bool isPress(int keyIndex)
{
    if (key[keyIndex] && !pressFlag[keyIndex])
    {
        pressFlag[keyIndex] = true;
        return true;
    }
    if (!key[keyIndex]) pressFlag[keyIndex] = false;
    return false;
}