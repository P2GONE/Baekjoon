#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
// Function to swap two elements 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int l, int r) {
    int pivot = arr[r];    int smll = l - 1;     
    // pivot보다 작은 수 찾는 index    
    // pivot보다 큰 값이 있으면, arr[smll]과 바꾸기    
    for(int bg=l ; bg<r ; bg++) 
    // pivot보다 큰 수 찾는 index (처음부터 pivot index 전까지 반복)    
    {        
        if(arr[bg] < pivot)        
        {            
            smll++;            
            swap(&arr[smll], &arr[bg]);        
        }    
    }     
    swap(&arr[smll+1], &arr[r]);   
    // arr[smll+1]과 pivot값 바꾸기    
    return (smll+1);                
    // smll+1을 기준점으로, 양쪽의 배열 quick sort
} 

// Function to sort an array using quick sort
void QuickSort(int arr[], int l, int r) {    
    // for left index == right index ( an array with one element )    
    if(l < r)    {        
        int pivot_index = Partition(arr, l, r);         
        // pivot 양쪽으로 Divide하여 재귀함수이용        
        QuickSort(arr, l, pivot_index-1);        
        QuickSort(arr, pivot_index+1, r);    
    }
}
int main() {
    int total_num = 0;
    int* arr;

    // 저장할 총 갯수를 입력받음
    scanf("%d", &total_num);

    // 동적으로 배열 할당
    arr = (int*)malloc(total_num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    // 입력들을 배열에 저장함
    for (int i = 0; i < total_num; i++) {
        scanf("%d", &arr[i]);
    }

    // Merge sort 호출하여 배열 정렬
    QuickSort(arr, 0, total_num - 1);

    // 정렬된 값 출력
    for (int i = 0; i < total_num; i++) {
        printf("%d\n", arr[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(arr);

    return 0;
}
