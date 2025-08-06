//
//  12852.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/12852
//  알고리즘 분류: 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 역추적

class BOJ12852: Solvable {
    // 메모리: 87328KB, 시간: 16ms, 코드 길이: 1490B
    func run() {
        // N을 1로 만드는 최소 연산 횟수와 경로를 구하는 함수
        func makeOneWithPath(_ n: Int) -> (count: Int, path: [Int]) {
            if n == 1 {
                return (0, [1])
            }
            
            // dp[i] = i를 1로 만드는 최소 연산 횟수
            var dp = [Int](repeating: 0, count: n + 1)
            
            // DP로 최소 연산 횟수 계산
            for i in 2...n {
                // 기본적으로 1을 빼는 연산
                dp[i] = dp[i - 1] + 1
                
                // 2로 나누어 떨어지면
                if i % 2 == 0 {
                    dp[i] = min(dp[i], dp[i / 2] + 1)
                }
                
                // 3으로 나누어 떨어지면
                if i % 3 == 0 {
                    dp[i] = min(dp[i], dp[i / 3] + 1)
                }
            }
            
            // 역추적으로 경로 구하기
            var path: [Int] = []
            var current = n
            
            while current >= 1 {
                path.append(current)
                
                if current == 1 {
                    break
                }
                
                // 현재 값에서 어떤 연산으로 왔는지 확인
                // 가능한 이전 상태들을 확인하여 최적해를 선택
                
                var next = current - 1  // 기본값: 1을 뺀 경우
                
                // 2로 나누어 떨어지고, 2로 나눈 경우가 더 적은 연산이면
                if current % 2 == 0 && dp[current / 2] + 1 == dp[current] {
                    next = current / 2
                }
                // 3으로 나누어 떨어지고, 3으로 나눈 경우가 더 적은 연산이면
                else if current % 3 == 0 && dp[current / 3] + 1 == dp[current] {
                    next = current / 3
                }
                
                current = next
            }
            
            return (dp[n], path)
        }

        // 메인 실행 부분
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        let result = makeOneWithPath(n)

        // 결과 출력
        print(result.count)
        print(result.path.map { String($0) }.joined(separator: " "))
    }
}
