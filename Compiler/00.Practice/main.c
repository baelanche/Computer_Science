#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
#include "main.h"

#define ID_MAX_LEN 100
#define STR_MAX_LEN 1000
#define PLUS "<PLUS, > \t+\n"
#define MINUS "<MINUS, > \t-\n"
#define MULTI "<MULTI, > \t*\n"
#define DIVIDE "<DIVIDE, > \t/\n"
#define ASSIGN "<ASSIGN, > \t=\n"
#define COLON "<COLON, > \t:\n"

int checkSymbol(char*);
void addSymbol(char*);
int checkValue(char*);
void printNumber(char*);
void printString(char*);
int checkOperator(char);

int line_number = 1;
char symbol_table[100][11];
char string_table[100][11];
int symbol_index = 0;
int string_index = 0;

int main(int argc, char *argv[]) {
	char str[ID_MAX_LEN];
	FILE* file = NULL;

	file = fopen(argv[1], "r");
	if (file != NULL) {
		char line[STR_MAX_LEN];
		char* str;
		while (!feof(file)) {
			str = fgets(line, sizeof(line), file);
			int assign = 1;
			if (str != NULL) {
				assign = strstr(str, "=") != NULL ? 1 : 0;
			}
			if (!assign) {
				printf("Error: line %d\t%s", line_number, str);
				line_number++;
				continue;
			}

			char* ptr = strtok(str, "=");
			if (ptr != NULL) {
				char* symbol = trim(ptr);
				int isSymbol = checkSymbol(symbol);
				if (!isSymbol) { addSymbol(symbol); }
			}

			printf("<ASSIGN, > \t=\n");
			ptr = strtok(NULL, "=");
			
			if (ptr != NULL) {
				char* value = trim(ptr);
				int valueType = checkValue(value);
				// number
				if (valueType) {
					printNumber(value);
				}
				// string
				else {
					printString(value);
				}
				
			}
			// 세미콜론 검사
			if (ptr != NULL) {
				if (strstr(ptr, ";") == NULL) {
					printf("Error: line %d\t%s\n", line_number, "no semicolon");
				}
				else {
					printf("<SEMICOLON, > \t;\n");
				}
			}	
			line_number++;
		}

		fclose(file);
	}
	
	printf("\n<Symbol Table> \t\t <String Table>\n");
	printf("index \t symbols \t index \t strings\n");
	int max = symbol_index > string_index ? symbol_index : string_index;
	for (int i=0; i<max; i++) {
		if (symbol_index > i) {
			printf("%d \t %s \t", i+1, symbol_table[i]);
		}
		if (string_index > i) {
			printf("\t %d \t %s \n", i+1, string_table[i]);
		} else {
			printf("\n");
		}
	}
	return 0;
}

int checkSymbol(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (!((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90) || (97 <= s[i] && s[i] <= 122))) {
			printf("Error: line %d\t%s\n", line_number, s);
			return 1;
		}
	}

	if (48 <= s[0] && s[0] <= 57) {
		printf("Error: line %d\t%s\n", line_number, s);
		return 1;
	}

	int int_number = 0;
	for (int i = 1; i < strlen(s) - 2; i++) {
		if (48 <= s[i] && s[i] <= 57) {
			int_number++;
		}
	}
	if (int_number > 0 && !(48 <= s[strlen(s) - 2] && s[strlen(s) - 2] <= 57)) {
		printf("Error: line %d\t%s\n", line_number, s);
		return 1;
	}

	return 0;
}

void addSymbol(char* s) {
	char temp[20];
	memset(temp, '\0', 20);
	strncpy(temp, s, 10);

	for (int i = 0; i < symbol_index; i++) {
		int cmp = strcmp(symbol_table[i], temp);
		if (cmp == 0) {
			printf("<ID, %d> \t%s\n", i + 1, symbol_table[i]);
			return;
		}
	}
	strcpy(symbol_table[symbol_index], temp);
	printf("<ID, %d> \t%s\n", symbol_index + 1, symbol_table[symbol_index]);
	symbol_index++;
}

