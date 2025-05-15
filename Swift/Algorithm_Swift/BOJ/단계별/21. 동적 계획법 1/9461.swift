//
//  9461.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9461
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ9461: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 715B
    func run() {
        // 파도반 수열을 계산하는 함수
        func calculatePadovanSequence(_ n: Int) -> Int64 {
            // N은 최대 100이므로 크기 101의 배열 생성
            var dp = [Int64](repeating: 0, count: max(10, n + 1))
            
            // 초기값 설정
            dp[1] = 1
            dp[2] = 1
            dp[3] = 1
            
            // 점화식: P(N) = P(N-2) + P(N-3) (N > 3)
            if n > 3 {
                for i in 4...n {
                    dp[i] = dp[i-2] + dp[i-3]
                }
            }
            
            return dp[n]
        }

        // 입력 처리
        if let input = readLine(), let t = Int(input) {
            for _ in 0..<t {
                if let nInput = readLine(), let n = Int(nInput) {
                    let result = calculatePadovanSequence(n)
                    print(result)
                }
            }
        }
    }
}
