//
//  MaxHeap.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/23/25.
//

// 최대 힙 구현
struct MaxHeap {
    private var heap = [Int]()
    
    var isEmpty: Bool {
        return heap.isEmpty
    }
    
    var count: Int {
        return heap.count
    }
    
    // 부모 노드의 인덱스
    private func parentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    // 왼쪽 자식 노드의 인덱스
    private func leftChildIndex(of index: Int) -> Int {
        return 2 * index + 1
    }
    
    // 오른쪽 자식 노드의 인덱스
    private func rightChildIndex(of index: Int) -> Int {
        return 2 * index + 2
    }
    
    // 두 인덱스의 값을 교환
    private mutating func swap(at i: Int, and j: Int) {
        heap.swapAt(i, j)
    }
    
    // 위로 올리기 (삽입 후 힙 성질 유지)
    private mutating func heapifyUp(from index: Int) {
        var childIndex = index
        let child = heap[childIndex]
        var parentIndex = self.parentIndex(of: childIndex)
        
        while childIndex > 0 && heap[parentIndex] < child {
            heap[childIndex] = heap[parentIndex]
            childIndex = parentIndex
            parentIndex = self.parentIndex(of: childIndex)
        }
        
        heap[childIndex] = child
    }
    
    // 아래로 내리기 (삭제 후 힙 성질 유지)
    private mutating func heapifyDown(from index: Int) {
        var parentIndex = index
        
        while true {
            var candidateIndex = parentIndex
            let leftIndex = leftChildIndex(of: parentIndex)
            let rightIndex = rightChildIndex(of: parentIndex)
            
            if leftIndex < count && heap[leftIndex] > heap[candidateIndex] {
                candidateIndex = leftIndex
            }
            
            if rightIndex < count && heap[rightIndex] > heap[candidateIndex] {
                candidateIndex = rightIndex
            }
            
            if candidateIndex == parentIndex {
                return
            }
            
            swap(at: parentIndex, and: candidateIndex)
            parentIndex = candidateIndex
        }
    }
    
    // 원소 삽입
    mutating func insert(_ value: Int) {
        heap.append(value)
        heapifyUp(from: count - 1)
    }
    
    // 최대값 제거 및 반환
    mutating func extractMax() -> Int? {
        guard !isEmpty else { return nil }
        
        if count == 1 {
            return heap.removeLast()
        }
        
        let max = heap[0]
        heap[0] = heap.removeLast()
        heapifyDown(from: 0)
        
        return max
    }
    
    // 최대값 확인 (제거하지 않음)
    func peek() -> Int? {
        return heap.first
    }
}
