//
//  1766.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1766
//  알고리즘 분류: 자료 구조, 그래프 이론, 우선순위 큐, 방향 비순환 그래프, 위상 정렬

class BOJ1766: Solvable {
    // 메모리: 84352KB, 시간: 56ms, 코드 길이: 957B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // 인접 리스트와 진입차수 배열 초기화
        var graph = Array(repeating: [Int](), count: n + 1)
        var indegree = Array(repeating: 0, count: n + 1)

        // 간선 정보 입력
        for _ in 0..<m {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            graph[a].append(b)
            indegree[b] += 1
        }

        // 우선순위 큐 (최소 힙) 초기화
        var heap = MinHeap()

        // 진입차수가 0인 노드들을 힙에 추가
        for i in 1...n {
            if indegree[i] == 0 {
                heap.insert(i)
            }
        }

        var result = [Int]()

        // 위상 정렬 수행
        while !heap.isEmpty {
            let current = heap.extractMin()!
            result.append(current)
            
            // 현재 노드와 연결된 모든 노드의 진입차수 감소
            for next in graph[current] {
                indegree[next] -= 1
                if indegree[next] == 0 {
                    heap.insert(next)
                }
            }
        }

        // 결과 출력
        print(result.map { String($0) }.joined(separator: " "))
    }
}
