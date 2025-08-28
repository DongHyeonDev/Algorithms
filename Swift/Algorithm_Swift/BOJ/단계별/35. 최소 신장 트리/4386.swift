//
//  4386.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4386
//  알고리즘 분류: 그래프 이론, 최소 스패닝 트리

class BOJ4386: Solvable {
    // 메모리: 79916KB, 시간: 12ms, 코드 길이: 886B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 별의 좌표 입력
        var stars: [Point] = []
        for _ in 0..<n {
            let x = fileIO.readDouble()
            let y = fileIO.readDouble()
            stars.append(Point(x: x, y: y))
        }

        // 모든 점 쌍 사이의 거리를 간선으로 생성
        var edges: [Edge] = []
        for i in 0..<n {
            for j in (i+1)..<n {
                let distance = stars[i].distance(to: stars[j])
                edges.append(Edge(i, j, distance))
            }
        }

        // 간선을 가중치(거리) 기준으로 오름차순 정렬
        edges.sort { $0.weight < $1.weight }

        // Union-Find 초기화
        parent = Array(0..<n)

        // Kruskal 알고리즘으로 MST 구성
        var mstWeight = 0.0
        var edgeCount = 0

        for edge in edges {
            if union(edge.from, edge.to) {
                mstWeight += edge.weight
                edgeCount += 1
                
                // MST는 정확히 n-1개의 간선을 가짐
                if edgeCount == n - 1 {
                    break
                }
            }
        }

        // 소수점 둘째 자리까지 출력
        print(String(format: "%.2f", mstWeight))
    }
}
