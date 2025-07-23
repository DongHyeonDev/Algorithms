//
//  11404.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11404
//  알고리즘 분류: 그래프 이론, 최단 경로, 플로이드–워셜

class BOJ11404: Solvable {
    // 메모리: 81812KB, 시간: 28ms, 코드 길이: 1126B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // INF 값을 충분히 크게 잡습니다.
        let INF = 1_000_000_000

        // 거리 행렬 초기화
        // dist[i][j] = i->j 최단 비용, i==j는 0, 나머지는 INF
        var dist = [[Int]](
            repeating: [Int](repeating: INF, count: n + 1),
            count: n + 1
        )
        for i in 1...n {
            dist[i][i] = 0
        }

        // 간선 정보 입력
        // 여러 간선이 있을 수 있기에 최솟값으로 저장
        for _ in 0..<m {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            let c = fileIO.readInt()
            if c < dist[a][b] {
                dist[a][b] = c
            }
        }

        // Floyd–Warshall 알고리즘 수행
        // 모든 k를 거쳐 i->j 경로를 완화
        for k in 1...n {
            for i in 1...n {
                // i->k가 INF면 건너뜀
                if dist[i][k] == INF { continue }
                for j in 1...n {
                    let via = dist[i][k] + dist[k][j]
                    if via < dist[i][j] {
                        dist[i][j] = via
                    }
                }
            }
        }

        // 결과 출력
        // i->j가 INF면 도달 불가능으로 0 출력
        var output = String()
        for i in 1...n {
            for j in 1...n {
                let cost = dist[i][j]
                output += (cost == INF ? "0" : "\(cost)")
                if j < n { output += " " }
            }
            output += "\n"
        }
        print(output)
    }
}
