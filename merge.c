/*
Function reads its input into an array, then uses the merge
sort algorithm to sort the array.
*/

#include <stdio.h>
#include "tableFill.h"

// initializes the functions used
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

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
    printf("\narray before merge sort: \n");
    for (x = 0; x < arrSize; x++) {
        printf("%i ", *(arr + x));
    }

    // sorts the array using merge sort
    mergeSort(arr, 0, arrSize - 1);
    printf("\n");

    printf("array after merge sort: \n");
    for (y = 0; y < arrSize; y++) {
        printf("%i ", *(arr + y));
    }
    printf("\n");

    return 0;
}

// helper function for merge sort to help merge subarrays together
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int arrSize1 = mid - left + 1;
    int arrSize2 = right - mid;
    // temp arrays for reordering in original
    int leftSubArr[arrSize1], rightSubArr[arrSize2];
    for (i = 0; i < arrSize1; i++) {
        leftSubArr[i] = arr[left + i];
    }
    for (j = 0; j < arrSize2; j++) {
        rightSubArr[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < arrSize1 && j < arrSize2) {
        if (leftSubArr[i] <= rightSubArr[j]) {
            arr[k] = leftSubArr[i];
            i++;
        } else {
            arr[k] = rightSubArr[j];
            j++;
        }
        k++;
    }
    // add remaining
    while (i < arrSize1) {
        arr[k] = leftSubArr[i];
        i++;
        k++;
    }
    while (j < arrSize2) {
        arr[k] = rightSubArr[j];
        j++;
        k++;
    }
}

// uses the merge sort algorithm to sort the given array
void mergeSort(int arr[], int left, int right) {
    // base case: stop iterating when left index exceeds right index
    if (left < right) {
        int mid = (left + right) / 2;
        // sort halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // merge halves back together
        merge(arr, left, mid, right);
    }
}
