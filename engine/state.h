#ifndef __STATE_H__
#define	__STATE_H__

typedef enum {
	RPG_STATE_DUMMY,
	RPG_STATE_SPLASH,
	RPG_STATE_MAIN_MENU,
	RPG_STATE_NEW_GAME,
	RPG_STATE_OVERWORLD,
	RPG_STATE_INVENTORY,
	RPG_STATE_MAP
} RPG_STATE_NUM;


typedef struct {
	RPG_STATE_NUM			state;
	RPG_STATE_NUM			newstate;
	unsigned int			state_timer;
	int				countdown;
} RPG_STATE;

void state();
void state_set(RPG_STATE_NUM state);

void state_constructor();
void state_destructor();

#endif
