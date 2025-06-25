//
//  AbsoluteHeap.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/25/25.
//

// 절댓값 힙 구현
struct AbsoluteHeap {
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
    
    // 절댓값 기준 비교 함수
    // a가 b보다 우선순위가 높으면 true
    private func hasHigherPriority(_ a: Int, than b: Int) -> Bool {
        let absA = abs(a)
        let absB = abs(b)
        
        if absA != absB {
            return absA < absB  // 절댓값이 작은 것이 우선
        } else {
            return a < b  // 절댓값이 같으면 더 작은 수가 우선
        }
    }
    
    // 위로 올리기 (삽입 후 힙 성질 유지)
    private mutating func heapifyUp(from index: Int) {
        var childIndex = index
        
        while childIndex > 0 {
            let parentIndex = self.parentIndex(of: childIndex)
            
            if !hasHigherPriority(heap[childIndex], than: heap[parentIndex]) {
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
            var highestPriorityIndex = parentIndex
            let leftIndex = leftChildIndex(of: parentIndex)
            let rightIndex = rightChildIndex(of: parentIndex)
            
            // 왼쪽 자식이 더 높은 우선순위를 가지면
            if leftIndex < count && hasHigherPriority(heap[leftIndex], than: heap[highestPriorityIndex]) {
                highestPriorityIndex = leftIndex
            }
            
            // 오른쪽 자식이 더 높은 우선순위를 가지면
            if rightIndex < count && hasHigherPriority(heap[rightIndex], than: heap[highestPriorityIndex]) {
                highestPriorityIndex = rightIndex
            }
            
            // 더 이상 교환할 필요가 없으면 종료
            if highestPriorityIndex == parentIndex {
                break
            }
            
            swap(at: parentIndex, and: highestPriorityIndex)
            parentIndex = highestPriorityIndex
        }
    }
    
    // 원소 삽입
    mutating func insert(_ value: Int) {
        heap.append(value)
        heapifyUp(from: count - 1)
    }
    
    // 절댓값이 가장 작은 값 제거 및 반환
    mutating func extractMin() -> Int? {
        guard !isEmpty else { return nil }
        
        if count == 1 {
            return heap.removeLast()
        }
        
        let min = heap[0]
        heap[0] = heap.removeLast()
        heapifyDown(from: 0)
        
        return min
    }
    
    // 절댓값이 가장 작은 값 확인 (제거하지 않음)
    func peek() -> Int? {
        return heap.first
    }
}
