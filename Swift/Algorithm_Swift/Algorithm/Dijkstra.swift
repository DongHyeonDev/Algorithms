//
//  Dijkstra.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/21/25.
//

// 다익스트라 함수
func dijkstra(start: Int,
              graph: [[(to: Int, weight: Int)]],
              V: Int) -> [Int] {
    let INF = Int.max
    var dist = [Int](repeating: INF, count: V + 1)
    dist[start] = 0
    var heap = MinHeap()
    // (거리 << 16) | 정점
    heap.insert((0 << 16) | start)

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
    return dist
}
