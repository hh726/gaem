#include "draw.h"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 32, 32, 32, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;
	
	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void blitEntity(SDL_Texture *texture, int x, int y, int movementStatus, int direction)
{
	SDL_Rect src;
	SDL_Rect dest;
	// if (movementStatus && direction == 1) {
	// 	src.x = 0;
	// 	src.y = 192;
	// } else {
	// 	src.x = 64;
	// 	src.y = 0;
	// }
	src.x = 0;
	switch (direction) 
	{
		case 1: //up
			src.y = 3 * ENTITY_SIZE_PIXELS;
			break;
		case 2: //down
			src.y = 0 * ENTITY_SIZE_PIXELS;
			break;
		case 3: //left
			src.y = 1 * ENTITY_SIZE_PIXELS;
			break;
		case 4: //right
			src.y = 2 * ENTITY_SIZE_PIXELS;
	}

	switch (movementStatus)
	{
		case 0:
			src.x = 1 * ENTITY_SIZE_PIXELS;
			break;
		case 1:
			src.x = ENTITY_SIZE_PIXELS * 2 * (int) ((SDL_GetTicks() / 100) % 2);
			break;
	}
	
	dest.x = x;
	dest.y = y;
	dest.w = ENTITY_SIZE_PIXELS;
	dest.h = ENTITY_SIZE_PIXELS;



	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	src.w /= 3;
	src.h /= 4;

	SDL_RenderCopy(app.renderer, texture, &src, &dest);
}
