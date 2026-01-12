/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11286                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11286                          #+#        #+#      #+#    */
/*   Solved: 2026/01/12 12:37:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[100001];
    int size;
} AbsHeap;

void init(AbsHeap* heap) {
    heap->size = 0;
}

int abs_val(int x) {
    return x < 0 ? -x : x;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// a가 b보다 우선순위가 높으면 1
int has_priority(int a, int b) {
    int abs_a = abs_val(a);
    int abs_b = abs_val(b);

    if (abs_a != abs_b) {
        return abs_a < abs_b;
    }
    return a < b;
}

void push(AbsHeap* heap, int value) {
    heap->data[++heap->size] = value;

    int idx = heap->size;
    while (idx > 1) {
        int parent = idx / 2;
        if (has_priority(heap->data[parent], heap->data[idx])) break;

        swap(&heap->data[parent], &heap->data[idx]);
        idx = parent;
    }
}

int pop(AbsHeap* heap) {
    if (heap->size == 0) return 0;

    int result = heap->data[1];
    heap->data[1] = heap->data[heap->size--];

    int idx = 1;
    while (idx * 2 <= heap->size) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int highest = idx;

        if (left <= heap->size && has_priority(heap->data[left], heap->data[highest])) {
            highest = left;
        }
        if (right <= heap->size && has_priority(heap->data[right], heap->data[highest])) {
            highest = right;
        }

        if (highest == idx) break;

        swap(&heap->data[idx], &heap->data[highest]);
        idx = highest;
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    AbsHeap heap;
    init(&heap);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        if (x != 0) {
            push(&heap, x);
        } else {
            printf("%d\n", pop(&heap));
        }
    }

    return 0;
}