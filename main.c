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
    int sort_algo;

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
    printf("\n\nNumbers Successfully Generated...\n\n\n");

    printf("Select a sorting algorithm: \n1.Selection Sort\n2.Bubble Sort\n3. Insertion Sort\n4.Merge Sort\n5.Quick Sort\n6. Heap Sort\n\n");
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
    start = clock();

}
