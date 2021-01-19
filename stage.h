#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y);
extern void blitEntity(SDL_Texture *texture, int x, int y, int movementStatus, int direction);
extern SDL_Texture *loadTexture(char *filename);

extern App app;
