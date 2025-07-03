//
//  2606.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2606
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 정렬, 너비 우선 탐색

class BOJ2606: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 703B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()    // 컴퓨터 수 (1번부터 n번까지)
        let m = fileIO.readInt()    // 직접 연결된 쌍의 수

        // 1-based 인접 리스트 생성
        var graph = [[Int]](repeating: [], count: n + 1)
        for _ in 0..<m {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }

        // 방문 기록
        var visited = [Bool](repeating: false, count: n + 1)
        var infectedCount = 0

        // DFS 함수
        func dfs(_ u: Int) {
            visited[u] = true
            for v in graph[u] {
                if !visited[v] {
                    infectedCount += 1    // 1번 컴퓨터 이외의 새 감염 컴퓨터
                    dfs(v)
                }
            }
        }

        // 1번 컴퓨터부터 탐색 시작
        dfs(1)

        // 결과 출력: 1번을 제외하고 감염된 컴퓨터 수
        print(infectedCount)
    }
}
