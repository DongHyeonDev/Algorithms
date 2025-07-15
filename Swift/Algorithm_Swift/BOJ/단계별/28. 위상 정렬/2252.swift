//
//  2252.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2252
//  알고리즘 분류: 그래프 이론, 방향 비순환 그래프, 위상 정렬

class BOJ2252: Solvable {
    // 메모리: 84520KB, 시간: 40ms, 코드 길이: 826B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt(), M = fileIO.readInt()

        // 그래프 및 진입차수 초기화
        var graph = Array(repeating: [Int](), count: N+1)
        var indegree = Array(repeating: 0, count: N+1)

        for _ in 0..<M {
            let a = fileIO.readInt(), b = fileIO.readInt()
            graph[a].append(b)
            indegree[b] += 1
        }

        // 진입차수 0인 노드를 큐에
        var queue = [Int]()
        for i in 1...N where indegree[i] == 0 {
            queue.append(i)
        }

        // Kahn의 위상 정렬
        var front = 0
        var order = [Int]()
        order.reserveCapacity(N)

        while front < queue.count {
            let u = queue[front]
            front += 1
            order.append(u)
            for v in graph[u] {
                indegree[v] -= 1
                if indegree[v] == 0 {
                    queue.append(v)
                }
            }
        }

        // 결과 출력
        print(order.map(String.init).joined(separator: " "))
    }
}
