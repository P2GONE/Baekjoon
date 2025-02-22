#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

#define MAXSIZE 100000
typedef struct {
    int data[MAXSIZE];
    int size;
} MinHeap;

// 최소 힙 초기화
void initHeap(MinHeap* heap) {
    heap->size = 0;
}

// 삽입 (Heapify-Up)
void insert(MinHeap* heap, int value) {
    if (heap->size >= MAXSIZE) {
        printf("Heap Overflow!\n");
        return;
    }

    // 새로운 노드를 마지막에 삽입
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    // Heapify-Up (부모와 비교)
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent] <= heap->data[i])
            break;

        // Swap (부모와 교환)
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[i];
        heap->data[i] = temp;

        i = parent;
    }
}

// 최소값 삭제 및 반환 (Heapify-Down)
int deleteMin(MinHeap* heap) {
    if (heap->size == 0) {
        return 0;  // 힙이 비어 있으면 0을 출력해야 함.
    }

    int minValue = heap->data[0];  // 최솟값 저장

    // 마지막 요소를 루트로 이동
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size && heap->data[left] < heap->data[smallest])
            smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[smallest])
            smallest = right;

        if (smallest == i)
            break;

        // Swap
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;

        i = smallest;
    }

    return minValue;
}

int main() {
    int total;
    int value;
    MinHeap heap;

    scanf("%d", &total);

    initHeap(&heap);

    for (int i = 0; i < total; i++) {
        scanf("%d", &value);

        if (value == 0) {
            // 0이 입력되면 최소값을 출력 후 삭제
            printf("%d\n", deleteMin(&heap));
        }
        else {
            insert(&heap, value);
        }
    }

    return 0;
}
