//
//  1260.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1260
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

class BOJ1260: Solvable {
    // 메모리: 79940KB, 시간: 12ms, 코드 길이: 1167B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let M = fileIO.readInt()
        let V = fileIO.readInt()

        // 1-based 인접 리스트
        var graph = [[Int]](repeating: [], count: N+1)
        for _ in 0..<M {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }
        // “번호가 작은 정점부터” 방문해야 하므로 오름차순 정렬
        for i in 1...N {
            graph[i].sort()
        }

        // 방문 기록
        var visitedDFS = [Bool](repeating: false, count: N+1)
        var dfsResult = [Int]()

        func dfs(_ u: Int) {
            visitedDFS[u] = true
            dfsResult.append(u)
            for w in graph[u] {
                if !visitedDFS[w] {
                    dfs(w)
                }
            }
        }

        // DFS 실행
        dfs(V)

        // BFS
        var visitedBFS = [Bool](repeating: false, count: N+1)
        var bfsResult = [Int]()
        var queue = [Int]()
        var qHead = 0

        // 시작점
        visitedBFS[V] = true
        queue.append(V)
        while qHead < queue.count {
            let u = queue[qHead]; qHead += 1
            bfsResult.append(u)
            for w in graph[u] {
                if !visitedBFS[w] {
                    visitedBFS[w] = true
                    queue.append(w)
                }
            }
        }

        // 출력
        print(dfsResult.map(String.init).joined(separator: " "))
        print(bfsResult.map(String.init).joined(separator: " "))
    }
}
