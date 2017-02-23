/*
Function reads its input into an array, then uses insertion
sort algorithm to sort the array.
*/

#include <stdio.h>
#include "tableFill.h"

// initializes the functions used
void insertionSort(int[], int);

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
    printf("\narray before insertion sort: \n");
    for (x = 0; x < arrSize; x++) {
        printf("%i ", *(arr + x));
    }

    // sorts the array using insertion sort
    insertionSort(arr, arrSize);
    printf("\n");

    printf("array after insertion sort: \n");
    for (y = 0; y < arrSize; y++) {
        printf("%i ", *(arr + y));
    }
    printf("\n");

    return 0;
}

// uses the insertion sort algorithm to sort the given array
void insertionSort(int arr[], int arrSize) {
    int x = 0;
    for (x = 1; x < arrSize - 1; x++) {
        int temp = arr[x];
        int y = x - 1;
        // swap intermediate values until temp in sorted position
        while (y >= 0 && arr[y] > temp) {
            arr[y + 1] = arr[y];
            y--;
        }
        arr[y + 1] = temp;
    }
}
