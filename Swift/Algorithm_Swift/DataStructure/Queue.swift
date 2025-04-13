//
//  Queue.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/13/25.
//

// 큐 자료구조 구현
struct Queue {
    private var elements: [Int] = []
    private var head = 0
    
    // 큐에 요소 추가
    mutating func push(_ x: Int) {
        elements.append(x)
    }
    
    // 큐에서 요소 제거하고 반환
    mutating func pop() -> Int {
        if isEmpty() {
            return -1
        }
        
        let value = elements[head]
        head += 1
        
        // 큐의 앞부분이 너무 커지면 배열 최적화
        if head > 1000 {
            elements.removeFirst(head)
            head = 0
        }
        
        return value
    }
    
    // 큐 크기 반환
    func size() -> Int {
        return elements.count - head
    }
    
    // 큐가 비어 있는지 확인
    func isEmpty() -> Bool {
        return size() == 0
    }
    
    // 큐의 맨 앞 요소 반환
    func front() -> Int {
        if isEmpty() {
            return -1
        }
        return elements[head]
    }
    
    // 큐의 맨 뒤 요소 반환
    func back() -> Int {
        if isEmpty() {
            return -1
        }
        return elements.last!
    }
}
