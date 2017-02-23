/*
Function reads its input into an array, then uses the selection
sort algorithm to sort the array.
*/

#include <stdio.h>
#include "tableFill.h"

// initializes the functions used
void selectionSort(int[], int);

int main(void)
{
    // arrSize variable holds the user requested size of the array
    int arrSize = 0;
    // used in the for loops to print the before and after arrays
    int x = 0;
    int y = 0;

    // reading information from the user through stdin
    // asks the user for the wanted size of the array
    printf("please enter size of the array you want: ");
    scanf("%i", &arrSize);

    // creates the array according to the specifications
    int arr[arrSize];
    printf("\n");
    tableFill(arr, arrSize);

    // printing information to the user through stdout
    // prints out the resulting array
    printf("\narray before selection sort: \n");
    for (x = 0; x < arrSize; x++) {
        printf("%i ", *(arr + x));
    }

    // sorts the array using selection sort
    selectionSort(arr, arrSize);
    printf("\n");

    printf("array after selection sort: \n");
    for (y = 0; y < arrSize; y++) {
        printf("%i ", *(arr + y));
    }
    printf("\n");

    return 0;
}

// uses the selection sort algorithm to sort the given array
void selectionSort(int arr[], int arrSize) {
    // minimum variable holds the current minimum of the array
    int minimum = 0;
    // used in the for loops to sort the array
    int x = 0;
    int y = 0;
    for (x = 0; x < arrSize - 1; x++) {
        minimum = x;
        for (y = x + 1; y < arrSize; y++) {
            if (arr[y] < arr[minimum]) {
                minimum = y;
            }
        }
        int temp = arr[x];
        arr[x] = arr[minimum];
        arr[minimum] = temp;
    }
}
