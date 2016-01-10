#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "player.h"
#include "digger.h"
#include "sound.h"

enum SOUND_EFFECT
{ SOUND_BEGIN_LEVEL, SOUND_FALLING, SOUND_LANDING, SOUND_DIGGER };

class GAMEPLAY
{
	public:
		GAMEPLAY(IDirect3DDevice9* d, IXAudio2* xa, PLATFORM* p, HWND &hWnd, int screen_width, int screen_height);
		~GAMEPLAY(void);
		void Render(IDirect3DSurface9* &buf);
		void MovePlayer1Right(void);
		void MovePlayer1Left(void);
		void MovePlayer1Up(void);
		void MovePlayer1Down(void);
		void DigRightPlayer1(void);
		void DigLeftPlayer1(void);
		int LoadLevel(unsigned int levelNbr);
		int LoadLevel(void);
		void Exit(void);
		void Gravity(void);
		void Sounds(void);
		wchar_t* GetMusicFileName(void);
		void Player1EntersLevel(void);

	private:
		IDirect3DDevice9* d3ddev;
		PLATFORM* platform;
		PLAYER** player;
		DIGGER* digger;
		SPRITE** monk;
		wchar_t** musicFileName;
		wchar_t** soundFileName;
		unsigned int gold;
		bool isFalling;
		bool isEnteringLevel;
		bool isEnteringLevelSound;
		bool isDiggingRight;
		bool isDiggingLeft;
		//SOUND* fallingSound;
		//SOUND* landingSound;
		SOUND** soundEffect;
};

#endif