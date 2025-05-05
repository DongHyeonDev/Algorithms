//
//  15650.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15650
//  알고리즘 분류: 백트래킹

class BOJ15650: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 1135B
    func run() {
        func backtrack(n: Int, m: Int) {
            var result: [Int] = []
            
            func dfs(depth: Int, start: Int) {
                // m개를 모두 선택했으면 결과 출력
                if depth == m {
                    print(result.map { String($0) }.joined(separator: " "))
                    return
                }
                
                // 최적화: 남은 자리를 채울 수 있는 마지막 시작점 계산
                let maxStart = n - (m - depth) + 1
                
                // start부터 가능한 범위까지 수를 선택
                for i in start...maxStart {
                    result.append(i)      // 결과에 추가
                    dfs(depth: depth + 1, start: i + 1) // 다음 숫자 선택 (오름차순 유지)
                    result.removeLast()   // 결과에서 제거 (백트래킹)
                }
            }
            
            dfs(depth: 0, start: 1)
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
