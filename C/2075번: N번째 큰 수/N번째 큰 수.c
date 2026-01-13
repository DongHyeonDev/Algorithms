/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2075                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2075                           #+#        #+#      #+#    */
/*   Solved: 2026/01/13 14:37:46 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int heap[1500];
int heap_size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    heap[heap_size++] = x;
    
    int idx = heap_size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) break;
        
        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

int pop() {
    int min_value = heap[0];
    heap[0] = heap[--heap_size];
    
    int idx = 0;
    while (idx * 2 + 1 < heap_size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = idx;
        
        if (left < heap_size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap_size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest == idx) break;
        
        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
    
    return min_value;
}

int top() {
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N * N; i++) {
        int num;
        scanf("%d", &num);
        
        if (heap_size < N) {
            push(num);
        } else if (num > top()) {
            pop();
            push(num);
        }
    }
    
    printf("%d\n", top());
    
    return 0;
}