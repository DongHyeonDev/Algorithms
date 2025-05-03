//
//  15649.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15649
//  알고리즘 분류: 백트래킹

class BOJ15649: Solvable {
    // 메모리: 79516KB, 시간: 92ms, 코드 길이: 1089B
    func run() {
        func backtrack(n: Int, m: Int) {
            var result: [Int] = []
            var visited = Array(repeating: false, count: n + 1)
            
            func dfs(depth: Int) {
                // m개를 모두 선택했으면 결과 출력
                if depth == m {
                    print(result.map { String($0) }.joined(separator: " "))
                    return
                }
                
                // 1부터 n까지의 수를 선택
                for i in 1...n {
                    // 아직 방문하지 않은 숫자라면
                    if !visited[i] {
                        visited[i] = true     // 방문 표시
                        result.append(i)      // 결과에 추가
                        
                        dfs(depth: depth + 1) // 다음 숫자 선택
                        
                        visited[i] = false    // 방문 표시 해제 (백트래킹)
                        result.removeLast()   // 결과에서 제거
                    }
                }
            }
            
            dfs(depth: 0)
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
