//
//  17472.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/31/25.
//

//  문제 링크: https://www.acmicpc.net/problem/17472
//  알고리즘 분류: 구현, 그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 최소 스패닝 트리

class BOJ17472: Solvable {
    // 메모리: 79524KB, 시간: 8ms, 코드 길이: 4181B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // 방향 벡터 (상, 하, 좌, 우)
        let dx = [-1, 1, 0, 0]
        let dy = [0, 0, -1, 1]

        // 지도 입력
        var grid = Array(repeating: Array(repeating: 0, count: m), count: n)
        for i in 0..<n {
            for j in 0..<m {
                grid[i][j] = fileIO.readInt()
            }
        }

        // 섬 번호 매기기 (DFS)
        var islandMap = Array(repeating: Array(repeating: -1, count: m), count: n)
        var islandCount = 0

        func dfs(_ x: Int, _ y: Int, _ islandId: Int) {
            if x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || islandMap[x][y] != -1 {
                return
            }
            
            islandMap[x][y] = islandId
            
            for i in 0..<4 {
                dfs(x + dx[i], y + dy[i], islandId)
            }
        }

        // 모든 섬 찾기
        for i in 0..<n {
            for j in 0..<m {
                if grid[i][j] == 1 && islandMap[i][j] == -1 {
                    dfs(i, j, islandCount)
                    islandCount += 1
                }
            }
        }

        if islandCount < 2 {
            print(-1)
        } else {
            // 섬 간의 최단 다리 찾기
            var minBridge = Array(repeating: Array(repeating: Int.max, count: islandCount), count: islandCount)
            
            // 가로 다리 찾기
            for i in 0..<n {
                var j = 0
                while j < m {
                    if grid[i][j] == 1 {
                        let island1 = islandMap[i][j]
                        
                        // 현재 섬의 끝까지 이동
                        while j < m && grid[i][j] == 1 {
                            j += 1
                        }
                        
                        // 바다 구간 시작
                        let bridgeStart = j
                        var bridgeLength = 0
                        
                        // 바다를 지나면서 다른 섬 찾기
                        while j < m && grid[i][j] == 0 {
                            bridgeLength += 1
                            j += 1
                        }
                        
                        // 다른 섬에 도달했고, 다리 길이가 2 이상인 경우
                        if j < m && grid[i][j] == 1 && bridgeLength >= 2 {
                            let island2 = islandMap[i][j]
                            if island1 != island2 {
                                minBridge[island1][island2] = min(minBridge[island1][island2], bridgeLength)
                                minBridge[island2][island1] = min(minBridge[island2][island1], bridgeLength)
                            }
                        }
                    } else {
                        j += 1
                    }
                }
            }
            
            // 세로 다리 찾기
            for j in 0..<m {
                var i = 0
                while i < n {
                    if grid[i][j] == 1 {
                        let island1 = islandMap[i][j]
                        
                        // 현재 섬의 끝까지 이동
                        while i < n && grid[i][j] == 1 {
                            i += 1
                        }
                        
                        // 바다 구간 시작
                        let bridgeStart = i
                        var bridgeLength = 0
                        
                        // 바다를 지나면서 다른 섬 찾기
                        while i < n && grid[i][j] == 0 {
                            bridgeLength += 1
                            i += 1
                        }
                        
                        // 다른 섬에 도달했고, 다리 길이가 2 이상인 경우
                        if i < n && grid[i][j] == 1 && bridgeLength >= 2 {
                            let island2 = islandMap[i][j]
                            if island1 != island2 {
                                minBridge[island1][island2] = min(minBridge[island1][island2], bridgeLength)
                                minBridge[island2][island1] = min(minBridge[island2][island1], bridgeLength)
                            }
                        }
                    } else {
                        i += 1
                    }
                }
            }
            
            // 간선 리스트 생성
            var edges: [Edge] = []
            for i in 0..<islandCount {
                for j in (i+1)..<islandCount {
                    if minBridge[i][j] != Int.max {
                        edges.append(Edge(i, j, Double(minBridge[i][j])))
                    }
                }
            }
            
            // Kruskal 알고리즘으로 MST 구성
            let unionFind = UnionFind(islandCount)
            edges.sort { $0.weight < $1.weight }
            
            var totalWeight = 0
            var edgeCount = 0
            
            for edge in edges {
                if unionFind.union(edge.from, edge.to) {
                    totalWeight += Int(edge.weight)
                    edgeCount += 1
                    if edgeCount == islandCount - 1 {
                        break
                    }
                }
            }
            
            // 모든 섬이 연결되었는지 확인
            if edgeCount == islandCount - 1 {
                print(totalWeight)
            } else {
                print(-1)
            }
        }
    }
}
