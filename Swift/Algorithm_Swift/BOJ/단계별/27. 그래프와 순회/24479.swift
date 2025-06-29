//
//  24479.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24479
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 정렬, 깊이 우선 탐색

class BOJ24479: Solvable {
    // 메모리: 96176KB, 시간: 176ms, 코드 길이: 872B
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
        
        // 각 정점의 인접 리스트를 오름차순으로 정렬
        for i in 1...n {
            graph[i].sort()
        }
        
        // 방문 순서를 저장할 배열 (0: 방문하지 않음)
        var visitOrder: [Int] = Array(repeating: 0, count: n + 1)
        var currentOrder = 1
        
        // DFS 함수
        func dfs(_ vertex: Int) {
            visitOrder[vertex] = currentOrder
            currentOrder += 1
            
            // 인접 정점들을 오름차순으로 방문 (이미 정렬됨)
            for nextVertex in graph[vertex] {
                if visitOrder[nextVertex] == 0 {  // 방문하지 않은 경우
                    dfs(nextVertex)
                }
            }
        }
        
        // 시작 정점에서 DFS 시작
        dfs(r)
        
        // 결과 출력
        for i in 1...n {
            print(visitOrder[i])
        }
    }
}
