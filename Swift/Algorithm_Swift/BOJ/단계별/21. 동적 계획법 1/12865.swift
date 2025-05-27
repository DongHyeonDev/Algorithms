//
//  12865.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/12865
//  알고리즘 분류: 다이나믹 프로그래밍, 배낭 문제

class BOJ12865: Solvable {
    // 메모리: 158696KB, 시간: 276ms, 코드 길이: 942B
    func run() {
        // 입력 받기
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()  // 물품의 수
        let k = fileIO.readInt()  // 배낭의 최대 무게

        var items: [(weight: Int, value: Int)] = []

        // 각 물품의 무게와 가치 입력
        for _ in 0..<n {
            let weight = fileIO.readInt()
            let value = fileIO.readInt()
            items.append((weight: weight, value: value))
        }

        // 동적 프로그래밍 배열 초기화
        // dp[i][w] = i번째 물품까지 고려했을 때, 무게 w 이하에서 얻을 수 있는 최대 가치
        var dp = Array(repeating: Array(repeating: 0, count: k + 1), count: n + 1)

        // 동적 프로그래밍으로 최대 가치 계산
        for i in 1...n {
            let currentWeight = items[i-1].weight
            let currentValue = items[i-1].value
            
            for w in 1...k {
                // 현재 물품을 넣을 수 없는 경우
                if currentWeight > w {
                    dp[i][w] = dp[i-1][w]
                }
                // 현재 물품을 넣을 수 있는 경우
                else {
                    // 넣지 않는 경우와 넣는 경우 중 최댓값 선택
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w-currentWeight] + currentValue)
                }
            }
        }

        // 최대 가치 출력
        print(dp[n][k])
    }
}
