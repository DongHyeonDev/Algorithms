//
//  Deque.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/15/25.
//

// 양방향 덱 구현
struct Deque<T> {
    private var frontStack: [T] = []
    private var backStack: [T] = []

    var isEmpty: Bool {
        return frontStack.isEmpty && backStack.isEmpty
    }

    var count: Int {
        return frontStack.count + backStack.count
    }

    mutating func pushFront(_ value: T) {
        frontStack.append(value)
    }

    mutating func pushBack(_ value: T) {
        backStack.append(value)
    }

    mutating func popFront() -> T? {
        if frontStack.isEmpty {
            frontStack = backStack.reversed()
            backStack.removeAll()
        }
        return frontStack.popLast()
    }

    mutating func popBack() -> T? {
        if backStack.isEmpty {
            backStack = frontStack.reversed()
            frontStack.removeAll()
        }
        return backStack.popLast()
    }

    func front() -> T? {
        return frontStack.isEmpty ? backStack.first : frontStack.last
    }

    func back() -> T? {
        return backStack.isEmpty ? frontStack.first : backStack.last
    }
}
