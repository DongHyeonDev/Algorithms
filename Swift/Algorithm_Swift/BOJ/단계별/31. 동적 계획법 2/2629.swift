//
//  2629.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2629
//  알고리즘 분류: 다이나믹 프로그래밍, 배낭 문제

class BOJ2629: Solvable {
    // 메모리: 79916KB, 시간: 16ms, 코드 길이: 803B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let weights = (0..<N).map { _ in fileIO.readInt() }
        let M = fileIO.readInt()
        let marbles = (0..<M).map { _ in fileIO.readInt() }

        let MAX = 15000
        var visited = Array(repeating: Array(repeating: false, count: MAX + 1), count: N + 1)

        func dfs(_ index: Int, _ diff: Int) {
            if visited[index][diff] { return }
            visited[index][diff] = true

            if index == N { return }

            let w = weights[index]
            dfs(index + 1, diff)           // 현재 추 사용 안함
            dfs(index + 1, diff + w)       // 오른쪽에 추가
            dfs(index + 1, abs(diff - w))  // 왼쪽에 추가
        }

        dfs(0, 0)

        for marble in marbles {
            if marble > MAX {
                print("N", terminator: " ")
            } else {
                print(visited[N][marble] ? "Y" : "N", terminator: " ")
            }
        }
    }
}
