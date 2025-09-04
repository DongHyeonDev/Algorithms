//
//  2213.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 9/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2213
//  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍, 역추적

class BOJ2213: Solvable {
    // 메모리: 81360KB, 시간: 20ms, 코드 길이: 2160B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        var n: Int = 0
        var weight: [Int] = []
        var graph: [[Int]] = []
        var dp: [[Int]] = []

        // dp[node][0]: node를 선택하지 않았을 때의 최대 독립집합 크기
        // dp[node][1]: node를 선택했을 때의 최대 독립집합 크기

        func dfs(_ node: Int, _ parent: Int) {
            dp[node][0] = 0  // 현재 노드를 선택하지 않음
            dp[node][1] = weight[node]  // 현재 노드를 선택함
            
            for child in graph[node] {
                if child != parent {
                    dfs(child, node)
                    
                    // 현재 노드를 선택하지 않으면, 자식은 선택해도 되고 안해도 됨
                    dp[node][0] += max(dp[child][0], dp[child][1])
                    
                    // 현재 노드를 선택하면, 자식은 선택할 수 없음 (독립집합 조건)
                    dp[node][1] += dp[child][0]
                }
            }
        }

        // 역추적을 통해 실제 선택된 노드들을 구하는 함수
        func backtrack(_ node: Int, _ parent: Int, _ shouldSelect: Bool) -> [Int] {
            var result: [Int] = []
            
            if shouldSelect {
                result.append(node)
                // 현재 노드를 선택했으므로 자식들은 선택하지 않음
                for child in graph[node] {
                    if child != parent {
                        result.append(contentsOf: backtrack(child, node, false))
                    }
                }
            } else {
                // 현재 노드를 선택하지 않았으므로 자식들 중 최적값을 선택
                for child in graph[node] {
                    if child != parent {
                        let selectChild = dp[child][1] > dp[child][0]
                        result.append(contentsOf: backtrack(child, node, selectChild))
                    }
                }
            }
            
            return result
        }

        // 입력 받기
        n = fileIO.readInt()

        // 가중치 입력
        weight = Array(repeating: 0, count: n + 1)
        for i in 1...n {
            weight[i] = fileIO.readInt()
        }

        // 그래프 초기화
        graph = Array(repeating: [], count: n + 1)

        // 간선 정보 입력 (n-1개의 간선)
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

        // 최대 독립집합 크기 계산
        let maxSize = max(dp[1][0], dp[1][1])
        print(maxSize)

        // 역추적을 통해 실제 선택된 노드들 구하기
        let shouldSelectRoot = dp[1][1] > dp[1][0]
        var selectedNodes = backtrack(1, -1, shouldSelectRoot)

        // 오름차순 정렬
        selectedNodes.sort()

        // 출력
        print(selectedNodes.map { String($0) }.joined(separator: " "))
    }
}
