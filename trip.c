// JOHN B 3/8/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold each element and its swap count
typedef struct {
    int value;
    int swapCount;
} NumberWithSwapCount;

// Function to print the value and swap count for each element
void printSwapCount(NumberWithSwapCount array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", array[i].value, array[i].swapCount);
    }
}

// Bubble Sort algorithm implementation
void bubbleSort(NumberWithSwapCount array[], int n) {
    int totalSwaps = 0;
    NumberWithSwapCount temp;

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j].value > array[j + 1].value) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                array[j].swapCount++;
                array[j + 1].swapCount++;
                totalSwaps++;
            }
        }
    }

    // Print total swaps and swap count for each element
    printf("Bubble Sort - Total swaps: %d\n", totalSwaps);
    printSwapCount(array, n);
}

// Selection Sort algorithm implementation
void selectionSort(NumberWithSwapCount array[], int n) {
    int totalSwaps = 0;
    NumberWithSwapCount temp;

    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j].value < array[minIndex].value) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
            array[i].swapCount++;
            array[minIndex].swapCount++;
            totalSwaps++;
        }
    }

    // Print total swaps and swap count for each element
    printf("Selection Sort - Total swaps: %d\n", totalSwaps);
    printSwapCount(array, n);
}

int main() {
    // Define the initial arrays
    NumberWithSwapCount array1[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    NumberWithSwapCount array2[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};
    
    // Create copies of the original arrays
    NumberWithSwapCount array1Copy[9], array2Copy[9];
    memcpy(array1Copy, array1, sizeof(array1));
    memcpy(array2Copy, array2, sizeof(array2));

    // Perform Bubble Sort and Selection Sort on the arrays
    printf("BubSort Array 1:\n");
    bubbleSort(array1, 9);
    printf("\nBubSort Array 2:\n");
    bubbleSort(array2, 9);
    printf("\nSelectSort Array 1:\n");
    selectionSort(array1Copy, 9);
    printf("\nSelectSort Array 2:\n");
    selectionSort(array2Copy, 9);

    return 0;
}
