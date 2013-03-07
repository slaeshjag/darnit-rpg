#include "engine.h"


int object_init() {
	int i, objects, j, x, y, l, dir;
	const char *sprite;

	for (i = objects =  0; i < rpg.map.map->objects; i++)
		if (!strcmp(d_map_prop(rpg.map.map->object[i].ref, "TYPE"), "npc"))
			objects++;
	
	if (!(rpg.object.entry = malloc(sizeof(OBJECT_ENTRY) * objects)) && objects)
		return -1;
	
	rpg.object.bbox = d_bbox_new(objects);

	for (i = j = 0; i < rpg.map.map->objects; i++) {
		if (!strcmp(d_map_prop(rpg.map.map->object[i].ref, "TYPE"), "teleporter")) {
			/* TODO: Implement teleporters */
			continue;
		}

		if (!strcmp(d_map_prop(rpg.map.map->object[i].ref, "TYPE"), "npc")) {
			x = rpg.map.map->object[i].x;
			y = rpg.map.map->object[i].y;
			l = rpg.map.map->object[i].l;
			MAP_COORD_DECODE(x, y, l, &x, &y);
			rpg.object.entry[j].x = x;
			rpg.object.entry[j].y = y;
			rpg.object.entry[j].layer = l;

			sprite = MAP_OBJ_PROP("sprite", i);
			dir = atoi(MAP_OBJ_PROP("sprite_dir", i));
			if (!strcmp(sprite, "NO SUCH KEY"))
				rpg.object.entry[j].sprite = d_sprite_load(sprite, dir, DARNIT_PFORMAT_RGB5A1);
			else
				rpg.object.entry[j].sprite = NULL;
			j++;
		}
	}
			
	rpg.object.entries = objects;

	return 1;
}


int object_destroy() {
	int i;

	/* TODO: There needs to be a loop here to free sprites etc. */
	for (i = 0; i < rpg.object.entries; i++)
		rpg.object.entry[i].sprite = d_sprite_free(rpg.object.entry[i].sprite);

	free(rpg.object.entry);
	rpg.object.entry = NULL;
	rpg.object.entries = 0;
	rpg.object.bbox = d_bbox_free(rpg.object.bbox);

	return 1;
}
