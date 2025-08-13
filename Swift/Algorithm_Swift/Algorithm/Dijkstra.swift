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
    
    // (거리, 정점) 튜플을 거리 기준으로 정렬하는 힙
    var heap = MinHeap<(Int, Int)> { $0.0 < $1.0 }
    heap.insert((0, start))
    
    while let (d, u) = heap.extractMin() {
        if d > dist[u] { continue }
        
        for (v, w) in graph[u] {
            let nd = d + w
            if nd < dist[v] {
                dist[v] = nd
                heap.insert((nd, v))
            }
        }
    }
    return dist
}
