/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1927                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1927                           #+#        #+#      #+#    */
/*   Solved: 2026/01/11 19:01:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef struct {
    int data[100001];
    int size;
} MinHeap;

void init(MinHeap* heap) {
    heap->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int value) {
    heap->data[++heap->size] = value;

    int idx = heap->size;
    while (idx > 1) {
        int parent = idx / 2;
        if (heap->data[parent] <= heap->data[idx]) break;

        swap(&heap->data[parent], &heap->data[idx]);
        idx = parent;
    }
}

int pop(MinHeap* heap) {
    if (heap->size == 0) return 0;

    int min_value = heap->data[1];
    heap->data[1] = heap->data[heap->size--];

    int idx = 1;
    while (idx * 2 <= heap->size) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int smallest = idx;

        if (left <= heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right <= heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }

        if (smallest == idx) break;

        swap(&heap->data[idx], &heap->data[smallest]);
        idx = smallest;
    }

    return min_value;
}

int main() {
    int N;
    scanf("%d", &N);

    MinHeap heap;
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