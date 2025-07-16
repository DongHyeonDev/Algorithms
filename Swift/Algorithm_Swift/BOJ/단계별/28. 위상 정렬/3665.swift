//
//  3665.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/3665
//  알고리즘 분류: 그래프 이론, 방향 비순환 그래프, 위상 정렬

class BOJ3665: Solvable {
    // 메모리: 80712KB, 시간: 44ms, 코드 길이: 2604B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let T = fileIO.readInt()

        for _ in 0..<T {
            let n = fileIO.readInt()
            var lastYear = [Int](repeating: 0, count: n + 1)
            var position = [Int](repeating: 0, count: n + 1)
            
            // 작년 순위 입력
            for i in 1...n {
                lastYear[i] = fileIO.readInt()
                position[lastYear[i]] = i
            }
            
            // 그래프 초기화 (작년 순위를 기반으로)
            var graph = Array(repeating: Array(repeating: false, count: n + 1), count: n + 1)
            var indegree = [Int](repeating: 0, count: n + 1)
            
            // 작년 순위를 기반으로 그래프 구성
            for i in 1..<n {
                for j in (i+1)...n {
                    let higher = lastYear[i]
                    let lower = lastYear[j]
                    graph[higher][lower] = true
                    indegree[lower] += 1
                }
            }
            
            let m = fileIO.readInt()
            
            // 상대적 순위가 바뀐 쌍들 처리
            for _ in 0..<m {
                let a = fileIO.readInt()
                let b = fileIO.readInt()
                
                // 원래 a가 b보다 순위가 높았다면 (position[a] < position[b])
                if position[a] < position[b] {
                    // a -> b 간선을 제거하고 b -> a 간선을 추가
                    graph[a][b] = false
                    indegree[b] -= 1
                    graph[b][a] = true
                    indegree[a] += 1
                } else {
                    // b -> a 간선을 제거하고 a -> b 간선을 추가
                    graph[b][a] = false
                    indegree[a] -= 1
                    graph[a][b] = true
                    indegree[b] += 1
                }
            }
            
            // 위상 정렬
            var queue = [Int]()
            var result = [Int]()
            
            // 진입차수가 0인 노드를 큐에 추가
            for i in 1...n {
                if indegree[i] == 0 {
                    queue.append(i)
                }
            }
            
            var isImpossible = false
            var isAmbiguous = false
            
            while !queue.isEmpty {
                // 큐에 여러 개의 노드가 있으면 순위가 애매함
                if queue.count > 1 {
                    isAmbiguous = true
                }
                
                let current = queue.removeFirst()
                result.append(current)
                
                // 현재 노드와 연결된 모든 노드의 진입차수를 감소
                for next in 1...n {
                    if graph[current][next] {
                        indegree[next] -= 1
                        if indegree[next] == 0 {
                            queue.append(next)
                        }
                    }
                }
            }
            
            // 모든 노드를 방문하지 못했다면 사이클이 존재 (불가능)
            if result.count != n {
                isImpossible = true
            }
            
            if isImpossible {
                print("IMPOSSIBLE")
            } else if isAmbiguous {
                print("?")
            } else {
                print(result.map { String($0) }.joined(separator: " "))
            }
        }
    }
}
