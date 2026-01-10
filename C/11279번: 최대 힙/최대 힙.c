/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11279                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11279                          #+#        #+#      #+#    */
/*   Solved: 2026/01/10 04:09:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef struct {
    int data[100001];
    int size;
} MaxHeap;

void init(MaxHeap* heap) {
    heap->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(MaxHeap* heap, int value) {
    heap->data[++heap->size] = value;

    int idx = heap->size;
    while (idx > 1) {
        int parent = idx / 2;
        if (heap->data[parent] >= heap->data[idx]) break;

        swap(&heap->data[parent], &heap->data[idx]);
        idx = parent;
    }
}

int pop(MaxHeap* heap) {
    if (heap->size == 0) return 0;

    int max_value = heap->data[1];
    heap->data[1] = heap->data[heap->size--];

    int idx = 1;
    while (idx * 2 <= heap->size) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int largest = idx;

        if (left <= heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right <= heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }

        if (largest == idx) break;

        swap(&heap->data[idx], &heap->data[largest]);
        idx = largest;
    }

    return max_value;
}

int main() {
    int N;
    scanf("%d", &N);

    MaxHeap heap;
    init(&heap);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        if (x > 0) {
            push(&heap, x);
        } else {
            printf("%d\n", pop(&heap));
        }
    }

    return 0;
}