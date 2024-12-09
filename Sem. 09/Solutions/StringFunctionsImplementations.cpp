const char TERMINATE_SYMBOL = '\0';

unsigned myStrLen(const char* str) {
	if (!str) {
		return 0;
	}

	unsigned index = 0;
	while (str[index] != TERMINATE_SYMBOL) {
          index++;
	}

	return index;
}
