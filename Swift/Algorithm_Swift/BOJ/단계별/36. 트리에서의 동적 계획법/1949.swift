//
//  1949.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 9/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1949
//  알고리즘 분류: 다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

class BOJ1949: Solvable {
    // 메모리: 82512KB, 시간: 20ms, 코드 길이: 3216B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        var n: Int = 0
        var population: [Int] = []
        var graph: [[Int]] = []
        var dp: [[Int]] = []

        // dp[node][0]: node를 선택하지 않았을 때의 최대값
        // dp[node][1]: node를 선택했을 때의 최대값

        func dfs(_ node: Int, _ parent: Int) {
            dp[node][0] = 0  // 현재 노드를 선택하지 않음
            dp[node][1] = population[node]  // 현재 노드를 선택함
            
            for child in graph[node] {
                if child != parent {
                    dfs(child, node)
                    
                    // 현재 노드를 선택하지 않으면, 자식은 선택할 수도 있고 안할 수도 있음
                    dp[node][0] += max(dp[child][0], dp[child][1])
                    
                    // 현재 노드를 선택하면, 자식은 선택할 수 없음 (인접 조건)
                    dp[node][1] += dp[child][0]
                }
            }
        }

        // 조건 3을 확인하는 함수: 선택되지 않은 마을이 적어도 하나의 우수 마을과 인접한지 확인
        func checkCondition3(_ node: Int, _ parent: Int, _ selected: [Bool]) -> Bool {
            var isValid = true
            
            // 현재 노드가 선택되지 않았다면, 인접한 노드 중 적어도 하나는 선택되어야 함
            if !selected[node] {
                var hasSelectedNeighbor = false
                for neighbor in graph[node] {
                    if selected[neighbor] {
                        hasSelectedNeighbor = true
                        break
                    }
                }
                if !hasSelectedNeighbor {
                    return false
                }
            }
            
            // 자식들에 대해서도 재귀적으로 확인
            for child in graph[node] {
                if child != parent {
                    if !checkCondition3(child, node, selected) {
                        isValid = false
                        break
                    }
                }
            }
            
            return isValid
        }

        // 최적해를 역추적하여 실제 선택된 노드들을 구하는 함수
        func backtrack(_ node: Int, _ parent: Int, _ mustSelect: Bool) -> [Bool] {
            var selected = Array(repeating: false, count: n + 1)
            
            func trace(_ node: Int, _ parent: Int, _ shouldSelect: Bool) {
                if shouldSelect || (dp[node][1] > dp[node][0]) {
                    selected[node] = true
                    // 현재 노드를 선택했으므로 자식들은 선택하지 않음
                    for child in graph[node] {
                        if child != parent {
                            trace(child, node, false)
                        }
                    }
                } else {
                    selected[node] = false
                    // 현재 노드를 선택하지 않았으므로 자식들 중 최적값을 선택
                    for child in graph[node] {
                        if child != parent {
                            trace(child, node, dp[child][1] > dp[child][0])
                        }
                    }
                }
            }
            
            trace(node, parent, mustSelect)
            return selected
        }

        // 입력 받기
        n = fileIO.readInt()

        population = Array(repeating: 0, count: n + 1)
        for i in 1...n {
            population[i] = fileIO.readInt()
        }

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

        // 루트를 선택하는 경우와 선택하지 않는 경우를 모두 확인
        let maxWithRoot = dp[1][1]
        let maxWithoutRoot = dp[1][0]

        var result = 0

        // 루트를 선택하는 경우
        let selectedWithRoot = backtrack(1, -1, true)
        if checkCondition3(1, -1, selectedWithRoot) {
            result = max(result, maxWithRoot)
        }

        // 루트를 선택하지 않는 경우
        let selectedWithoutRoot = backtrack(1, -1, false)
        if checkCondition3(1, -1, selectedWithoutRoot) {
            result = max(result, maxWithoutRoot)
        }

        print(result)
    }
}
