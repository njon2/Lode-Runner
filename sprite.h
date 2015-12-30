#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

#define ANIMATION_AUTOMATIC_LOOP	1
#define ANIMATION_TRIGGERED_SEQ		2
#define BLOCK_REGULAR		0
#define BLOCK_SOLID			1
#define BLOCK_SLOW			2
#define BLOCK_HOLLOW		3
#define BLOCK_GOLD_COIN		4
#define BLOCK_GOLD_BUCKET	5
#define BLOCK_GOLD_SKULL	6
#define BLOCK_GOLD_BARS		7
#define BLOCK_LADDER		8
#define BLOCK_LADDER_END	9
#define BLOCK_BAR			10
#define BLOCK_TELEPORT_ENTRY		11
#define BLOCK_TELEPORT_EXIT			12
#define BLOCK_KEY_ORANGE			13
#define BLOCK_KEY_GREEN				14
#define BLOCK_KEY_RED				15
#define BLOCK_JACKHAMMER			16
#define BLOCK_PICK					17
#define BLOCK_ROPE					18
#define BLOCK_CAVE					19
#define BLOCK_EXIT_DOOR				20
#define BLOCK_EXIT_DOOR_ORANGE		21
#define BLOCK_EXIT_DOOR_GREEN		22
#define BLOCK_EXIT_DOOR_RED			23
#define BLOCK_BOMB_LARGE			24
#define BLOCK_BOMB_SMALL			25
#define BLOCK_GOO					26
#define BLOCK_GAS					27
#define BLOCK_PLAYER1				28
#define BLOCK_PLAYER2				29
#define BLOCK_MONK					30
#define BLOCK_MONK_RANDOM			31
#define BLOCK_EMPTY					100
#define BLOCK_REGULAR_WITH_GOLD_COIN	(200+BLOCK_REGULAR+BLOCK_GOLD_COIN)
#define BLOCK_REGULAR_WITH_LADDER		(200+BLOCK_REGULAR+BLOCK_LADDER)
#define BLOCK_REGULAR_WITH_LADDER_END	(200+BLOCK_REGULAR+BLOCK_LADDER_END)
#define BLOCK_REGULAR_WITH_BOMB_SMALL	(200+BLOCK_REGULAR+BLOCK_BOMB_SMALL)
#define IS_NOT_OCCUPIED					0
#define IS_OCCUPIED						1
#define IS_OCCUPIED_WITH_EMPTY_SECOND_LAYER	3
#define IS_OCCUPIED_FULL				4

class SPRITE
{
	public:
		SPRITE(IDirect3DDevice9* d, int nbr_of_frames, int screen_width, int screen_height);
		~SPRITE();
		int loadBitmaps(wchar_t* name);
		int copyBitmaps(IMAGE* image, int frame_nbr);
		int setAnimationType(int a);
		int renderSprite(IDirect3DSurface9* &backbuffer);
		int CopyOntoBlock(IMAGE* image);
		void nextFrame(void);
		void setTransparencyColor(unsigned long color);
		IMAGE* getFrame(void);
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

class PLATFORM
{
	public:
		PLATFORM(IDirect3DDevice9* d, int screen_width, int screen_height);
		~PLATFORM();
		int initialize(unsigned int nbr_of_blocks, unsigned int nbr_of_types);
		int addPlatform(unsigned int blockNbr, unsigned int _type);
		void deinitialize(void);
		int loadBlocks(wchar_t* name);
		void setBlock(unsigned int blockNbr);
		void renderPlatform(IDirect3DSurface9* &buf);
		void GetBlockCoordinates(unsigned int blockNbr, int &x, int &y);
		unsigned int getBlockNbr(int x, int y);
		unsigned char getIsOccupied(unsigned int blockNbr);
		bool getIsSelected(unsigned int blockNbr);
		unsigned int getSelectedTypeNbr(void);
		IMAGE* getImage(int type);
	private:
		SPRITE** blocks;
		SPRITE* temp_sprite;
		IMAGE* sheet;			// this holds the sprite sheet
		SPRITE** menu;
		unsigned char* isOccupied;
		bool* isSelected;
		unsigned int* type;		// hold the type ID of each block
		unsigned int nbrOfBlocks;
		unsigned int nbrOfTypes;
		int screenWidth;
		int screenHeight;
		IDirect3DDevice9* d3ddev;

};

class CURSOR
{
	public:
		CURSOR(IDirect3DDevice9* &d, unsigned int type_nbr, int screen_width, int screen_height);
		CURSOR(IDirect3DDevice9* &d, int screen_width, int screen_height);
		~CURSOR();
		int SetType(unsigned int type_nbr);
		unsigned int GetType(void);
		void Render(IDirect3DSurface9* &backbuffer);
		void SetSelectionX_Pos(int x);
		void SetSelectionY_Pos(int y);
		void MoveCursorX(int qty);
		void MoveCursorY(int qty);
		int GetBlockCursor(void);
		int SetBlockCursor(int c);
		int SetButtonCursor(int c);
		POINT GetCursorPosition(void);
	private:
		int blockCursor;
		SPRITE* cursorGraphic;
		SPRITE* selectionGraphic;
		unsigned int typeNbr;			// ID for the image to be displayed as cursor from PLATFORM sheet
		int screenWidth;
		int screenHeight;
		bool displaySelectionGraphic;
};

#endif