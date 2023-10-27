#pragma once
class SOUND
{
public:
	int B_1[1];

	void Load()
	{
		B_1[0] = LoadSoundMem("./Sound/Music/B_1.mp3");
		ChangeVolumeSoundMem(128, B_1[0]);
	};
private:
};

SOUND Sound;