//
//  11780.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11780
//  알고리즘 분류: 그래프 이론, 최단 경로, 플로이드–워셜, 역추적

class BOJ11780: Solvable {
    // 메모리: 81816KB, 시간: 52ms, 코드 길이: 1833B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        let INF = Int.max

        // 거리 배열과 경로 추적을 위한 next 배열 초기화
        var dist = Array(repeating: Array(repeating: INF, count: n + 1), count: n + 1)
        var next = Array(repeating: Array(repeating: -1, count: n + 1), count: n + 1)

        // 자기 자신으로 가는 거리는 0
        for i in 1...n {
            dist[i][i] = 0
        }

        // 간선 정보 입력
        for _ in 0..<m {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            let c = fileIO.readInt()
            
            // 같은 경로의 더 짧은 거리만 저장 (중복 간선 처리)
            if c < dist[a][b] {
                dist[a][b] = c
                next[a][b] = b
            }
        }

        // 플로이드-워셜 알고리즘
        for k in 1...n {
            for i in 1...n {
                for j in 1...n {
                    if dist[i][k] != INF && dist[k][j] != INF {
                        if dist[i][k] + dist[k][j] < dist[i][j] {
                            dist[i][j] = dist[i][k] + dist[k][j]
                            next[i][j] = next[i][k]
                        }
                    }
                }
            }
        }

        // 최단 거리 출력
        for i in 1...n {
            var result: [String] = []
            for j in 1...n {
                if dist[i][j] == INF {
                    result.append("0")
                } else {
                    result.append(String(dist[i][j]))
                }
            }
            print(result.joined(separator: " "))
        }

        // 경로 복원 함수
        func getPath(from start: Int, to end: Int) -> [Int] {
            if next[start][end] == -1 {
                return []  // 경로가 존재하지 않음
            }
            
            var path: [Int] = [start]
            var current = start
            
            while current != end {
                current = next[current][end]
                path.append(current)
            }
            
            return path
        }

        // 모든 쌍의 경로 출력
        for i in 1...n {
            for j in 1...n {
                if dist[i][j] == INF || i == j {
                    print("0")
                } else {
                    let path = getPath(from: i, to: j)
                    print("\(path.count) \(path.map { String($0) }.joined(separator: " "))")
                }
            }
        }
    }
}
