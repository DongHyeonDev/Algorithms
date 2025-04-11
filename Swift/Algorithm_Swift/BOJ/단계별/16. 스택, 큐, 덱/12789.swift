//
//  12789.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/12789
//  알고리즘 분류: 자료 구조, 스택

class BOJ12789: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 912B
    func run() {
        // 입력 받기
        if let _ = Int(readLine() ?? ""),
           let inputLine = readLine()?.split(separator: " ").compactMap({ Int($0) }) {

            var queue = inputLine // 대기열 (줄)
            var stack: [Int] = [] // 보조 공간 (한 줄 대기 구역)
            var current = 1       // 현재 간식을 받을 번호

            while !queue.isEmpty {
                if queue.first == current {
                    queue.removeFirst() // 줄에서 바로 간식 수령
                    current += 1
                } else if let top = stack.last, top == current {
                    stack.removeLast() // 보조 공간에서 간식 수령
                    current += 1
                } else {
                    stack.append(queue.removeFirst()) // 보조 공간으로 이동
                }
            }

            // 보조 공간 처리
            while let top = stack.last, top == current {
                stack.removeLast()
                current += 1
            }

            print(stack.isEmpty ? "Nice" : "Sad")
        }
    }
}
