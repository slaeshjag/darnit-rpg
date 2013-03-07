#include "engine.h"


int render_everything_map() {
	int i;

	if (!rpg.map.map)
		return 0;
	for (i = 0; i < rpg.map.map->layers; i++)
		d_tilemap_draw(rpg.map.map->layer[i].tilemap);
	
	return 1;
}


int render_splash() {
	return 1;
}

int render_main_menu() {
	fprintf(stderr, "Main menu\n");
	return 1;
}


int render_overworld() {
	render_everything_map();
	
	return 1;
}


int render_inventory() {
	return 1;
}


int render_map() {
	return 1;
}


int render() {
	switch (rpg.state.state) {
		case RPG_STATE_SPLASH:
			render_splash();
			break;
		case RPG_STATE_MAIN_MENU:
			render_main_menu();
			break;
		case RPG_STATE_OVERWORLD:
			render_overworld();
			break;
		case RPG_STATE_INVENTORY:
			render_inventory();
			break;
		case RPG_STATE_MAP:
			render_map();
			break;
	}

	return 1;
}
