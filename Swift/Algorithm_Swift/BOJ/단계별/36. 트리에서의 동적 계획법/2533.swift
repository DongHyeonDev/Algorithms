//
//  2533.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 9/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2533
//  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

class BOJ2533: Solvable {
    // 메모리: 240560KB, 시간: 984ms, 코드 길이: 1119B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        var n: Int = 0
        var graph: [[Int]] = []
        var dp: [[Int]] = []

        // dp[node][0]: node가 얼리 어답터가 아닐 때 node를 루트로 하는 서브트리의 최소 얼리 어답터 수
        // dp[node][1]: node가 얼리 어답터일 때 node를 루트로 하는 서브트리의 최소 얼리 어답터 수

        func dfs(_ node: Int, _ parent: Int) {
            dp[node][0] = 0  // 현재 노드가 얼리 어답터가 아님
            dp[node][1] = 1  // 현재 노드가 얼리 어답터임
            
            for child in graph[node] {
                if child != parent {
                    dfs(child, node)
                    
                    // 현재 노드가 얼리 어답터가 아니라면, 모든 자식은 얼리 어답터여야 함
                    dp[node][0] += dp[child][1]
                    
                    // 현재 노드가 얼리 어답터라면, 자식은 얼리 어답터여도 되고 아니어도 됨
                    dp[node][1] += min(dp[child][0], dp[child][1])
                }
            }
        }

        // 입력 받기
        n = fileIO.readInt()

        // 그래프 초기화
        graph = Array(repeating: [], count: n + 1)

        // 간선 정보 입력
        for _ in 0..<(n-1) {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }

        // DP 배열 초기화
        dp = Array(repeating: Array(repeating: 0, count: 2), count: n + 1)

        // 임의의 루트(1번 노드)에서 DFS 수행
        dfs(1, -1)

        // 루트가 얼리 어답터인 경우와 아닌 경우 중 최솟값
        print(min(dp[1][0], dp[1][1]))
    }
}
