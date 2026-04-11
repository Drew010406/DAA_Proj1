#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Copy_array(int source[], int dest[], int n);
void arr2file(const char *filename, const int original[], const int sorted[], int n, const char *algo);

void Selection_sort(int Arr[], int n);
void Bubble_sort(int Arr[], int n);
void Insertion_sort(int Arr[], int n);

void merge(int Arr[], int left, int mid, int right);
void Merge_sort(int Arr[], int left, int right);

int partition(int Arr[], int low, int high);
void Quick_sort(int Arr[], int low, int high);

void heapify(int Arr[], int n, int i);
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

    //seed random number generator
    srand((unsigned int)time(NULL));


    if (data_method == 1) {
        for (int i = 0; i < n; i++) {
            numbers[i] = rand() % (MAX_RANGE + 1);
        }
        printf("\nRandom array generated.\n");
    }
    else if (data_method == 2) {
        printf("Enter starting positive integer X: ");
        scanf("%d", &start_val);
        for (int i = 0; i < n; i++) {
            numbers[i] = start_val + i;
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

    Copy_array(numbers, work, n);
    start = clock();
    Selection_sort(work, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Selection Sort");

    Copy_array(numbers, work, n);
    start = clock();
    Bubble_sort(work, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Bubble Sort");

    Copy_array(numbers, work, n);
    start = clock();
    Insertion_sort(work, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Insertion Sort");

    Copy_array(numbers, work, n);
    start = clock();
    Merge_sort(work, 0, n - 1);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Merge Sort");

    Copy_array(numbers, work, n);
    start = clock();
    Quick_sort(work, 0, n - 1);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Quick Sort");

    Copy_array(numbers, work, n);
    start = clock();
    Heap_sort(work, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort: %f seconds\n", cpu_time);
    arr2file("output.txt", numbers, work, n, "Heap Sort");

    free(work);
    free(numbers);
    return 0;
}

void Copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void arr2file(const char *filename, const int original[], const int sorted[], int n, const char *algo) {
    FILE *f = fopen(filename, "a");
    if (!f) return;
    fprintf(f, "\n--- %s ---\n", algo);
    fprintf(f, "Original array (%d elements):\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", original[i]);
        if ((i+1) % 20 == 0) fprintf(f, "\n");
    }
    fprintf(f, "\nSorted array (%d elements):\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", sorted[i]);
        if ((i+1) % 20 == 0) fprintf(f, "\n");
    }
    fprintf(f, "\n");
    fclose(f);
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
    int swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (Arr[j] > Arr[j+1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void Insertion_sort(int Arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = Arr[i];
        int j = i - 1;
        while (j >= 0 && Arr[j] > key) {
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = key;
    }
}

void merge(int Arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = Arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = Arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) Arr[k++] = L[i++];
        else Arr[k++] = R[j++];
    }
    while (i < n1) Arr[k++] = L[i++];
    while (j < n2) Arr[k++] = R[j++];
    free(L);
    free(R);
}

void Merge_sort(int Arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort(Arr, left, mid);
        Merge_sort(Arr, mid+1, right);
        merge(Arr, left, mid, right);
    }
}

int partition(int Arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (Arr[mid] < Arr[low]) { int t = Arr[low]; Arr[low] = Arr[mid]; Arr[mid] = t; }
    if (Arr[high] < Arr[low]) { int t = Arr[low]; Arr[low] = Arr[high]; Arr[high] = t; }
    if (Arr[high] < Arr[mid]) { int t = Arr[mid]; Arr[mid] = Arr[high]; Arr[high] = t; }

    int pivot = Arr[mid];
    Arr[mid] = Arr[high];
    Arr[high] = pivot;

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (Arr[j] <= pivot) {
            i++;
            int temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    }
    int temp = Arr[i+1];
    Arr[i+1] = Arr[high];
    Arr[high] = temp;
    return i+1;
}

void Quick_sort(int Arr[], int low, int high) {
    if (low < high) {
        int pi = partition(Arr, low, high);
        Quick_sort(Arr, low, pi-1);
        Quick_sort(Arr, pi+1, high);
    }
}

void heapify(int Arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && Arr[left] > Arr[largest]) largest = left;
    if (right < n && Arr[right] > Arr[largest]) largest = right;
    if (largest != i) {
        int temp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = temp;
        heapify(Arr, n, largest);
    }
}

void Heap_sort(int Arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(Arr, n, i);
    for (int i = n-1; i > 0; i--) {
        int temp = Arr[0];
        Arr[0] = Arr[i];
        Arr[i] = temp;
        heapify(Arr, i, 0);
    }
}