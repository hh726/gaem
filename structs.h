typedef struct Entity Entity;

typedef struct {
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
} App;

struct Entity {
	float x;
	float y;
	float dx;
	float dy;
	int movementStatus; // 1 = moveing, 0 = still
	short int direction;
	int health;
	SDL_Texture *texture;
};
