//
//  9252.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9252
//  알고리즘 분류: 다이나믹 프로그래밍, 문자열, 역추적, 최장 공통 부분 수열 문제

class BOJ9252: Solvable {
    // 메모리: 87344KB, 시간: 36ms, 코드 길이: 1185B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let s = fileIO.readString()
        let t = fileIO.readString()

        let A = Array(s.utf8)
        let B = Array(t.utf8)
        let n = A.count
        let m = B.count

        let W = m + 1
        var dp = [Int](repeating: 0, count: (n + 1) * (m + 1))

        // DP 채우기
        if n > 0 && m > 0 {
            for i in 1...n {
                let ai = A[i - 1]
                let r  = i * W
                let pr = (i - 1) * W
                for j in 1...m {
                    if ai == B[j - 1] {
                        dp[r + j] = dp[pr + j - 1] + 1
                    } else {
                        let up = dp[pr + j]
                        let left = dp[r + j - 1]
                        dp[r + j] = (up >= left) ? up : left
                    }
                }
            }
        }

        // backtrack
        var i = n, j = m
        var lcsBytes = [UInt8]()
        lcsBytes.reserveCapacity(dp[n * W + m])

        while i > 0 && j > 0 {
            if A[i - 1] == B[j - 1] {
                lcsBytes.append(A[i - 1])
                i -= 1; j -= 1
            } else {
                if dp[(i - 1) * W + j] >= dp[i * W + (j - 1)] {
                    i -= 1
                } else {
                    j -= 1
                }
            }
        }

        lcsBytes.reverse()
        let lcsStr = String(bytes: lcsBytes, encoding: .utf8) ?? ""

        // 결과 출력
        let len = dp[n * W + m]
        print(len)
        if len > 0 {
            print(lcsStr)
        }
    }
}
