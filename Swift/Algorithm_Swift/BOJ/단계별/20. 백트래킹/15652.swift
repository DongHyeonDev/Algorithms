//
//  15652.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15652
//  알고리즘 분류: 백트래킹

class BOJ15652: Solvable {
    // 메모리: 79848KB, 시간: 20ms, 코드 길이: 1058B
    func run() {
        // 비내림차순 수열 생성 함수 (N과 M (4))
        func generateSequences(n: Int, m: Int) {
            var stack = [Int]()   // 현재 수열 저장
            var output = ""       // 결과 누적

            // depth: 현재 뽑은 개수, start: 이번 자리에 최소 이 값부터 선택
            func dfs(start: Int, depth: Int) {
                if depth == m {
                    // 수열이 완성되면 한 줄로 만들어 output에 추가
                    output += stack.map(String.init).joined(separator: " ")
                    output += "\n"
                    return
                }
                // 비내림차순을 위해 start부터 n까지 반복
                for num in start...n {
                    stack.append(num)
                    dfs(start: num, depth: depth + 1)
                    stack.removeLast()
                }
            }

            dfs(start: 1, depth: 0)
            // 모든 수열을 한 번에 출력
            print(output, terminator: "")
        }

        // 입력 처리
        if let line = readLine() {
            let parts = line.split(separator: " ").map { Int($0)! }
            let n = parts[0], m = parts[1]
            generateSequences(n: n, m: m)
        }
    }
}
