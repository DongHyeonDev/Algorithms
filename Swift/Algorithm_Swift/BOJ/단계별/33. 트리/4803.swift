//
//  4803.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4803
//  알고리즘 분류: 자료 구조, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 분리 집합

class BOJ4803: Solvable {
    // 메모리: 82152KB, 시간: 44ms, 코드 길이: 2186B
    func run() {
        // Union-Find 자료구조
        class UnionFind {
            private var parent: [Int]
            private var rank: [Int]
            
            init(_ n: Int) {
                parent = Array(0..<n)
                rank = Array(repeating: 0, count: n)
            }
            
            func find(_ x: Int) -> Int {
                if parent[x] != x {
                    parent[x] = find(parent[x])
                }
                return parent[x]
            }
            
            func union(_ x: Int, _ y: Int) -> Bool {
                let rootX = find(x)
                let rootY = find(y)
                
                if rootX == rootY {
                    return false // 이미 같은 집합 (사이클 형성)
                }
                
                if rank[rootX] < rank[rootY] {
                    parent[rootX] = rootY
                } else if rank[rootX] > rank[rootY] {
                    parent[rootY] = rootX
                } else {
                    parent[rootY] = rootX
                    rank[rootX] += 1
                }
                
                return true
            }
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        var caseNumber = 1

        while true {
            let n = fileIO.readInt()
            let m = fileIO.readInt()
            
            if n == 0 && m == 0 {
                break
            }
            
            let uf = UnionFind(n + 1) // 1-indexed
            var hasCycle = Array(repeating: false, count: n + 1)
            var componentSize = Array(repeating: 0, count: n + 1)
            
            // 간선 처리
            for _ in 0..<m {
                let u = fileIO.readInt()
                let v = fileIO.readInt()
                
                if !uf.union(u, v) {
                    // 사이클 발견
                    let root = uf.find(u)
                    hasCycle[root] = true
                }
            }
            
            // 각 정점의 루트를 찾아 컴포넌트 크기 계산
            for i in 1...n {
                let root = uf.find(i)
                componentSize[root] += 1
            }
            
            // 트리 개수 세기
            var treeCount = 0
            
            for i in 1...n {
                if componentSize[i] > 0 {
                    let root = uf.find(i)
                    
                    // 트리 조건: 사이클이 없고, 연결되어 있어야 함
                    // 크기가 1인 컴포넌트도 트리로 간주 (단일 정점)
                    if !hasCycle[root] {
                        treeCount += 1
                    }
                }
            }
            
            // 결과 출력
            print("Case \(caseNumber): ", terminator: "")
            if treeCount == 0 {
                print("No trees.")
            } else if treeCount == 1 {
                print("There is one tree.")
            } else {
                print("A forest of \(treeCount) trees.")
            }
            
            caseNumber += 1
        }
    }
}
