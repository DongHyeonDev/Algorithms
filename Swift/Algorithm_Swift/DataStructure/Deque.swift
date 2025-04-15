//
//  Deque.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/15/25.
//

// 덱(Deque) 구조체: frontStack과 backStack 두 개의 스택으로 덱 구현
struct Deque<T> {
    private var frontStack: [T] = []
    private var backStack: [T] = []

    var isEmpty: Bool {
        return frontStack.isEmpty && backStack.isEmpty
    }

    var count: Int {
        return frontStack.count + backStack.count
    }

    // 앞에 삽입
    mutating func pushFront(_ value: T) {
        frontStack.append(value)
    }

    // 뒤에 삽입
    mutating func pushBack(_ value: T) {
        backStack.append(value)
    }

    // 앞에서 제거
    mutating func popFront() -> T? {
        if frontStack.isEmpty {
            frontStack = backStack.reversed()
            backStack.removeAll()
        }
        return frontStack.popLast()
    }

    // 뒤에서 제거
    mutating func popBack() -> T? {
        if backStack.isEmpty {
            backStack = frontStack.reversed()
            frontStack.removeAll()
        }
        return backStack.popLast()
    }

    // 앞 요소 조회
    func front() -> T? {
        return frontStack.isEmpty ? backStack.first : frontStack.last
    }

    // 뒤 요소 조회
    func back() -> T? {
        return backStack.isEmpty ? frontStack.first : backStack.last
    }
}
