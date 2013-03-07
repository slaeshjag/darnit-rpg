#include "engine.h"



int rpg_init() {
	DARNIT_PLATFORM platform;
	
	platform = d_platform_get();
	if (!(rpg.conf.conf = d_stringtable_open("meta/system.stz")))
		return 0;
	d_stringtable_section_load(rpg.conf.conf, "CONFIG");
	if (d_init_rest(CONFIG("Title"), platform.screen_w, platform.screen_h, platform.fullscreen, d_str_null(CONFIG( "Icon"))))
		return 0;
	if (!map_init())
		return 0;
	
	object_prepare();

	rpg.state.state = RPG_STATE_DUMMY;
	state_set(RPG_STATE_NEW_GAME);

	return 1;
}


int main(int argc, char **argv) {

	d_init_partial(argv[0]);
	d_fs_mount_self();
	if (!rpg_init()) {
		fprintf(stderr, "Init failed\n");
		d_quit();
	}

	for (;;) {
		state();

		d_render_blend_enable();
		d_render_begin();

		render();

		d_render_end();
		d_loop();
	}
	
	d_quit();
	
	return 0;
}
