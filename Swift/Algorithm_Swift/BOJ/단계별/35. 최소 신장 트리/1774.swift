//
//  1774.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1774
//  알고리즘 분류: 그래프 이론, 최소 스패닝 트리

class BOJ1774: Solvable {
    // 메모리: 98412KB, 시간: 148ms, 코드 길이: 993B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // 좌표 입력 (0번부터 n-1번까지)
        var points: [Point] = []
        for _ in 0..<n {
            let x = Double(fileIO.readInt())
            let y = Double(fileIO.readInt())
            points.append(Point(x: x, y: y))
        }

        // Union-Find 초기화 (0부터 n-1까지)
        let unionFind = UnionFind(n)

        // 이미 연결된 통로 처리
        for _ in 0..<m {
            let a = fileIO.readInt() - 1  // 1-indexed를 0-indexed로 변환
            let b = fileIO.readInt() - 1
            _ = unionFind.union(a, b)
        }

        // 모든 점 쌍 사이의 거리를 간선으로 생성
        var edges: [Edge] = []
        for i in 0..<n {
            for j in (i+1)..<n {
                let distance = points[i].distance(to: points[j])
                edges.append(Edge(i, j, distance))
            }
        }

        // 간선을 가중치(거리) 기준으로 오름차순 정렬
        edges.sort { $0.weight < $1.weight }

        // Kruskal 알고리즘으로 나머지 MST 구성
        var totalWeight = 0.0

        for edge in edges {
            if unionFind.union(edge.from, edge.to) {
                totalWeight += edge.weight
            }
        }

        // 소수점 둘째 자리까지 출력
        print(String(format: "%.2f", totalWeight))
    }
}
