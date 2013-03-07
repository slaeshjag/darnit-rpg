#include "engine.h"


void state_constructor() {
	switch (rpg.state.state) {
		case RPG_STATE_NEW_GAME:
			game_new();
			break;
		default:
			break;
	}

	return;
}


void state_destructor() {
	return;
}


void state() {

	switch (rpg.state.state) {
		case RPG_STATE_MAIN_MENU:
			state_set(RPG_STATE_NEW_GAME);
			break;
		case RPG_STATE_NEW_GAME:
			state_set(RPG_STATE_OVERWORLD);
			break;
		case RPG_STATE_OVERWORLD:
			break;
		default:
			fprintf(stderr, "Blurgh... %i\n", rpg.state.state);
	}
	
	if (d_render_fade_status() == 2 && rpg.state.state != rpg.state.newstate) {
		d_render_fade_out(atoi(d_stringtable_entry(rpg.conf.conf, "Fade_time")));
		state_destructor();
		rpg.state.state = rpg.state.newstate;
		state_constructor();
	}

	return;
}



void state_set(RPG_STATE_NUM state) {
	if (rpg.state.newstate == state)
		return;
	if (rpg.state.state != RPG_STATE_DUMMY)
		d_render_fade_in(atoi(d_stringtable_entry(rpg.conf.conf, "Fade_time")), 0, 0, 0);
	else
		d_render_fade_in(1, 0, 0, 0);
	rpg.state.newstate = state;
	rpg.state.state_timer = 0;
	rpg.state.countdown = -1;

	return;
}

