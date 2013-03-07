#ifndef __SAVEDATA_H__
#define	__SAVEDATA_H__

typedef struct {
	int			num[4];
} SAVEDATA_ENTRY_FULL;


typedef struct {
	unsigned int		bool;
} SAVEDATA_ENTRY_FLAG;


typedef struct {
	char			data[16];
} SAVEDATA_ENTRY_CHAR;


typedef struct {
	SAVEDATA_ENTRY_FULL	*entry;
	SAVEDATA_ENTRY_FLAG	*bool_entry;
	SAVEDATA_ENTRY_CHAR	*char_entry;
} SAVEDATA_BANK;


typedef struct {
	SAVEDATA_BANK		*bank;
	unsigned int		banks;
	unsigned int		bank_size;
} SAVEDATA;


int savedata_init();

#endif
