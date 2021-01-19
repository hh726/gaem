#include "stage.h"

static void logic(void);
static void draw(void);
static void initPlayer(void);
static void doPlayer(void);
static void drawPlayer(void);

static Entity *player;

void initStage(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	
	initPlayer();
}

static void initPlayer()
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));

	
	player->x = 200;
	player->y = 200;
	player->texture = loadTexture("gfx/player.png");
	player->movementStatus = 0;
}

static void logic(void)
{
	doPlayer();
}

static void doPlayer(void)
{
	player->dx = player->dy = 0;
	
	if (app.keyboard[SDL_SCANCODE_UP])
	{
		player->dy = -PLAYER_SPEED;
		player->direction = UP;
		player->movementStatus = 1;
	} 
	
	else if (app.keyboard[SDL_SCANCODE_DOWN])
	{
		player->dy = PLAYER_SPEED;
		player->direction = DOWN;
		player->movementStatus = 1;
	}
	
	else if (app.keyboard[SDL_SCANCODE_LEFT])
	{
		player->dx = -PLAYER_SPEED;
		player->direction = LEFT;
		player->movementStatus = 1;
	}
	
	else if (app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player->dx = PLAYER_SPEED;
		player->direction = RIGHT;
		player->movementStatus = 1;
	}
	else 
	{
		player->movementStatus = 0;
	}
	player->x += player->dx;
	player->y += player->dy;
}

static void draw(void)
{
	drawPlayer();
}

static void drawPlayer(void)
{
	blitEntity(player->texture, player->x, player->y, player->movementStatus, player->direction);
}

