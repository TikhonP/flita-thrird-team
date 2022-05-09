#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
    int * output = malloc(size * sizeof(int));
    
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    
    int * count = malloc(max+1 * sizeof(int));
    
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
    free(output);
    free(count);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void captureArray(int array[], int size) {
    int value;
    for (int i = 0; i < size; ++i) {
        scanf("%d", &value);
        array[i] = value;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int * data = malloc(n * sizeof(int));
    captureArray(data, n);
    
    printf("Unsorted Array\n");
    printArray(data, n);
    
    countingSort(data, n);
    
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}
