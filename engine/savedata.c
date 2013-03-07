#include "engine.h"


SAVEDATA_BANK savedata_bank_new(int banksize) {
	SAVEDATA_BANK bank;

	bank.entry = malloc(sizeof(SAVEDATA_ENTRY_FULL) * banksize);
	bank.bool_entry = malloc(sizeof(SAVEDATA_ENTRY_FLAG) * banksize);
	bank.char_entry = malloc(sizeof(SAVEDATA_ENTRY_CHAR) * banksize);

	memset(bank.char_entry, 0, sizeof(SAVEDATA_ENTRY_FULL) * banksize);
	memset(bank.char_entry, 0, sizeof(SAVEDATA_ENTRY_FLAG) * banksize);
	memset(bank.char_entry, 0, sizeof(SAVEDATA_ENTRY_CHAR) * banksize);

	return bank;
}


int savedata_init() {
	int i, banks, banksize;

	rpg.savedata.banks = atoi(CONFIG("Save_banks"));
	rpg.savedata.bank_size = atoi(CONFIG("Save_bank_size"));
	banks = rpg.savedata.banks;
	banksize = rpg.savedata.bank_size;

	fprintf(stdout, "Initializing savedata... (%lu bytes)\n", (sizeof(SAVEDATA_ENTRY_FLAG) + sizeof(SAVEDATA_ENTRY_FULL) + sizeof(SAVEDATA_ENTRY_CHAR)) * banks * banksize);

	if (!(rpg.savedata.bank = malloc(sizeof(SAVEDATA_BANK) * banks)))
		return 0;
	for (i = 0; i < banks; i++)
		rpg.savedata.bank[i] = savedata_bank_new(banksize);
	
	fprintf(stdout, "Savedata initialized\n");

	return 1;
}
