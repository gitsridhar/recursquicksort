#include <stdio.h>

void swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int partition(int data[], int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if(data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i+1], &data[high]);
    return (i + 1);
}

void iterativequicksort(int data[], int low, int high) {
    // Create an auxiliary stack  
    int stack[ high - low + 1 ];  
  
    // initialize top of stack  
    int top = -1;  
  
    // push initial values of l and h to stack  
    stack[ ++top ] = low;  
    stack[ ++top ] = high;  
  
    // Keep popping from stack while is not empty  
    while ( top >= 0 )  
    {  
        // Pop h and l  
        high = stack[ top-- ];  
        low = stack[ top-- ];  
  
        // Set pivot element at its correct position  
        // in sorted array  
        int p = partition( data, low, high );  
  
        // If there are elements on left side of pivot,  
        // then push left side to stack  
        if ( p-1 > low )  
        {  
            stack[ ++top ] = low;  
            stack[ ++top ] = p - 1;  
        }  
  
        // If there are elements on right side of pivot,  
        // then push right side to stack  
        if ( p+1 < high )  
        {  
            stack[ ++top ] = p + 1;  
            stack[ ++top ] = high;  
        }  
    }  
}

int main() {
    int data[] = {1,9,2,8,3,7,4,6,5};
    iterativequicksort(data, 0, (sizeof(data)/sizeof(data[0]))-1);
    for (int i=0; i<(sizeof(data)/sizeof(data[0])); i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
