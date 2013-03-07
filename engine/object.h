#ifndef __OBJECT_H__
#define	__OBJECT_H__

typedef enum {
	OBJECT_INIT,
	OBJECT_UPDATE,
	OBJECT_CONTINUE,
	OBJECT_DATA_READ,
	OBJECT_DATA_WRITE,
	OBJECT_DESTROY
} OBJECT_MESSAGE;


typedef struct {
	/* TODO: Handler goes here */

	int		x;
	int		y;
	int		layer;
	DARNIT_SPRITE	*sprite;
} OBJECT_ENTRY;


typedef struct {
	OBJECT_ENTRY	*entry;
	int		entries;
	DARNIT_BBOX	*bbox;
} OBJECT;


int object_init();
int object_destroy();


#endif
