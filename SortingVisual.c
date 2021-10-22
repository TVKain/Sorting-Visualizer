#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Sorting.c"
#include "InputHelper.c"

int *inputArray(int *size)
{
	int n;
	int choice;
	int flag = 0;
	char arrayString[64];
	char tmp[8];
	char prompt[128] = "The enterred array: ";
	int *array;

	printInformativeBlock(1, (char*[]) {"INPUT ARRAY"}, CENTER);

	inputInt("Input array size: ", &n, LEFT_RANGE, 1);

	array = malloc(n * sizeof(int));

	InputArrayOfInt("Input elements: ", n, array, LEFT_RANGE, 0); 

	for (int i = 0; i < n; ++i) {
		strcat(arrayString, itoa(array[i], tmp, 10));
		strcat(arrayString, " ");
	}

	strcat(prompt, arrayString);

	printInformativeBlock(1, (char*[]) {prompt}, CENTER);
	printInformativeBlock(2, (char*[]) {"1. Re enter the array", "2. Confirm"}, LEFT);

	inputInt("Enter your choice: ", &choice, RANGE, 1, 2);
	
	*size = n;

	if (choice == 1) {
		system("cls");
		free(array);
		array = inputArray(size);
	}



	return array;
}

int chooseSorting()
{
	int sort;
	int choice;
	char *algorithms[6] = {	"1. Insertion Sort", "2. Selection Sort", 
							"3. Bubble Sort", "4. Merge Sort",
							"5. Quick Sort", "6. Heap Sort"};	

	printInformativeBlock(1, (char*[]) {"PICK A SORTING ALGORITHM"}, CENTER);
	printInformativeBlock(6, algorithms, LEFT);

	inputInt("Enter your choice: ", &sort, RANGE, 1, 6);

	char *chosen = myStrCat(algorithms[sort - 1] + 3, " algorithm has been chosen"); 
	printInformativeBlock(1, (char*[]) {chosen}, CENTER);
	printInformativeBlock(2, (char*[]) {"1. Pick a different algorithm", "2. Confirm"}, LEFT); 

	inputInt("Enter your choice: ", &choice, RANGE, 1, 2);

	if (choice == 1) {
		system("cls");
		sort = chooseSorting();
	}

	system("cls");

	return sort;
}

void sortSimulator(int sort, int n, int *old_array)
{
	int array[n];

	for (int i = 0; i < n; ++i) {
		array[i] = old_array[i];
	}

	switch(sort) {
		case 1: 
			printRunningSort(2, (char*[]) {"RUNNING INSERTION SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		case 2:	
			printRunningSort(2, (char*[]) {"RUNNING SELECTION SORT SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		case 3: 
			printRunningSort(2, (char*[]) {"RUNNING BUBBLE SORT SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		case 4: 
			printRunningSort(2, (char*[]) {"RUNNING MERGE SORT SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		case 5: 
			printRunningSort(2, (char*[]) {"RUNNING QUICK SORT SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		case 6: 
			printRunningSort(2, (char*[]) {"RUNNING HEAP SORT SIMULATION", "PRESS ENTER TO START"});
			sortSimulation(n, array, sort);
			break;
		default: break;
	}
	printInformativeBlock(1, (char*[]) {"Simulation has finished, press Enter to exit.."}, CENTER);
	getchar();
	system("cls");

}

int main()
{
	int choice;
	int haveRan[3] = {0, 0, 0};
	int *array;
	int size;
	char first;
	char second;
	int sort;

	do { 
		printInformativeBlock(2, (char*[]) {"SORTING VISUALIZER", "PROGRAM MENU"}, CENTER);
		printInformativeBlock(4, (char*[]) {"1. Input array", "2. Pick a sorting algorithm", "3. Run simulation", "4. Exit"}, LEFT);
		
		do {
			inputInt("Enter your choice: ", &choice, RANGE, 1, 4);
			switch (choice) {
				
				case 1: 
					if (haveRan[0] == 1) {
						printf("\tAn array has already been input\n");
						printf("\tDo you want to enter a new array ? ");
						scanf("%c", &first);
						getchar();
						if (first == 'N' || first == 'n') 
							break;
					}
					system("cls");
					array = inputArray(&size); 
					haveRan[0] = 1;
					system("cls");
					break;
				case 2:
					if (haveRan[1] == 1) {
						printf("\tAn algorithm has been chosen\n");
						printf("\tDo you want to choose a different algorithm ? ");
						scanf("%c", &second);
						getchar();
						if (second == 'N' || second == 'n') 
							break;
					}
					system("cls");
					sort = chooseSorting(sort);
					system("cls");
					haveRan[1] = 1;
					break;
				case 3:
					if (haveRan[0] == 0 && haveRan[1] == 0) {
						printErrorBlock(2, (char*[]) {"Input array has not been initialized", "Sorting algorithm has not been chosen"});
					} else if (haveRan[0] == 0) {
						printErrorBlock(1, (char*[]) {"Input array has not been initialized"});
					} else if (haveRan[1] == 0) {
						printErrorBlock(1, (char*[]) {"Sorting algorithm has not been chosen"});
					} else {
						system("cls");
						sortSimulator(sort, size, array);
					}	
					break;
				case 4: printf("Thank you have a nice day!\n"); sleep(1); system("cls"); break;
				default: 
					printErrorBlock(1, (char*[]) {"Invalid choice"});
					break;
			}
		} while (choice < 1 || choice > 4 || (choice == 3 && (haveRan[0] == 0 || haveRan[1] == 0)) || first == 'n' || first == 'N' || second == 'n' || second == 'N');
	} while (choice != 4);

	return 0;
}