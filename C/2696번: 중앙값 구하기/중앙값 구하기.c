/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2696                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2696                           #+#        #+#      #+#    */
/*   Solved: 2026/01/14 15:32:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max_heap[5000];
int max_size = 0;

int min_heap[5000];
int min_size = 0;

int medians[5000];
int median_count = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 최대 힙 연산
void max_push(int x) {
    max_heap[max_size++] = x;
    
    int idx = max_size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (max_heap[parent] >= max_heap[idx]) break;
        swap(&max_heap[parent], &max_heap[idx]);
        idx = parent;
    }
}

int max_pop() {
    int result = max_heap[0];
    max_heap[0] = max_heap[--max_size];
    
    int idx = 0;
    while (idx * 2 + 1 < max_size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int largest = idx;
        
        if (left < max_size && max_heap[left] > max_heap[largest]) {
            largest = left;
        }
        if (right < max_size && max_heap[right] > max_heap[largest]) {
            largest = right;
        }
        
        if (largest == idx) break;
        swap(&max_heap[idx], &max_heap[largest]);
        idx = largest;
    }
    
    return result;
}

int max_top() {
    return max_heap[0];
}

// 최소 힙 연산
void min_push(int x) {
    min_heap[min_size++] = x;
    
    int idx = min_size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (min_heap[parent] <= min_heap[idx]) break;
        swap(&min_heap[parent], &min_heap[idx]);
        idx = parent;
    }
}

int min_pop() {
    int result = min_heap[0];
    min_heap[0] = min_heap[--min_size];
    
    int idx = 0;
    while (idx * 2 + 1 < min_size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = idx;
        
        if (left < min_size && min_heap[left] < min_heap[smallest]) {
            smallest = left;
        }
        if (right < min_size && min_heap[right] < min_heap[smallest]) {
            smallest = right;
        }
        
        if (smallest == idx) break;
        swap(&min_heap[idx], &min_heap[smallest]);
        idx = smallest;
    }
    
    return result;
}

int min_top() {
    return min_heap[0];
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int M;
        scanf("%d", &M);
        
        max_size = 0;
        min_size = 0;
        median_count = 0;
        
        for (int i = 1; i <= M; i++) {
            int num;
            scanf("%d", &num);
            
            // 1. 힙에 추가
            if (max_size == 0 || num <= max_top()) {
                max_push(num);
            } else {
                min_push(num);
            }
            
            // 2. 균형 맞추기
            if (max_size > min_size + 1) {
                min_push(max_pop());
            } else if (min_size > max_size) {
                max_push(min_pop());
            }
            
            // 3. 홀수번째면 중앙값 저장
            if (i % 2 == 1) {
                medians[median_count++] = max_top();
            }
        }
        
        // 출력
        printf("%d\n", median_count);
        for (int i = 0; i < median_count; i++) {
            printf("%d", medians[i]);
            if ((i + 1) % 10 == 0 || i == median_count - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
    
    return 0;
}