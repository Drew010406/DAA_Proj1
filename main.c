#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Copy_array(int source[], int dest[], int n);

void Selection_sort(int Arr[], int n);
void Bubble_sort(int Arr[], int n);
void Insertion_sort(int Arr[], int n);

void merge(int Arr[], int left, int mid, int right);
void Merge_sort(int Arr[], int left, int right);

void Quick_sort(int Arr[], int low, int high);
void Heap_sort(int Arr[], int size);

int main() {
    clock_t start, end;
    double cpu_time; 

    unsigned long int MAX_RANGE = 1000000; // maximum possible integer

    // asks and stores the number of elements
    int n, data_method, start_val;

    printf("Number of elements: ");
    scanf("%d", &n);

    printf("Data Generation Method:\n");
    printf("\t1. Randomly Generated Integers\n");
    printf("\t2. Increasing Sequence\n");
    printf("Choice: ");
    scanf("%d", &data_method);
    printf("\n");

    // allocate array
    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (data_method == 1) {
        for (int i = 0; i < n; i++) {
            numbers[i] = rand() % (MAX_RANGE + 1);
            printf("numbers[%d]: %d\n", i+1, numbers[i]);
        }
        printf("\nRandom array generated.\n");
    }
    else if (data_method == 2) {
        printf("Enter starting positive integer X: ");
        scanf("%d", &start_val);
        for (int i = 0; i < n; i++) {
            numbers[i] = start_val + i;
            printf("numbers[%d]: %d\n", i+1, numbers[i]);
        }
        printf("\nIncreasing sequence generated.\n");
    }
    else {
        printf("Invalid choice.\n");
        free(numbers);
        return 1;
    }

    //working array
    int *work = (int*)malloc(n * sizeof(int));
    if (work == NULL) {
        printf("Memory allocation failed.\n");
        free(numbers);
        return 1;
    }

    Copy_array(work, numbers, n);
    start = clock();
    Selection_sort(work, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f seconds\n", cpu_time);

    free(numbers);
    free(work);
    return 0;
}

void Copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void Selection_sort(int Arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (Arr[j] < Arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = Arr[i];
            Arr[i] = Arr[min_idx];
            Arr[min_idx] = temp;
        }
    }
}

void Bubble_sort(int Arr[], int n) {

}
void Insertion_sort(int Arr[], int n) {

}

void merge(int Arr[], int left, int mid, int right) {

}
void Merge_sort(int Arr[], int left, int right) {

}

void Quick_sort(int Arr[], int low, int high) {

}
void Heap_sort(int Arr[], int size) {

}
