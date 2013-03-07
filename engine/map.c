#include "engine.h"


int map_init() {
	rpg.map.map = NULL;
	rpg.map.next_map = NULL;

	return 1;
}


int map_load(const char *path) {
	rpg.map.map = d_map_unload(rpg.map.map);
	rpg.map.next_map = NULL;
	rpg.state.countdown = -1;

	object_destroy();

	if (!strcmp(path, "MAIN_MENU")) {
		state_set(RPG_STATE_MAIN_MENU);
		path = d_stringtable_entry(rpg.conf.conf, "Main_menu");
	}

	rpg.map.map = d_map_load(path);
	if (!rpg.map.map)
		return 0;
	if (strcmp("Next_map", d_map_prop(rpg.map.map->prop, "Next_map")))
		rpg.map.next_map = d_map_prop(rpg.map.map->prop, "Next_map");
	if (strcmp("Next_delay", d_map_prop(rpg.map.map->prop, "Next_delay")))
		rpg.state.countdown = atoi(d_map_prop(rpg.map.map->prop, "Next_delay"));
	object_init();
	
	return 1;
}


int map_render(int layer) {
	if (layer >= rpg.map.map->layers)
		return 0;
	d_tilemap_draw(rpg.map.map->layer[layer].tilemap);

	return 1;
}
