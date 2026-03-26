//
//  15647.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/26/26.
//

//  문제 링크: https://www.acmicpc.net/problem/15647
//  알고리즘 분류: 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 트리에서의 다이나믹 프로그래밍, 트리에서의 전방향 다이나믹 프로그래밍

class BOJ15647: Solvable {
    // 메모리: 139088KB, 시간: 460ms, 코드 길이: 1466B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()

        var graph = [[(Int, Int)]](repeating: [], count: N + 1)
        for _ in 0..<(N - 1) {
            let u = fileIO.readInt(), v = fileIO.readInt(), d = fileIO.readInt()
            graph[u].append((v, d)); graph[v].append((u, d))
        }

        var par    = [Int](repeating: 0, count: N + 1)
        var parW   = [Int](repeating: 0, count: N + 1)
        var sz     = [Int](repeating: 1, count: N + 1)
        var down   = [Int64](repeating: 0, count: N + 1)
        var ans    = [Int64](repeating: 0, count: N + 1)
        var order  = [Int]()
        var visited = [Bool](repeating: false, count: N + 1)
        order.reserveCapacity(N)

        // BFS로 방문 순서 + 부모 설정
        var queue = [Int](repeating: 0, count: N + 1)
        var head = 0, tail = 0
        queue[tail] = 1; tail += 1; visited[1] = true

        while head < tail {
            let u = queue[head]; head += 1
            order.append(u)
            for (v, w) in graph[u] where !visited[v] {
                visited[v] = true; par[v] = u; parW[v] = w
                queue[tail] = v; tail += 1
            }
        }

        // 1단계: 역순으로 sz, down 계산 (리프 → 루트)
        for u in order.reversed() {
            for (c, w) in graph[u] where c != par[u] {
                sz[u] += sz[c]
                down[u] += down[c] + Int64(sz[c]) * Int64(w)
            }
        }

        // 2단계: 리루팅 (루트 → 자식)
        ans[1] = down[1]
        for u in order {
            for (c, w) in graph[u] where c != par[u] {
                ans[c] = ans[u] + Int64(N - 2 * sz[c]) * Int64(w)
            }
        }

        var output = ""
        output.reserveCapacity(N * 5)
        for i in 1...N { output += "\(ans[i])\n" }
        print(output, terminator: "")
    }
}
