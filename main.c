#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void Selection_sort(int Arr[], int n);
void Bubble_sort(int Arr[], int n);
void Insertion_sort(int Arr[], int n);

void merge(int Arr[], int left, int mid, int right);
void Merge_sort(int Arr[], int left, int right);

void Quick_sort(int Arr[], int low, int high);
void Heap_sort(int Arr[], int size);

int main() {
    clock_t start, end;
    double cpu_time_used; 

    unsigned long int MAX_RANGE = 1000000; // maximum possible integer

    // asks and stores the number of elements
    int n, data_method, start_val, sort_algo;

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

    printf("\nSelect a sorting algorithm: \n1.Selection Sort\n2.Bubble Sort\n3. Insertion Sort\n4.Merge Sort\n5.Quick Sort\n6. Heap Sort\n\n");
    scanf("%d", &sort_algo);

    //selection of algorithm (Need pa dagdagan error handling pero goods na muna to)
    switch (sort_algo)
        {
        case 1:
            Selection_sort(numbers, n);
            break;
        
        case 2:

            Insertion_sort(numbers, n);
            break;
        
        case 3:
        
            Bubble_sort(numbers, n);
            break;
        
        case 4:
        
            Merge_sort(numbers, 0, n-1);
            break;

        case 5:
        
            Quick_sort(numbers, 0, n-1);
            break;
        
        case 6:
        
            Heap_sort(numbers, n);
            break;

        default:
            printf("Please select a valid algorithm!\n");
            break;
        }

        free(numbers);
        return 0;
}


void Selection_sort(int Arr[], int n) {


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
