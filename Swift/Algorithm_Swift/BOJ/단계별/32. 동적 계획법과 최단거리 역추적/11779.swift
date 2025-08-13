//
//  11779.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11779
//  알고리즘 분류: 그래프 이론, 최단 경로, 데이크스트라, 역추적

class BOJ11779: Solvable {
    // 메모리: 88440KB, 시간: 52ms, 코드 길이: 1404B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // 그래프 구성 (인접 리스트)
        var graph = Array(repeating: [(Int, Int)](), count: n + 1) // (목적지, 비용)

        for _ in 0..<m {
            let from = fileIO.readInt()
            let to = fileIO.readInt()
            let cost = fileIO.readInt()
            graph[from].append((to, cost))
        }

        let start = fileIO.readInt()
        let end = fileIO.readInt()

        // 다익스트라 알고리즘
        let INF = Int.max
        var dist = Array(repeating: INF, count: n + 1)
        var parent = Array(repeating: -1, count: n + 1)

        // (비용, 노드) 튜플을 비용 기준으로 정렬하는 힙 생성
        var heap = MinHeap<(Int, Int)> { $0.0 < $1.0 }

        dist[start] = 0
        heap.insert((0, start))

        while !heap.isEmpty {
            guard let (currentCost, currentNode) = heap.extractMin() else { break }
            
            // 이미 처리된 노드면 건너뛰기
            if currentCost > dist[currentNode] {
                continue
            }
            
            // 인접 노드들 확인
            for (nextNode, edgeCost) in graph[currentNode] {
                let newCost = currentCost + edgeCost
                
                if newCost < dist[nextNode] {
                    dist[nextNode] = newCost
                    parent[nextNode] = currentNode
                    heap.insert((newCost, nextNode))
                }
            }
        }

        // 결과 출력
        print(dist[end])

        // 경로 역추적
        var path: [Int] = []
        var current = end

        while current != -1 {
            path.append(current)
            current = parent[current]
        }

        path.reverse()

        print(path.count)
        print(path.map { String($0) }.joined(separator: " "))
    }
}
