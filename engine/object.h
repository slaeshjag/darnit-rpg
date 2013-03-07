#ifndef __OBJECT_H__
#define	__OBJECT_H__

typedef enum {
	OBJECT_MSG_INIT,
	OBJECT_MSG_UPDATE,
	OBJECT_MSG_DONE,
	OBJECT_MSG_DATA_READ,
	OBJECT_MSG_DATA_WRITE,
	OBJECT_MSG_MESSAGE,
	OBJECT_MSG_POS_UPDATE,
	OBJECT_MSG_DESTROY,
} OBJECT_MESSAGE;


typedef struct {
	void		*pointer;
	int		num;
} OBJECT_MSG_DATA;


typedef struct {
	/* TODO: Handler goes here */
	OBJECT_MESSAGE	(*handler)(OBJECT_MESSAGE msg, void *self);

	int		x;
	int		y;
	int		layer;
	DARNIT_SPRITE	*sprite;
	OBJECT_MSG_DATA	data;
} OBJECT_ENTRY;


typedef struct {
	OBJECT_ENTRY	*entry;
	int		entries;
	DARNIT_BBOX	*bbox;
	DARNIT_DYNLIB	*main_lib;
	DARNIT_DYNLIB	*aux_lib;
} OBJECT;


int object_init();
int object_destroy();
int object_prepare();


#endif
