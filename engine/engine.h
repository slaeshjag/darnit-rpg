#ifndef __ENGINE_H__
#define	__ENGINE_H__

#include <darnit/darnit.h>

#include <string.h>

#include "render.h"
#include "map.h"
#include "state.h"
#include "game.h"
#include "savedata.h"
#include "object.h"

#define	CONFIG(x)			d_stringtable_entry(rpg.conf.conf, (x))

typedef struct {
	DARNIT_STRINGTABLE		*conf;
} RPG_CONF;


typedef struct {
	RPG_CONF			conf;
	RPG_STATE			state;
	RPG_MAP				map;
	OBJECT				object;
	SAVEDATA			savedata;
} RPG;


RPG rpg;



#endif
