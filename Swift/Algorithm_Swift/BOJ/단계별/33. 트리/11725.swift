//
//  11725.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11725
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 트리, 너비 우선 탐색, 깊이 우선 탐색

class BOJ11725: Solvable {
    // 메모리: 90588KB, 시간: 68ms, 코드 길이: 716B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()

        var graph = [[Int]](repeating: [], count: N + 1)
        for _ in 0..<(N - 1) {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }

        var parent = [Int](repeating: 0, count: N + 1)
        var queue = [Int](repeating: 0, count: N + 5)
        var head = 0, tail = 0

        parent[1] = 0
        queue[tail] = 1; tail += 1

        while head < tail {
            let u = queue[head]; head += 1
            for v in graph[u] {
                if parent[v] == 0 && v != 1 {
                    parent[v] = u
                    queue[tail] = v; tail += 1
                }
            }
        }

        var out = String()
        for i in 2...N {
            out += "\(parent[i])\n"
        }
        print(out, terminator: "")
    }
}
