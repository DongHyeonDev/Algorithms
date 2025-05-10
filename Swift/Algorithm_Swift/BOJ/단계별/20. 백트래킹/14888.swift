//
//  14888.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14888
//  알고리즘 분류: 브루트포스 알고리즘, 백트래킹

class BOJ14888: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 1596B
    func run() {
        // 전역 변수: 최댓값, 최솟값
        var maxResult = Int.min
        var minResult = Int.max

        func dfs(_ idx: Int,
                 _ current: Int,
                 _ add: Int, _ sub: Int, _ mul: Int, _ div: Int,
                 _ numbers: [Int]) {
            // 모든 연산자를 다 썼다면 결과 갱신
            if idx == numbers.count {
                maxResult = max(maxResult, current)
                minResult = min(minResult, current)
                return
            }
            
            let next = numbers[idx]
            
            // 덧셈
            if add > 0 {
                dfs(idx + 1, current + next,
                    add - 1, sub, mul, div, numbers)
            }
            // 뺄셈
            if sub > 0 {
                dfs(idx + 1, current - next,
                    add, sub - 1, mul, div, numbers)
            }
            // 곱셈
            if mul > 0 {
                dfs(idx + 1, current * next,
                    add, sub, mul - 1, div, numbers)
            }
            // 나눗셈 (C++14 방식: 음수는 절댓값 나눗셈 후 부호 복원)
            if div > 0 {
                let divided: Int
                if current < 0 {
                    divided = -((abs(current) / next))
                } else {
                    divided = current / next
                }
                dfs(idx + 1, divided,
                    add, sub, mul, div - 1, numbers)
            }
        }

        func main() {
            let _ = Int(readLine()!)!
            let numbers = readLine()!.split(separator: " ").map { Int($0)! }
            let ops = readLine()!.split(separator: " ").map { Int($0)! }
            // ops 순서: [+, -, ×, ÷]
            
            // DFS 시작: 첫 번째 숫자를 초기 current로
            dfs(1, numbers[0],
                ops[0], ops[1], ops[2], ops[3],
                numbers)
            
            // 출력
            print(maxResult)
            print(minResult)
        }

        main()
    }
}
