//
//  1956.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1956
//  알고리즘 분류: 그래프 이론, 최단 경로, 플로이드–워셜

class BOJ1956: Solvable {
    // 메모리: 83364KB, 시간: 460ms, 코드 길이: 1026B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let V = fileIO.readInt()    // 마을(정점) 개수
        let E = fileIO.readInt()    // 도로(간선) 개수

        // 무한대를 충분히 큰 값으로 정의
        let INF = Int(1e9)

        // 거리 배열 초기화: dist[i][j] = i→j 현재까지의 최단 거리
        // 0-based indexing을 쓰기 위해 크기를 V×V로 만들고, 모두 INF로 채운다.
        var dist = [[Int]](repeating: [Int](repeating: INF, count: V), count: V)

        // 간선 정보 입력: a→b 비용 c
        // 여러 개일 수 있으니 항상 최소값을 저장
        for _ in 0..<E {
            let a = fileIO.readInt() - 1
            let b = fileIO.readInt() - 1
            let c = fileIO.readInt()
            dist[a][b] = min(dist[a][b], c)
        }

        // Floyd–Warshall 수행
        // k = 거쳐가는 중간 정점
        for k in 0..<V {
            for i in 0..<V {
                // i→k 경로가 유효하지 않으면 건너뛰기
                if dist[i][k] == INF { continue }
                for j in 0..<V {
                    let viaK = dist[i][k] + dist[k][j]
                    if viaK < dist[i][j] {
                        dist[i][j] = viaK
                    }
                }
            }
        }

        // 자기 자신으로 돌아오는 최소 사이클 길이를 탐색
        var answer = INF
        for i in 0..<V {
            answer = min(answer, dist[i][i])
        }

        // 결과 출력
        print(answer == INF ? -1 : answer)
    }
}
