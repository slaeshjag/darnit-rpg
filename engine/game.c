#include "engine.h"

int game_new() {
	savedata_init();
	map_load(d_stringtable_entry(rpg.conf.conf, "New_game_map"));

	return 1;
}
