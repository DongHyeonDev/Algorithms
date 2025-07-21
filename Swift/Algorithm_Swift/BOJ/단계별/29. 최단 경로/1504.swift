//
//  1504.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1504
//  알고리즘 분류: 그래프 이론, 최단 경로, 데이크스트라

class BOJ1504: Solvable {
    // 메모리: 88724KB, 시간: 40ms, 코드 길이: 1768B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let E = fileIO.readInt()

        // 그래프 구성 (무향)
        var graph = [[(to: Int, weight: Int)]](repeating: [], count: N + 1)
        for _ in 0..<E {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            let c = fileIO.readInt()
            graph[a].append((b, c))
            graph[b].append((a, c))
        }

        // 반드시 거쳐야 할 두 정점
        let v1 = fileIO.readInt()
        let v2 = fileIO.readInt()

        // 세 번의 다익스트라: 1, v1, v2 출발
        let distFrom1  = dijkstra(start: 1,  graph: graph, V: N)
        let distFromV1 = dijkstra(start: v1, graph: graph, V: N)
        let distFromV2 = dijkstra(start: v2, graph: graph, V: N)

        // 두 경로 중 짧은 쪽 선택
        let INF = Int.max
        // 경로1: 1→v1→v2→N
        let path1 = distFrom1[v1] < INF && distFromV1[v2] < INF && distFromV2[N] < INF
                  ? distFrom1[v1] + distFromV1[v2] + distFromV2[N]
                  : INF
        // 경로2: 1→v2→v1→N
        let path2 = distFrom1[v2] < INF && distFromV2[v1] < INF && distFromV1[N] < INF
                  ? distFrom1[v2] + distFromV2[v1] + distFromV1[N]
                  : INF

        let ans = min(path1, path2)
        print(ans >= INF ? -1 : ans)
    }
}
