//
//  1167.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1167
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리의 지름

class BOJ1167: Solvable {
    // 메모리: 109124KB, 시간: 80ms, 코드 길이: 1358B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let v = fileIO.readInt()

        // 인접 리스트로 트리 구성 (노드, 가중치)
        var graph = Array(repeating: [(Int, Int)](), count: v + 1)

        for _ in 0..<v {
            let startNode = fileIO.readInt()
            
            while true {
                let node = fileIO.readInt()
                if node == -1 { break }
                
                let weight = fileIO.readInt()
                graph[startNode].append((node, weight))
            }
        }

        // DFS를 사용하여 특정 노드에서 가장 먼 노드와 거리를 찾는 함수
        func dfs(start: Int) -> (maxNode: Int, maxDistance: Int) {
            var visited = Array(repeating: false, count: v + 1)
            var maxDistance = 0
            var maxNode = start
            
            func dfsRecursive(node: Int, distance: Int) {
                visited[node] = true
                
                if distance > maxDistance {
                    maxDistance = distance
                    maxNode = node
                }
                
                for (nextNode, weight) in graph[node] {
                    if !visited[nextNode] {
                        dfsRecursive(node: nextNode, distance: distance + weight)
                    }
                }
            }
            
            dfsRecursive(node: start, distance: 0)
            return (maxNode, maxDistance)
        }

        // 1단계: 임의의 노드(1번)에서 가장 먼 노드 찾기
        let firstResult = dfs(start: 1)
        let farthestNode = firstResult.maxNode

        // 2단계: 가장 먼 노드에서 다시 가장 먼 노드까지의 거리 구하기 (이것이 지름)
        let secondResult = dfs(start: farthestNode)
        let diameter = secondResult.maxDistance

        print(diameter)
    }
}
