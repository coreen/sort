/*
Function reads its input into an array, then uses the quick
sort algorithm to sort the array.
*/

#include <stdio.h>
#include "tableFill.h"

// initializes the functions used
int partition(int[], int, int);
void quickSort(int[], int, int);

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
    printf("\narray before quick sort: \n");
    for (x = 0; x < arrSize; x++) {
        printf("%i ", *(arr + x));
    }

    // sorts the array using quick sort
    quickSort(arr, 0, arrSize - 1);
    printf("\n");

    printf("array after quick sort: \n");
    for (y = 0; y < arrSize; y++) {
        printf("%i ", *(arr + y));
    }
    printf("\n");

    return 0;
}

// helper function for quick sort to help find pivot element
int partition(int arr[], int lower, int upper) {
    int pivot = arr[upper];
    int x = lower - 1;
    for (int y = lower; y <= upper - 1; y++) {
        // swap if current <= pivot
        if (arr[y] <= pivot) {
            x++;
            int temp = arr[y];
            arr[y] = arr[x];
            arr[x] = temp;
        }
    }
    int temp = arr[upper];
    arr[upper] = arr[x + 1];
    arr[x + 1] = temp;
    return x + 1;
}

// uses the quick sort algorithm to sort the given array
void quickSort(int arr[], int lower, int upper) {
    // base case: stop iterating when lower bound exceeds upper bound
    if (lower < upper) {
        int partitionIndex = partition(arr, lower, upper);
        // sort partitions
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}
