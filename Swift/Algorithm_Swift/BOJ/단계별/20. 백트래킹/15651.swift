//
//  15651.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15651
//  알고리즘 분류: 백트래킹

class BOJ15651: Solvable {
    // 메모리: 111012KB, 시간: 800ms, 코드 길이: 850B
    func run() {
        func backtrack(n: Int, m: Int) {
            var stack = [Int]()
            var answer = ""
            
            func dfs(depth: Int) {
                // m개를 모두 선택했으면 결과 출력
                if depth == m {
                    answer += stack.map { String($0) }.joined(separator: " ")
                    answer += "\n"
                    return
                }
                
                // 1부터 n까지의 수를 선택 (중복 허용)
                for i in 1...n {
                    stack.append(i)      // 결과에 추가
                    dfs(depth: depth + 1) // 다음 숫자 선택
                    stack.removeLast()   // 결과에서 제거 (백트래킹)
                }
            }
            
            dfs(depth: 0)
            print(answer)
        }

        // 입력 받기
        if let input = readLine() {
            let parts = input.split(separator: " ").map { Int($0)! }
            let n = parts[0]
            let m = parts[1]
            
            backtrack(n: n, m: m)
        }
    }
}
