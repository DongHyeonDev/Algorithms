//
//  1904.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1904
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ1904: Solvable {
    // 메모리: 87324KB, 시간: 20ms, 코드 길이: 596B
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // dp[1]과 dp[2]를 안전하게 다루기 위해 크기를 max(3, n+1)로 설정
            var dp = [Int](repeating: 0, count: max(3, n + 1))
            
            // 기본 값 설정
            dp[1] = 1  // 길이 1: "1" 한 가지
            dp[2] = 2  // 길이 2: "11", "00" 두 가지
            
            // n > 2일 때부터 점화식으로 계산
            // dp[i] = dp[i-1] + dp[i-2] (mod 15746)
            if n > 2 {
                for i in 3...n {
                    dp[i] = (dp[i-1] + dp[i-2]) % 15746
                }
            }
            
            // 결과 출력
            print(dp[n])
        }
    }
}
