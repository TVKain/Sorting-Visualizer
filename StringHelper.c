#include <string.h>
#include <stdio.h>
#include <ctype.h>

void normalized(char *string)
{
	int i = 0;

	while (string[i] != '\0') {
		if (string[i] == ' ' && string[i + 1] == ' ') {
			strcpy(&string[i], &string[i + 1]);
		} else {
			i++;
		}
	}
	if (string[0] == ' ')
		strcpy(&string[0], &string[1]);
	if (string[strlen(string) - 1] == ' ') 
		string[strlen(string) - 1] = 0;
}

void trimString(char *string)
{
	int i = 0;

	while (string[i] != ' ') {
		i++;
	}

	strcpy(&string[0], &string[i + 1]);
}

int countWhiteSpace(char *string)
{
	int count = 0;

	for (int i = 0; i < strlen(string); ++i) {
		if (string[i] == ' ')
			count++;
	}
	return count;
}

int checkStringInt(char *string, int n)
{
	for (int i = 0; i < string[i]; ++i) {
		if (!isdigit(string[i]) && string[i] != ' ')
			return 0;
	}

	if (countWhiteSpace(string) + 1 != n)
		return 0;


	return 1;
}


char *myStrCat(char *dest, char *source)
{
	char *result = malloc((strlen(dest) + strlen(source) + 1) * sizeof(char));

	strcpy(result, dest);
	strcat(result, source);

	return result;
}	
