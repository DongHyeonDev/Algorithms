//
//  1967.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1967
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리의 지름

class BOJ1967: Solvable {
    // 메모리: 82284KB, 시간: 16ms, 코드 길이: 1372B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 인접 리스트로 트리 구성 (노드, 가중치)
        var graph = Array(repeating: [(Int, Int)](), count: n + 1)

        // 부모-자식-가중치 형태로 입력받아 양방향 그래프 구성
        for _ in 0..<n-1 {
            let parent = fileIO.readInt()
            let child = fileIO.readInt()
            let weight = fileIO.readInt()
            
            // 양방향 간선 추가
            graph[parent].append((child, weight))
            graph[child].append((parent, weight))
        }

        // DFS를 사용하여 특정 노드에서 가장 먼 노드와 거리를 찾는 함수
        func dfs(start: Int) -> (maxNode: Int, maxDistance: Int) {
            var visited = Array(repeating: false, count: n + 1)
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
