//
//  9370.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9370
//  알고리즘 분류: 그래프 이론, 최단 경로, 데이크스트라

class BOJ9370: Solvable {
    // 메모리: 83424KB, 시간: 32ms, 코드 길이: 1124B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let T  = fileIO.readInt()
        var ans = [String]()

        for _ in 0..<T {
            let n = fileIO.readInt()
            let m = fileIO.readInt()
            let t = fileIO.readInt()
            let s = fileIO.readInt()
            let g = fileIO.readInt()
            let h = fileIO.readInt()

            // 그래프 구성: 기본 간선은 d*2, (g,h) 만 d*2−1
            var graph = Array(
                repeating: [(to: Int, weight: Int)](),
                count: n + 1
            )
            for _ in 0..<m {
                let a = fileIO.readInt(), b = fileIO.readInt(), d = fileIO.readInt()
                let w = ((a==g && b==h)||(a==h && b==g)) ? d*2 - 1 : d*2
                graph[a].append((b, w))
                graph[b].append((a, w))
            }

            // 후보지 읽고 정렬
            var candidates = [Int]()
            for _ in 0..<t { candidates.append(fileIO.readInt()) }
            candidates.sort()

            // 한 번의 다익스트라
            let dist = dijkstra(start: s, graph: graph, V: n)

            // 도달 가능(≠ INF)하면서 홀수 거리인 후보지만 골라서
            let INF = Int.max
            let filtered = candidates.filter {
                dist[$0] < INF && dist[$0] % 2 == 1
            }
            ans.append(filtered.map(String.init).joined(separator: " "))
        }

        print(ans.joined(separator: "\n"))
    }
}
