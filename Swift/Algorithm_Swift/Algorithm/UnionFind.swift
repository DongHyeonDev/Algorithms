//
//  UnionFind.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/28/25.
//

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
        
        if rootX == rootY { return false }
        
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
