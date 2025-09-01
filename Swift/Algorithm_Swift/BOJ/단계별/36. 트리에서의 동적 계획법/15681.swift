//
//  15681.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 9/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15681
//  알고리즘 분류: 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍

class BOJ15681: Solvable {
    // 메모리: 100496KB, 시간: 132ms, 코드 길이: 842B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let r = fileIO.readInt()
        let q = fileIO.readInt()
        var graph: [[Int]] = []
        var subtreeSize: [Int] = []

        // 트리 구성 및 서브트리 크기 계산
        func dfs(_ node: Int, _ parent: Int) {
            subtreeSize[node] = 1  // 자기 자신 포함
            
            for child in graph[node] {
                if child != parent {  // 부모가 아닌 연결된 노드들은 자식
                    dfs(child, node)
                    subtreeSize[node] += subtreeSize[child]
                }
            }
        }

        // 그래프 초기화
        graph = Array(repeating: [], count: n + 1)
        subtreeSize = Array(repeating: 0, count: n + 1)

        // 간선 정보 입력
        for _ in 0..<(n-1) {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }

        // 루트부터 DFS 수행하여 각 노드의 서브트리 크기 계산
        dfs(r, -1)

        // 쿼리 처리
        for _ in 0..<q {
            let u = fileIO.readInt()
            print(subtreeSize[u])
        }
    }
}
