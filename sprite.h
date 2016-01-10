#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

enum ANIMATION_TYPES
{ ANIMATION_AUTOMATIC_LOOP=1, ANIMATION_TRIGGERED_SEQ=2};

enum BLOCK_TYPES {
BLOCK_REGULAR,
BLOCK_SOLID,
BLOCK_SLOW,
BLOCK_HOLLOW,
BLOCK_GOLD_COIN,
BLOCK_GOLD_BUCKET,
BLOCK_GOLD_SKULL,
BLOCK_GOLD_BARS,
BLOCK_LADDER,
BLOCK_LADDER_END,
BLOCK_BAR,
BLOCK_TELEPORT_ENTRY,
BLOCK_TELEPORT_EXIT,
BLOCK_KEY_ORANGE,
BLOCK_KEY_GREEN,
BLOCK_KEY_RED,
BLOCK_JACKHAMMER,
BLOCK_PICK,
BLOCK_ROPE,
BLOCK_CAVE,
BLOCK_EXIT_DOOR,
BLOCK_EXIT_DOOR_ORANGE,
BLOCK_EXIT_DOOR_GREEN,
BLOCK_EXIT_DOOR_RED,
BLOCK_BOMB_LARGE,
BLOCK_BOMB_SMALL,
BLOCK_GOO,
BLOCK_GAS,
BLOCK_PLAYER1,
BLOCK_PLAYER2,
BLOCK_MONK,
BLOCK_MONK_RANDOM,
BLOCK_SAVE_BUTTON=33,
BLOCK_LOAD_BUTTON=34,
BLOCK_EMPTY=100,
BLOCK_REGULAR_WITH_GOLD_COIN=(200+BLOCK_REGULAR+BLOCK_GOLD_COIN),
BLOCK_REGULAR_WITH_LADDER=(200+BLOCK_REGULAR+BLOCK_LADDER),
BLOCK_REGULAR_WITH_LADDER_END=(200+BLOCK_REGULAR+BLOCK_LADDER_END),
BLOCK_REGULAR_WITH_BOMB_SMALL=(200+BLOCK_REGULAR+BLOCK_BOMB_SMALL),
BLOCK_TELEPORT_ENTRY1=300,
BLOCK_TELEPORT_ENTRY2=331,
BLOCK_TELEPORT_ENTRY3=302,
BLOCK_TELEPORT_ENTRY4=303,
BLOCK_TELEPORT_ENTRY5=304,
BLOCK_TELEPORT_EXIT1=305,
BLOCK_TELEPORT_EXIT2=306,
BLOCK_TELEPORT_EXIT3=307,
BLOCK_TELEPORT_EXIT4=308,
BLOCK_TELEPORT_EXIT5=309,
};

enum OCCUPANCY_STATES
{ 
IS_NOT_OCCUPIED,
IS_OCCUPIED,
IS_OCCUPIED_TELEPORT,
IS_OCCUPIED_WITH_EMPTY_SECOND_LAYER,
IS_OCCUPIED_FULL
};

enum WORLDS
{
WORLD_JUNGLE,
WORLD_FUNGUS,
WORLD_ANCIENT,
WORLD_CRYSTAL,
WORLD_ICE,
WORLD_FOSSIL,
WORLD_LAVA,
WORLD_PHOSPHORUS,
WORLD_DARK,
WORLD_INDUSTRIAL
};

class SPRITE
{
	public:
		SPRITE(IDirect3DDevice9* d, int nbr_of_frames, int screen_width, int screen_height);
		~SPRITE();
		int loadBitmaps(wchar_t* name);
		int copyBitmaps(IMAGE* image, int frame_nbr);
		int setAnimationType(int a);
		int renderSprite(IDirect3DSurface9* &backbuffer);
		int CopyOntoBlock(IMAGE* image, unsigned int width, unsigned int height);
		void setTransparencyColor(unsigned long color);
		IMAGE* getFrame(void);
		IMAGE* getFrame(unsigned int frameNbr);
		int x_pos;
		int y_pos;
	protected:
		IMAGE* frames;
		int nbrOfFrames;
		IDirect3DDevice9* d3ddev;
		int frameState;
		int screenWidth;
		int screenHeight;
		int animationType;
		unsigned long transparencyColor;
};



#endif