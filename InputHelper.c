#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include "MenuHelper.c"
#include "StringHelper.c"
#include <stdarg.h>

#define RANGE 3
#define LEFT_RANGE 2
#define RIGHT_RANGE 1
#define NO_RANGE 0

int checkInputInt(char *string, int range, int start, int end)
{
	for (int i = 0; i < strlen(string); ++i) {
		if (!isdigit(string[i]))
			return 0;
	}

	int x = atoi(string);

	switch (range) {
		case RANGE:
		case LEFT_RANGE:
		case RIGHT_RANGE:
			if (x < start || x > end)
				return 0;
			break;
		case NO_RANGE: break;
		default: error("Undefined range option");
	} 

	return 1;
}

void inputInt(char *prompt, int *x, int range, ...)
{
	char buffer[32];
	int flag;
	int start = INT_MIN;
	int end = INT_MAX;

	va_list va;

	va_start(va, range);

	if (range == RANGE) {
		start = va_arg(va, int);
		end = va_arg(va, int);
	} else if (range == LEFT_RANGE) {
		start = va_arg(va, int);
	} else if (range == RIGHT_RANGE) {
		end = va_arg(va, int);
	}

	do {
		printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = 0;
		flag = checkInputInt(buffer, range, start, end);
		if (flag == 0) {
			printErrorBlock(1, (char*[]) {"Invalid Input"});
		}
	} while (flag == 0);

	sscanf(buffer, "%d", x);

	va_end(va);
}

int checkArrayRange(char *string, int size, int start, int end)
{
	int x;
	int count = 0;

	while (1) {
		sscanf(string, "%d", &x);

		if (x < start || x > end)
			return 0;

		count++;

		if (count == size)
			break;
		trimString(string);
	}

	return 1;
}

int checkInputArray(char *string, int size, int range, int start, int end) 
{
	for (int i = 0; i < strlen(string); ++i) {
		if (!isdigit(string[i]) && string[i] != ' ') {
			return 0;
		}
	}

	if (checkStringInt(string, size) == 0) 
		return 0;
	

	char tmp[strlen(string) * sizeof(char)];
	strcpy(tmp, string);

	switch (range) {
		case NO_RANGE: break;
		case LEFT_RANGE:
		case RIGHT_RANGE:
		case RANGE: 
			if (checkArrayRange(tmp, size, start, end) == 0) {
				return 0;
			}
			break;
		default: break;
	}

	return 1; 
}

void InputArrayOfInt(char *prompt, int size, int *a, int range, ...)
{
	char buffer[32];
	int flag;
	int count = 0;

	va_list va;
	int start = INT_MIN;
	int end = INT_MAX;

	va_start(va, range);

	if (range == RANGE) {
		start = va_arg(va, int);
		end = va_arg(va, int); 
	} else if (range == LEFT_RANGE) {
		start = va_arg(va, int);
	} else if (range == RIGHT_RANGE) {
		end = va_arg(va, int);
	}
	do {
		printf("%s", prompt);
		fgets(buffer, sizeof buffer, stdin);
		buffer[strlen(buffer) - 1] = 0;
		normalized(buffer);
		flag = checkInputArray(buffer, size, range, start, end); 
		if (flag == 0) {
			printErrorBlock(1, (char*[]) {"Invalid Input"});
		} 

	} while (flag == 0);

	while (1) {
		sscanf(buffer, "%d", &a[count]);
		count++;

		if (count == size)
			break;
		trimString(buffer);
	}

}

