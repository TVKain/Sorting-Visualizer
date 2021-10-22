#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYMBOL_SIZE 48
#define CENTER 'c'
#define LEFT 'l'

void error(const char *string)
{
	printf("%s\n", string);
	exit(EXIT_FAILURE);
}

void printErrorBlock(size_t size, char *a[size]) 
{	
	int n;
	int l;

	printf("................................................\n");
	printf(". Error:                                       .\n");
	for (size_t j = 0; j < size; ++j) {
		l = strlen(a[j]);
		n = (SYMBOL_SIZE - l) / 2 - 1;

		printf(".");
		for (int i = 0; i < n; ++i) {
			printf(" ");
		}

		if (l % 2 == 1)
			n += 1;

		printf("%s", a[j]);

		for (int i = 0; i < n; ++i) {
			printf(" ");
		}
		printf(".\n");
	}
	printf("................................................\n");


	return;
}

void printInformativeBlock(size_t size, char *a[size], char option) 
{
	int n;
	int l;

	switch (option) {
		case CENTER:
			printf(" ------------------------------------------------ \n");
			for (size_t j = 0; j < size; ++j) {

				l = strlen(a[j]);
				n = (SYMBOL_SIZE - l) / 2;

				printf("|");
				for (int i = 0; i < n; ++i) {
					printf(" ");
				}

				printf("%s", a[j]);
				if (strlen(a[j]) % 2 == 1) 
					n += 1;
				for (int i = 0; i < n; ++i) {
					printf(" ");
				}
				printf("|\n");
			}
			printf(" ------------------------------------------------ \n");
			break;
		case LEFT:
			printf(" ------------------------------------------------ \n");

			for (size_t j = 0; j < size; ++j) {

				l = strlen(a[j]);
				n = SYMBOL_SIZE - strlen(a[j]) - 1;

				printf("| %s", a[j]);
				for (int i = 0; i < n; ++i) {
					printf(" ");
				}
				printf("|\n");
			}
			printf(" ------------------------------------------------ \n");
			break;
		default: error("Invalid option!"); break; 
	}
}

void printRunningSort(size_t size, char* a[]) 
{
	printInformativeBlock(size, a, CENTER);
	getchar();
	system("cls");
	
}
