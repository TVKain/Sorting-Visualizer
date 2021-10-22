#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int getMax(int n, int array[]);
void swap(int *x, int *y);

void fillTable(int rowSize, int colSize, char table[rowSize][colSize], int n, int array[]);
void printTable(int rowSize, int wordLength, char table[rowSize][wordLength]);
void fillCol(int colNum, int rowSize, int colSize, char table[rowSize][colSize], int value);

void sortSimulation(int n, int array[], int sort);

void insertionSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]);

void selectionSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]);

void bubbleSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]); 

void mergeSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize], int p, int r);
void merge(int array[], int p, int q, int r);

void quickSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize], int p, int r);
int partition(int n, int array[], int p, int r, int rowSize, int colSize, char table[rowSize][colSize]);

void heapSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]);
void heapify(int arr[], int n, int i);

void printArray(int n, int array[]);
void printArrayTable(int rowSize, int colSize, char table[rowSize][colSize], int n, int array[]);


int getMax(int n, int array[])
{
	int max = array[0];

	for (int i = 1; i < n; ++i) {
		if (max < array[i]) {
			max = array[i];
		}
	}

	return max;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void fillTable(int rowSize, int colSize, char table[rowSize][colSize], int n, int array[])
{	
	for (int i = 0; i < rowSize; ++i) {
		for (int j = 0; j < colSize - 1; ++j) {
			table[i][j] = ' ';
		}
		table[i][colSize - 1] = 0;
	}

	for (int i = 0; i < n; ++i) {
		fillCol(i, rowSize, colSize, table, array[i]);
	}
}

void fillCol(int colNum, int rowSize, int colSize, char table[rowSize][colSize], int value)
{
	int startColIndex = colNum * 3;  
	int startRowIndex = rowSize - 1; 

	for (int i = 0; i < value; ++i) {
		if (i == 0) {
			table[startRowIndex][startColIndex] = '|';
			table[startRowIndex][startColIndex + 1]= '_';
			table[startRowIndex][startColIndex + 2] = '|';
			table[startRowIndex - 1][startColIndex + 1] = '_';
		} else {
			table[startRowIndex - i][startColIndex] = '|';
			table[startRowIndex - i][startColIndex + 2] = '|';
			table[startRowIndex - i - 1][startColIndex + 1] = '_';
		}
	}

} 

void printTable(int rowSize, int wordLength, char table[rowSize][wordLength])
{
	for (int i = 0; i < rowSize; ++i) {
		printf("%s\n", table[i]);
	}
}


void printArray(int n, int array[])
{
	for (int i = 0; i < n; ++i) {
		printf(" %d ", array[i]);
	}
	printf("\n");
}

void printArrayTable(int rowSize, int colSize, char table[rowSize][colSize], int n, int array[])
{
	fillTable(rowSize, colSize, table, n, array);
	printTable(rowSize, colSize, table);
	printArray(n, array);
}

void sortSimulation(int n, int array[], int sort)
{
	int rowSize = getMax(n, array) + 1; 
	int colSize = n * 3 + 1; 

	char table[rowSize][colSize];

	switch (sort) {
		case 1:
			insertionSort(n, array, rowSize, colSize, table);
			break;
		case 2:
			selectionSort(n, array, rowSize, colSize, table);
			break;
		case 3:
			bubbleSort(n, array, rowSize, colSize, table);
			break;
		case 4:
			printArrayTable(rowSize, colSize, table, n, array);
			sleep(1);
			system("cls");
			mergeSort(n, array, rowSize, colSize, table, 0, n - 1);
			printArrayTable(rowSize, colSize, table, n, array);
			break;
		case 5:
			quickSort(n, array, rowSize, colSize, table, 0, n - 1);
			printArrayTable(rowSize, colSize, table, n, array);
			break;
		case 6:
			heapSort(n, array, rowSize, colSize, table);
			printArrayTable(rowSize, colSize, table, n, array);
			break;
		default: break;
	}
}

void insertionSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]) 
{
    int i, key, j;

    for (i = 1; i < n; i++) {
  		printArrayTable(rowSize, colSize, table, n, array);
  		sleep(1);
		system("cls");
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    printArrayTable(rowSize, colSize, table, n, array);
}


void selectionSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize])
{

	for (int i = 0; i < n - 1; ++i) {
		printArrayTable(rowSize, colSize, table, n, array);
		sleep(1);
		system("cls");
		for (int j = i + 1; j < n; ++j) {	
			if (array[i] > array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	printArrayTable(rowSize, colSize, table, n, array);
}


void bubbleSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize]) 
{
	for (int i = 0; i < n - 1; ++i) {
		printArrayTable(rowSize, colSize, table, n, array);
		sleep(1);
		system("cls");
		for (int j = n - 1; j >= i + 1; --j) {
			if (array[j] < array[j - 1]) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
		printArrayTable(rowSize, colSize, table, n, array);
}


void mergeSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize], int p, int r) 
{
	if (p >= r) {
		return;
	}
	int q = (p + r) / 2;
	mergeSort(n, array, rowSize, colSize, table, p, q);
	mergeSort(n, array, rowSize, colSize, table, q + 1, r);
	merge(array, p, q, r);
	printArrayTable(rowSize, colSize, table, n, array);
	sleep(1);
	system("cls");
}

void merge(int array[], int p, int q, int r) 
{
	int first = q - p + 1;
	int second = r - q;
	int firstArray[first + 1];
	int secondArray[second + 1];

	for (int i = 0; i < first; ++i) {
		firstArray[i] = array[p + i];
	}	

	for (int i = 0; i < second; ++i) {
		secondArray[i] = array[q + i + 1];
	}

	firstArray[first] = INT_MAX;
	secondArray[second] = INT_MAX;
	int i = 0;
	int j = 0;

	for (int k = p; k <= r; ++k) {
		if (firstArray[i] <= secondArray[j]) {
			array[k] = firstArray[i];
			i++;
		} else if (firstArray[i] > secondArray[j]) {
			array[k] = secondArray[j];
			j++;
		}
	}
}


void quickSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize], int p, int r) 
{
	if (p >= r)
		return;

	printArrayTable(rowSize, colSize, table, n, array);
	sleep(1);
	system("cls");

	int q = partition(n, array, p, r, rowSize, colSize, table);
	
	quickSort(n, array, rowSize, colSize, table, p, q - 1);
	quickSort(n, array, rowSize, colSize, table,q + 1, r);
}

int partition(int n, int array[], int p, int r, int rowSize, int colSize, char table[rowSize][colSize]) 
{
	int x = array[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; ++j) {
		if (array[j] <= x) {
			i = i + 1;
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	int tmp = array[i + 1];
	array[i + 1] = array[r];
	array[r] = tmp;



	return i + 1;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
  
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
   
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 

void heapSort(int n, int array[], int rowSize, int colSize, char table[rowSize][colSize])
{
    printArrayTable(rowSize, colSize, table, n, array);
    sleep(1);
    system("cls");

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
  
    for (int i = n - 1; i > 0; i--) {
    	printArrayTable(rowSize, colSize, table, n, array);
    	sleep(1);
    	system("cls");

        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}