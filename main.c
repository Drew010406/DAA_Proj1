#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

    unsigned long int MAX_RANGE = 1000; //maximum possible intiger

    //asks and stores the number of elements
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    //elements array
    int numbers[n];

    //randomizes intigers and stores them in the array
    for (int i = 0; i < n; i++) {

         // rand() generates a number ; % MAXRANGE + 1 takes the remainder by the max number and adds 1 to include max[min, max)
        numbers[i] = (rand() % MAX_RANGE+1); 
    }

    //prints elements
    for (int j=0; j< n; j++) {

        printf("numbers[%d] : %d\n", j, numbers[j]);
    }

    start = clock();

}
