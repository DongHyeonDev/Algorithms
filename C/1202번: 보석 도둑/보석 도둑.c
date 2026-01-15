/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1202                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1202                           #+#        #+#      #+#    */
/*   Solved: 2026/01/15 11:39:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Jewel;

int max_heap[300000];
int heap_size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    max_heap[heap_size++] = x;
    
    int idx = heap_size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (max_heap[parent] >= max_heap[idx]) break;
        swap(&max_heap[parent], &max_heap[idx]);
        idx = parent;
    }
}

int pop() {
    int result = max_heap[0];
    max_heap[0] = max_heap[--heap_size];
    
    int idx = 0;
    while (idx * 2 + 1 < heap_size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int largest = idx;
        
        if (left < heap_size && max_heap[left] > max_heap[largest]) {
            largest = left;
        }
        if (right < heap_size && max_heap[right] > max_heap[largest]) {
            largest = right;
        }
        
        if (largest == idx) break;
        swap(&max_heap[idx], &max_heap[largest]);
        idx = largest;
    }
    
    return result;
}

int compare_jewel(const void* a, const void* b) {
    Jewel* j1 = (Jewel*)a;
    Jewel* j2 = (Jewel*)b;
    return j1->weight - j2->weight;
}

int compare_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    Jewel jewels[300000];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewels[i].weight, &jewels[i].value);
    }
    
    int bags[300000];
    for (int i = 0; i < K; i++) {
        scanf("%d", &bags[i]);
    }
    
    // 정렬
    qsort(jewels, N, sizeof(Jewel), compare_jewel);
    qsort(bags, K, sizeof(int), compare_int);
    
    long long total = 0;
    int jewel_idx = 0;
    
    for (int i = 0; i < K; i++) {
        // 현재 가방에 담을 수 있는 보석들을 힙에 추가
        while (jewel_idx < N && jewels[jewel_idx].weight <= bags[i]) {
            push(jewels[jewel_idx].value);
            jewel_idx++;
        }
        
        // 가장 비싼 보석 선택
        if (heap_size > 0) {
            total += pop();
        }
    }
    
    printf("%lld\n", total);
    
    return 0;
}