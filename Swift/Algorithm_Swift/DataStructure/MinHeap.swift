//
//  MinHeap.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/24/25.
//

// 제네릭 최소 힙 구현 (제네릭)
struct MinHeap<T> {
    private var heap = [T]()
    private let isOrderedBefore: (T, T) -> Bool
    
    init(_ isOrderedBefore: @escaping (T, T) -> Bool) {
        self.isOrderedBefore = isOrderedBefore
    }
    
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
        
        while childIndex > 0 {
            let parentIndex = self.parentIndex(of: childIndex)
            
            if !isOrderedBefore(heap[childIndex], heap[parentIndex]) {
                break
            }
            
            swap(at: parentIndex, and: childIndex)
            childIndex = parentIndex
        }
    }
    
    // 아래로 내리기 (삭제 후 힙 성질 유지)
    private mutating func heapifyDown(from index: Int) {
        var parentIndex = index
        
        while true {
            var smallestIndex = parentIndex
            let leftIndex = leftChildIndex(of: parentIndex)
            let rightIndex = rightChildIndex(of: parentIndex)
            
            // 왼쪽 자식이 더 작으면
            if leftIndex < count && isOrderedBefore(heap[leftIndex], heap[smallestIndex]) {
                smallestIndex = leftIndex
            }
            
            // 오른쪽 자식이 더 작으면
            if rightIndex < count && isOrderedBefore(heap[rightIndex], heap[smallestIndex]) {
                smallestIndex = rightIndex
            }
            
            // 더 이상 교환할 필요가 없으면 종료
            if smallestIndex == parentIndex {
                break
            }
            
            swap(at: parentIndex, and: smallestIndex)
            parentIndex = smallestIndex
        }
    }
    
    // 원소 삽입
    mutating func insert(_ value: T) {
        heap.append(value)
        heapifyUp(from: count - 1)
    }
    
    // 최솟값 제거 및 반환
    mutating func extractMin() -> T? {
        guard !isEmpty else { return nil }
        
        if count == 1 {
            return heap.removeLast()
        }
        
        let min = heap[0]
        heap[0] = heap.removeLast()
        heapifyDown(from: 0)
        
        return min
    }
    
    // 최솟값 확인
    func peek() -> T? {
        return heap.first
    }
}
