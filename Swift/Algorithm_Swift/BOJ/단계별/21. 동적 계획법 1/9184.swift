//
//  9184.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9184
//  알고리즘 분류: 다이나믹 프로그래밍, 재귀

class BOJ9184: Solvable {
    // 메모리: 79516KB, 시간: 40ms, 코드 길이: 1681B
    func run() {
        // dp[a][b][c]에는 0 ≤ a,b,c ≤ 20 범위에서 w(a,b,c)를 저장합니다.
        var dp = Array(
            repeating: Array(
                repeating: Array(repeating: 0, count: 21),
                count: 21
            ),
            count: 21
        )
        
        // 1) 초기 조건: a=0 or b=0 or c=0 이면 w=1
        for a in 0...20 {
            for b in 0...20 {
                for c in 0...20 {
                    if a == 0 || b == 0 || c == 0 {
                        dp[a][b][c] = 1
                    }
                }
            }
        }
        
        // 2) 나머지 점화식으로 채우기
        for a in 1...20 {
            for b in 1...20 {
                for c in 1...20 {
                    if a < b && b < c {
                        dp[a][b][c] = dp[a][b][c-1]
                            + dp[a][b-1][c-1]
                            - dp[a][b-1][c]
                    } else {
                        dp[a][b][c] = dp[a-1][b][c]
                            + dp[a-1][b-1][c]
                            + dp[a-1][b][c-1]
                            - dp[a-1][b-1][c-1]
                    }
                }
            }
        }
        
        // w(a,b,c)를 묻는 함수: 주어진 a,b,c에 따라 테이블을 참조하거나 1을 반환
        func w(_ a: Int, _ b: Int, _ c: Int) -> Int {
            if a <= 0 || b <= 0 || c <= 0 { return 1 }
            if a > 20 || b > 20 || c > 20 { return dp[20][20][20] }
            return dp[a][b][c]
        }

        // 3) 입력을 한 줄씩 읽어서 처리
        while let line = readLine() {
            // 공백 기준으로 나누고 정수 변환
            let parts = line.split(separator: " ").compactMap { Int($0) }
            // EOF 혹은 잘못된 형식이면 종료
            if parts.count != 3 { break }
            let a = parts[0], b = parts[1], c = parts[2]
            // 종료 조건
            if a == -1 && b == -1 && c == -1 {
                break
            }
            let result = w(a, b, c)
            print("w(\(a), \(b), \(c)) = \(result)")
        }
    }
}
