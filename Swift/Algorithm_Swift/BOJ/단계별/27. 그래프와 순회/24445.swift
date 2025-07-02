//
//  24445.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24445
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 정렬, 너비 우선 탐색

class BOJ24445: Solvable {
    // 메모리: 92772KB, 시간: 172ms, 코드 길이: 1284B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()
        let r = fileIO.readInt()

        // 인접 리스트 생성
        var graph: [[Int]] = Array(repeating: [], count: n + 1)

        // 간선 정보 입력
        for _ in 0..<m {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }

        // 각 정점의 인접 리스트를 내림차순으로 정렬
        for i in 1...n {
            graph[i].sort(by: >)  // 내림차순 정렬
        }

        // 방문 순서를 저장할 배열 (0: 방문하지 않음)
        var visitOrder: [Int] = Array(repeating: 0, count: n + 1)
        var currentOrder = 1

        // BFS 함수
        func bfs(_ start: Int) {
            var queue: [Int] = []
            
            // 시작 정점 방문 처리
            visitOrder[start] = currentOrder
            currentOrder += 1
            queue.append(start)
            
            var queueIndex = 0  // 큐의 앞부분을 가리키는 인덱스 (dequeue 최적화)
            
            while queueIndex < queue.count {
                let current = queue[queueIndex]  // dequeue
                queueIndex += 1
                
                // 현재 정점의 인접 정점들을 내림차순으로 방문
                for nextVertex in graph[current] {
                    if visitOrder[nextVertex] == 0 {  // 방문하지 않은 경우
                        visitOrder[nextVertex] = currentOrder
                        currentOrder += 1
                        queue.append(nextVertex)  // enqueue
                    }
                }
            }
        }

        // 시작 정점에서 BFS 시작
        bfs(r)

        // 결과 출력
        for i in 1...n {
            print(visitOrder[i])
        }
    }
}
