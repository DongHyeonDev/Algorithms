//
//  UnionFind.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/28/25.
//

// Union-Find 자료구조
var parent: [Int] = []

@inline(__always) func find(_ x: Int) -> Int {
    if parent[x] != x {
        parent[x] = find(parent[x])
    }
    return parent[x]
}

@inline(__always) func union(_ x: Int, _ y: Int) -> Bool {
    let rootX = find(x)
    let rootY = find(y)
    
    if rootX == rootY {
        return false  // 이미 같은 집합 (사이클 형성)
    }
    
    parent[rootX] = rootY
    return true  // 성공적으로 합침
}
