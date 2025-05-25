//
//  2565.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2565
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ2565: Solvable {
    // 메모리: 79516KB, 시간: 12ms, 코드 길이: 588B
    func run() {
        // 빠른 입출력
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()
        var wires = [(a: Int, b: Int)]()
        wires.reserveCapacity(N)
        for _ in 0..<N {
            wires.append((fileIO.readInt(), fileIO.readInt()))
        }

        // A 전봇대 기준으로 정렬
        wires.sort { $0.a < $1.a }

        // B 번호들만 뽑아서 LIS 길이 구하기
        let B = wires.map { $0.b }
        var dp = [Int](repeating: 1, count: N)
        var lis = 1

        for i in 0..<N {
            for j in 0..<i {
                if B[j] < B[i] {
                    dp[i] = max(dp[i], dp[j] + 1)
                }
            }
            lis = max(lis, dp[i])
        }

        // 제거할 전깃줄 수 = 전체 N - 남길 수 있는 최대 교차 없는 전깃줄 수 (LIS)
        print(N - lis)
    }
}
