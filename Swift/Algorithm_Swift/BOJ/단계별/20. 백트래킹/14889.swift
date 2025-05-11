//
//  14889.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14889
//  알고리즘 분류: 브루트포스 알고리즘, 백트래킹

class BOJ14889: Solvable {
    // 메모리: 79516KB, 시간: 244ms, 코드 길이: 1293B
    func run() {
        // 입력
        let N = Int(readLine()!)!
        var S = [[Int]](repeating: [], count: N)
        for i in 0..<N {
            S[i] = readLine()!.split(separator: " ").map { Int($0)! }
        }

        var used = [Bool](repeating: false, count: N)
        var answer = Int.max

        // 재귀: idx부터 조합 선택
        func dfs(_ idx: Int, _ selectedCount: Int) {
            // N/2명 다 골랐으면 두 팀 점수 계산
            if selectedCount == N/2 {
                var startSum = 0, linkSum = 0
                // i<j 쌍마다 같은 팀인지 보고 점수 누적
                for i in 0..<N {
                    for j in i+1..<N {
                        if used[i] && used[j] {
                            startSum += S[i][j] + S[j][i]
                        } else if !used[i] && !used[j] {
                            linkSum  += S[i][j] + S[j][i]
                        }
                    }
                }
                answer = min(answer, abs(startSum - linkSum))
                return
            }
            // 남은 원소가 부족하면 중단
            if idx == N { return }

            // 이 자리에 넣는 경우
            used[idx] = true
            dfs(idx + 1, selectedCount + 1)
            // 넣지 않는 경우
            used[idx] = false
            // 단, 남은 인원 중에서 아직 뽑아야 할 수만큼이 남아 있어야 함
            if N - (idx + 1) >= (N/2 - selectedCount) {
                dfs(idx + 1, selectedCount)
            }
        }

        dfs(0, 0)
        print(answer)
    }
}
