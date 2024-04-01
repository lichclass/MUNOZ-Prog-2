#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int arr[], int size){
    int i, j, temp;

    for(i = 1; i < size; i++){
        
        temp = arr[i];

        for(j = i - 1; j >= 0 && arr[j] > temp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;

    }
}

void bubble(int arr[], int size){
    int i, j, swapped;

    for(i = 0; i < size - 1; i++){
        swapped = 0;
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr + j, arr + j + 1);
                swapped = 1;
            }
        }

        if(swapped == 0) break;
    }
}

void fromLow_bubble(int arr[], int size){
    int i, j, swapped = 1;
    for(i = 0; i < size - 1 && swapped != 0; i++){
        swapped = 0;
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr + j, arr + j + 1);
                swapped = 1;
            }
        }
    }
}

void fromHigh_bubble(int arr[], int size){
    int i, j, swapped = 1;
    for(i = size - 1; i > 0 && swapped != 0; i--){
        swapped = 0;
        for(j = size - 1; j > size - i - 1; j--){ 
            if(arr[j] < arr[j - 1]){
                swap(arr + j, arr + j - 1);
                swapped = 1;
            }
        }
    }
}

void swap_insertion(int arr[], int size){
    int i, j;
    for(i = 1; i < size; i++){
        for(j = i; j > 0 && arr[j] < arr[j - 1]; j--){
            swap(arr + j, arr + j - 1);
        }
    }
}

void shift_insertion(int arr[], int size){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}   

int main(){
    int arr[] = { 2, 4, 5, 3, 2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    swap_insertion(arr, size);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
