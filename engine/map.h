#ifndef __MAP_H__
#define	__MAP_H__

#define	MAP_COORD_DECODE(t_x, t_y, l, x, y)	\
	d_tilemap_iso_to_screen(rpg.map.map->layer[(l)].tilemap, (t_x), (t_y), \
	(x), (y))
#define	MAP_OBJ_PROP(x, i)	d_map_prop(rpg.map.map->object[(i)].ref, (x))

typedef struct {
	DARNIT_MAP		*map;
	const char		*next_map;
} RPG_MAP;

int map_init();
int map_load(const char *path);
int map_render(int layer);

#endif
