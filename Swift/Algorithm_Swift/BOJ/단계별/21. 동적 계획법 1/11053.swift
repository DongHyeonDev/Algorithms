//
//  11053.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11053
//  알고리즘 분류: 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열 문제

class BOJ11053: Solvable {
    // 메모리: 79508KB, 시간: 16ms, 코드 길이: 504B
    func run() {
        // 빠른 입출력을 위한 File I/O
        let fileIO = RhynoFileIO()

        // 수열의 크기 N
        let n = fileIO.readInt()

        // 수열 A 읽기
        var A = [Int]()
        A.reserveCapacity(n)
        for _ in 0..<n {
            A.append(fileIO.readInt())
        }

        // dp[i]: A[i]를 마지막 원소로 하는 LIS의 길이
        var dp = [Int](repeating: 1, count: n)
        var answer = 1

        // O(N²) DP: i 이전의 모든 j를 탐색
        for i in 0..<n {
            for j in 0..<i {
                if A[j] < A[i] {
                    dp[i] = max(dp[i], dp[j] + 1)
                }
            }
            answer = max(answer, dp[i])
        }

        // 결과 출력
        print(answer)
    }
}
