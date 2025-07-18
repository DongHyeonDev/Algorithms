//
//  1753.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1753
//  알고리즘 분류: 그래프 이론, 최단 경로, 데이크스트라

class BOJ1753: Solvable {
    // 메모리: 102520KB, 시간: 100ms, 코드 길이: 951B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let V = fileIO.readInt()
        let E = fileIO.readInt()
        let K = fileIO.readInt()

        // 그래프 구성
        var graph = [[(to: Int, weight: Int)]](repeating: [], count: V + 1)
        for _ in 0..<E {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            let w = fileIO.readInt()
            graph[u].append((v, w))
        }

        // 거리 배열 초기화
        let INF = Int.max
        var dist = [Int](repeating: INF, count: V + 1)
        dist[K] = 0

        // 우선순위 큐로 (거리, 정점) 관리
        var heap = MinHeap()
        heap.insert((0 << 16) | K)

        // 다익스트라
        while let key = heap.extractMin() {
            let d = key >> 16
            let u = key & 0xFFFF
            if d > dist[u] { continue }
            for (v, w) in graph[u] {
                let nd = d + w
                if nd < dist[v] {
                    dist[v] = nd
                    heap.insert((nd << 16) | v)
                }
            }
        }

        // 결과 출력
        for i in 1...V {
            if dist[i] == INF {
                print("INF")
            } else {
                print(dist[i])
            }
        }
    }
}
