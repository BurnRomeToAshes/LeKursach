#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void insertionSort(int **);
void selectionSort(int **);
void mergeSort(int **a, int low, int high);
void bubbleSort(int **);
int quickSort(int **);
void newMatrix(int **);
void printMatrix(int **);
void fileOutput(int **);

char choice = 0;
unsigned short m = 0;
unsigned short n = 0;
int ** sortedMatrix = NULL;
int iterationNumber = -1;
int mergeIterationCount = 0;
int main()
{
	

	cout << "Please enter m: ";
	cin >> m;
	cout << "Please enter n: ";
	cin >> n;

	int **matrix = new int*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	sortedMatrix = new int*[m*n];

	newMatrix(matrix);

	while (choice != 'q') {
		cout << "Press 1 for Insertion sort\nPress 2 for Selection sort\nPress 3 for Merge sort\nPress 4 for Bubble sort\nPress 5 for Quicksort\nPress 6 to generate new Matrix\nPress 7 to input number of iteations\nPress F for file output\nPress P to print the Matrix\nPress Q to quit\n";
		cin >> choice;
		switch (choice) {
		case '1':
			insertionSort(sortedMatrix);
			break;
		case '2':
			selectionSort(sortedMatrix);
			break;
		case '3':
			mergeSort(sortedMatrix, 0, n*m - 1);
			cout << "Merge sort finished!" << endl;
			break;
		case '4':
		
			break;
		case '5':
			
			break;
		case '6':
			newMatrix(matrix);
			break;
		case '7':
			cout << "Please input the number of allowed iterations: ";
			cin >> iterationNumber;
			break;
		case 'f':
			fileOutput(matrix);
			break;
		case 'p':
			printMatrix(matrix);
			break;
		case 'q':
			fileOutput(matrix);
			break;
		 default:
			cout << "Wrong input!" << endl;
			break;
		}
	}

    return 0;
}

void newMatrix(int ** matrix) {
	do {
		cout << "To input values manually press M, to input values automatically press R" << endl;
		cin >> choice;
	} while (choice != 'm' && choice != 'r');

	if (choice == 'm') {
		short k = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
				sortedMatrix[k++] = &matrix[i][j];
			}
		}
	}
	else {
		short k = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = rand() % 100 + 1;
				sortedMatrix[k++] = &matrix[i][j];
			}
		}
	}
}

void printMatrix(int ** matrix) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void fileOutput(int ** matrix) {
	ofstream outfile("test.txt");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			outfile << matrix[i][j] << " ";
		}
		outfile << endl;
	}	
	outfile.close();
}

void insertionSort(int ** matrix) {		
	int tmp = 0;
	int iterationCount = 0;
	for (int i = 1; i < n*m; i++) {
		int j = i;
		while (j > 0 && *matrix[j - 1] > *matrix[j]) {
			if (iterationNumber < 0 || iterationCount++ <= iterationNumber)
			{
				tmp = *matrix[j];
				*matrix[j] = *matrix[j - 1];
				*matrix[--j] = tmp;
			}
		}
	}
	cout << "Insersion sort finished!" << endl;
}

void selectionSort(int ** matrix) {
	int min = 0;
	int toSwitch = 0;
	int tmp = 0;
	int iterationCount = 0;
	for (int i = 0; i < m * n; i++)
	{
		min = *matrix[i];
		toSwitch = i;
		for (int j = i + 1; j< m*n; j++)
		{
			if (min>*matrix[j])
			{
				min = *matrix[j];
				toSwitch = j;
			}
		}
		if (iterationNumber < 0 || iterationCount++ <= iterationNumber)
		{
			tmp = *matrix[i];
			*matrix[i] = *matrix[toSwitch];
			*matrix[toSwitch] = tmp;
		}
	}
	cout << "Selection sort finished!" << endl;
}

void bubbleSort(int ** matrix) {

}

void quickSort(int ** matrix) {

}

void mergeSort(int **a, int low, int high)
{
	int length = high - low + 1;
	int mid = 0;
	int merge1 = 0;
	int merge2 = 0;
	int *merging = new int[length * 2];
	if (low == high)
	{
		return;
	}
	mid = (low + high) / 2;

	mergeSort(a, low, mid);
	mergeSort(a, mid + 1, high);

	for (int i = 0; i < length; i++)
	{
		merging[i] = *a[low + i];
	}

	merge1 = 0;
	merge2 = mid - low + 1;

	for (int i = 0; i < length; i++) {
		{
			if (merge2 <= high - low) {
				if (merge1 <= mid - low) {
					if (merging[merge1] > merging[merge2])
						if (mergeIterationCount++ <= iterationNumber) {
							*a[i + low] = merging[merge2++];
						}
						else {
							if (mergeIterationCount++ <= iterationNumber) {
								*a[i + low] = merging[merge1++];
							}
						}
				}
				else {
					if (mergeIterationCount++ <= iterationNumber) {
						*a[i + low] = merging[merge2++];
					}
				}
			}
			else {
				if (mergeIterationCount++ <= iterationNumber) {
					*a[i + low] = merging[merge1++];
				}
			}
		}
	}
}