int checkValue(char* s) {
	for (int i = 0; i < strlen(s) - 1; i++) {
		if (!(48 <= s[i] && s[i] <= 57)) {
			if (s[i] != '.' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
				return 0;
			}
		}
	}
	return 1;
}

void printNumber(char* s) {
	int numberType = 0;
	int start = 0, length = 1;
	if (s[0] == '0' && strlen(s) > 2) {
		printf("Error line: %d\t%s\n", line_number, s);
		return;
	}
	for (int i = 0; i < strlen(s) - 1; i++) {
		if (s[i] == '.') {
			numberType = 1;
		}
		int op = checkOperator(s[i]);
		if (op == 0) {
			length++;
		}
		else {
			if (length > 1) {
				char buffer[100];
				memset(buffer, NULL, 100);
				char* value;
				value = strncpy(buffer, &s[start], length);
				if (numberType) {
					printf("<REAL, %s> \t%s\n", value, value);
					numberType = 0;
				}
				else {
					printf("<INT, %s> \t%s\n", value, value);
				}
				start = i + 1;
				length = 1;
			}
			switch (op) {
				case 1: printf(PLUS); break;
				case 2: printf(MINUS); break;
				case 3: printf(MULTI); break;
				case 4: printf(DIVIDE); break;
				case 5: printf(ASSIGN); break;
				case 6: printf(COLON); break;
			}
			start = i + 1;
			length = 1;
		}
	}
	if (length > 1) {
		char buffer[100];
		memset(buffer, NULL, 100);
		char* value;
		value = strncpy(buffer, &s[start], length - 1);
		if (numberType) {
			printf("<REAL, %s> \t%s\n", value, value);
			numberType = 0;
		}
		else {
			printf("<INT, %s> \t%s\n", value, value);
		}
	}
}

void printString(char *s) {
	int string = 0;
	int pos = 0;
	for (int i = 0; i < strlen(s) - 1; i++) {
		if (s[i] == '\"' && string == 1) {
			char temp[100];
			memset(temp, '\0', 20);
			int tempPos = 0;
			for (int j = pos; j <= i; j++) {
				temp[tempPos] = s[j];
				tempPos++;
			}
			string = 0;
			strcpy(string_table[string_index], temp);
			string_index++;
		}
		else if (s[i] == '\"' && string == 0) {
			pos = i;
			string = 1;
		}
		else if (string == 0) {
			int op = checkOperator(s[i]);
			switch (op) {
				case 1: printf(PLUS); break;
				case 2: printf(MINUS); break;
				case 3: printf(MULTI); break;
				case 4: printf(DIVIDE); break;
				case 5: printf(ASSIGN); break;
				case 6:;
					char *ptr = strtok(s, ":");
					int number = 1;
					int symbol = 0;
					for (int j = 0; j < strlen(ptr); j++) {
						if (!(48 <= ptr[j] && ptr[j] <= 57)) {
							number = 0;
						}
					}

					if (!number) {
						for (int j = 0; j < symbol_index; j++) {
							if (strcmp(symbol_table[j], ptr) == 0) {
								printf("<ID, %d> \t%s\n", j + 1, ptr);
								symbol = 1;
							}
						}
					}

					if (!symbol) {
						printf("<STRING, > \t%s\n", ptr);
					}

					printf(COLON);
					ptr = strtok(NULL, ":");
					ptr = strtok(ptr, " ");
					ptr = strtok(ptr, ";");
					printf("<RANGE, > \t%s\n", ptr);
					break;
				case 0:
					break;
			}
		}
	}
}

int checkOperator(char s) {
	if (s == '+')		return 1;
	else if (s == '-')	return 2;
	else if (s == '*')	return 3;
	else if (s == '/')	return 4;
	else if (s == '=')	return 5;
	else if (s == ':')	return 6;
	else				return 0;
}
