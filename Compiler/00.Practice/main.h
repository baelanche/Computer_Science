#define STR_MAX_LEN 1000

extern char* ltrim(char* s) {
	char* begin;
	begin = s;

	while (*begin != '\0') {
		if (isspace(*begin)) {
			begin++;
		}
		else {
			s = begin;
			break;
		}
	}
	return s;
}

extern char* rtrim(char* s) {
	char t[STR_MAX_LEN];
	char *end;

	strcpy(t, s);
	end = t + strlen(t) - 1;
	while (end != t && isspace(*end)) {
		end--;
	}
	*(end + 1) = '\0';
	s = t;

	return s;
}

extern char* trim(char* s) {
	return rtrim(ltrim(s));
}
