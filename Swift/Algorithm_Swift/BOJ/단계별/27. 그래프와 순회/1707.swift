//
//  1707.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1707
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 이분 그래프

class BOJ1707: Solvable {
    // 메모리: 100508KB, 시간: 184ms, 코드 길이: 1085B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let K = fileIO.readInt()

        for _ in 0..<K {
            let V = fileIO.readInt(), E = fileIO.readInt()
            // 인접 리스트
            var graph = Array(repeating: [Int](), count: V+1)
            for _ in 0..<E {
                let u = fileIO.readInt(), v = fileIO.readInt()
                graph[u].append(v)
                graph[v].append(u)
            }
            // 방문 및 색상: 0=미방문, 1 or -1 두 색으로 칠하기
            var color = Array(repeating: 0, count: V+1)
            var isBipartite = true

            // 모든 연결 컴포넌트 탐색
            for start in 1...V where color[start] == 0 && isBipartite {
                // BFS로 색칠
                var queue = [start]; color[start] = 1
                var head = 0
                while head < queue.count && isBipartite {
                    let u = queue[head]; head += 1
                    for v in graph[u] {
                        if color[v] == 0 {
                            color[v] = -color[u]
                            queue.append(v)
                        } else if color[v] == color[u] {
                            isBipartite = false
                            break
                        }
                    }
                }
            }

            print(isBipartite ? "YES" : "NO")
        }
    }
}
