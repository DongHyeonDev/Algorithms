//
//  24511.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24511
//  알고리즘 분류: 자료 구조, 스택, 덱, 큐

// QueueStack 구현
struct QueueStack {
    private var dataStructures: [Any]
    
    init(types: [Int], initialElements: [Int]) {
        dataStructures = []
        
        for i in 0..<types.count {
            if types[i] == 0 {  // 큐
                dataStructures.append(Queue(initialElement: initialElements[i]))
            } else {  // 스택
                dataStructures.append(Stack(initialElement: initialElements[i]))
            }
        }
    }
    
    // 원소를 queuestack에 삽입하고 결과 반환
    mutating func process(_ x0: Int) -> Int {
        var currentValue = x0
        
        for i in 0..<dataStructures.count {
            if var queue = dataStructures[i] as? Queue {
                queue.enqueue(currentValue)
                currentValue = queue.dequeue()
                dataStructures[i] = queue
            } else if var stack = dataStructures[i] as? Stack {
                stack.push(currentValue)
                currentValue = stack.pop()
                dataStructures[i] = stack
            }
        }
        
        return currentValue
    }
}

class BOJ24511: Solvable {
    // 메모리: 79516KB, 시간: 28ms, 코드 길이: 2676B
    func run() {
        // 빠른 입출력을 위한 설정
        let fileIO = RhynoFileIO()
        
        // queuestack에 있는 자료구조의 개수
        let n = fileIO.readInt()
        
        // 각 자료구조의 타입 (0: 큐, 1: 스택)
        var types = [Int]()
        for _ in 0..<n {
            types.append(fileIO.readInt())
        }
        
        // 각 자료구조에 초기에 들어있는 원소
        var initialElements = [Int]()
        for _ in 0..<n {
            initialElements.append(fileIO.readInt())
        }
        
        // 삽입할 원소의 개수
        let m = fileIO.readInt()
        
        // queuestack 초기화
        var queueStack = QueueStack(types: types, initialElements: initialElements)
        
        // 결과 저장을 위한 배열
        var results = [Int]()
        
        // 원소를 삽입하고 결과 저장
        for _ in 0..<m {
            let element = fileIO.readInt()
            let result = queueStack.process(element)
            results.append(result)
        }
        
        // 결과 출력
        print(results.map { String($0) }.joined(separator: " "))
    }
}
