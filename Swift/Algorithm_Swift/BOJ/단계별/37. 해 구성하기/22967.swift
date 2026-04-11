//
//  22967.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/11/26.
//

//  문제 링크: https://www.acmicpc.net/problem/22967
//  알고리즘 분류: 그래프 이론, 애드 혹, 해 구성하기

class BOJ22967: Solvable {
    // 메모리: 79648KB, 시간: 8ms, 코드 길이: 1600B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()

        var graph = [[Int]](repeating: [], count: N + 1)
        var adj = [[Bool]](repeating: [Bool](repeating: false, count: N + 1), count: N + 1)

        for _ in 0..<(N - 1) {
            let u = io.readInt(), v = io.readInt()
            graph[u].append(v); graph[v].append(u)
            adj[u][v] = true; adj[v][u] = true
        }

        func bfs(src: Int) -> ([Int], [Int]) {
            var dist = [Int](repeating: -1, count: N + 1)
            var par  = [Int](repeating: -1, count: N + 1)
            var queue = [src]; var head = 0
            dist[src] = 0
            while head < queue.count {
                let u = queue[head]; head += 1
                for v in graph[u] where dist[v] == -1 {
                    dist[v] = dist[u] + 1; par[v] = u; queue.append(v)
                }
            }
            return (dist, par)
        }

        var newEdges = [(Int, Int)]()
        var diameter: Int

        if N <= 4 {
            // 완전 그래프: 지름 1
            diameter = 1
            for i in 1..<N {
                for j in (i+1)...N where !adj[i][j] {
                    newEdges.append((i, j))
                }
            }
        } else {
            // 트리 중심 찾기
            let (d1, _) = bfs(src: 1)
            let u = (1...N).max(by: { d1[$0] < d1[$1] })!
            let (d2, par2) = bfs(src: u)
            let v = (1...N).max(by: { d2[$0] < d2[$1] })!
            let D = d2[v]

            // u → v 경로 복원, 중심 선택
            var path = [Int]()
            var cur = v
            while cur != -1 { path.append(cur); cur = par2[cur] }
            let center = path[D / 2]

            diameter = 2
            for i in 1...N where i != center && !adj[i][center] {
                newEdges.append((i, center))
            }
        }

        var output = "\(newEdges.count)\n\(diameter)\n"
        for (a, b) in newEdges { output += "\(a) \(b)\n" }
        print(output, terminator: "")
    }
}
