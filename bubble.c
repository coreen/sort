/*
Function reads its input into an array, then uses bubble
sort algorithm to sort the array.
*/

#include<stdio.h>

// initializes the functions used
void bubbleSort(int[], int);
void tableFill(int[], int);

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
    printf("\narray before bubble sort: \n");
    for (x = 0; x < arrSize; x++) {
        printf("%i ", *(arr + x));
    }

    // sorts the array using bubble sort
    bubbleSort(arr, arrSize);
    printf("\n");

    printf("array after bubble sort: \n");
    for (y = 0; y < arrSize; y++) {
        printf("%i ", *(arr + y));
    }
    printf("\n");

    return 0;
}

// uses the bubble sort algorithm to sort the given array
void bubbleSort(int arr[], int arrSize) {
    // flag to track if swapping is done
    int swapped = 0;
    while (swapped) {
        swapped = 1;
        int x = 0;
        for (x = 1; x < arrSize; x++) {
            // out of order, swap
            if (arr[x - 1] > arr[x]) {
                int temp = arr[x - 1];
                arr[x - 1] = arr[x];
                arr[x] = temp;
                swapped = 0;
            }
        }
    }
}

// fills the array with user inputed values
// if the array is full, prints an error message
void tableFill(int arr[], int arrSize) {
    // counter variable keeps track of the current number of
    // elements added to the array so far
    int counter = 0;
    // number variable keeps track of the current value to be
    // added to the array
    int number = 0;
    // x variable used in the for loop
    int x = 0;

    // reading information from the user through stdin
    // allows values to be added to the array while there is still space
    while (counter < arrSize) {
        // asks the user for an integer value to enter into the array
        printf("please enter an integer value to put into an array: ");
        scanf("%i", &number);
        // adds the number entered into the array
        arr[counter] = number;
        counter++;
    }
}
