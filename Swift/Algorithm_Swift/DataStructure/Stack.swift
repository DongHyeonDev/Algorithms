//
//  Stack.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/17/25.
//

// 스택 구현
struct Stack {
    private var elements: [Int]
    
    init(initialElement: Int) {
        elements = [initialElement]
    }
    
    // 스택에 요소 추가
    mutating func push(_ element: Int) {
        elements.append(element)
    }
    
    // 스택에서 요소 꺼내기
    mutating func pop() -> Int {
        if isEmpty() {
            return -1  // 오류 상황
        }
        return elements.removeLast()
    }
    
    // 스택이 비었는지 확인
    func isEmpty() -> Bool {
        return elements.isEmpty
    }
}
