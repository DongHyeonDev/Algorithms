//
//  11657.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11657
//  알고리즘 분류: 그래프 이론, 최단 경로, 벨만–포드

import Foundation

class BOJ11657: Solvable {
    // 메모리: 79840KB, 시간: 64ms, 코드 길이: 932B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let M = fileIO.readInt()

        // 간선 리스트 입력
        var edges: [(u: Int, v: Int, w: Int)] = []
        edges.reserveCapacity(M)
        for _ in 0..<M {
            let A = fileIO.readInt()
            let B = fileIO.readInt()
            let C = fileIO.readInt()
            edges.append((A, B, C))
        }

        // 거리 배열 초기화
        let INF = Int(1e18)
        var dist = [Int](repeating: Int(INF), count: N + 1)
        dist[1] = 0

        // Bellman–Ford: N-1번 반복 완화
        for _ in 1..<N {
            for (u, v, w) in edges {
                if dist[u] < Int(INF), dist[v] > dist[u] + w {
                    dist[v] = dist[u] + w
                }
            }
        }

        // 음수 사이클 여부 검사: 한 번 더 완화 시도
        for (u, v, w) in edges {
            if dist[u] < Int(INF), dist[v] > dist[u] + w {
                // 음수 사이클이 존재 -> -1 출력 후 종료
                print(-1)
                exit(0)
            }
        }

        // 결과 출력
        // 1번 도시 제외한 2~N번 도시에 대해
        // 도달 불가능 INF -> -1, 아니면 dist
        for city in 2...N {
            let d = dist[city]
            print(d == Int(INF) ? -1 : d)
        }
    }
}
