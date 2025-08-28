//
//  1197.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1197
//  알고리즘 분류: 그래프 이론, 최소 스패닝 트리

class BOJ1197: Solvable {
    // 메모리: 84788KB, 시간: 48ms, 코드 길이: 1373B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let v = fileIO.readInt()  // 정점 수
        let e = fileIO.readInt()  // 간선 수

        // 간선 정보 입력
        var edges: [Edge] = []
        edges.reserveCapacity(e)

        for _ in 0..<e {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            let c = fileIO.readInt()
            edges.append(Edge(a, b, Double(c)))
        }

        // 간선을 가중치 기준으로 오름차순 정렬
        edges.sort { $0.weight < $1.weight }

        // Union-Find 초기화 (1부터 v까지)
        parent = Array(0...v)

        // Kruskal 알고리즘
        var mstWeight = 0
        var edgeCount = 0

        for edge in edges {
            if union(edge.from, edge.to) {
                mstWeight += Int(edge.weight)
                edgeCount += 1
                
                // MST는 정확히 V-1개의 간선을 가짐
                if edgeCount == v - 1 {
                    break
                }
            }
        }

        print(mstWeight)
    }
}
