//
//  Kruskal.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/30/25.
//

// 크루스칼 알고리즘으로 MST 구하기
func kruskal(_ m: Int, _ edges: [Edge]) -> Int {
    let sortedEdges = edges.sorted { $0.weight < $1.weight }
    let unionFind = UnionFind(m)
    var mstWeight = 0
    var edgeCount = 0
    
    for edge in sortedEdges {
        if unionFind.union(edge.from, edge.to) {
            mstWeight += Int(edge.weight)
            edgeCount += 1
            if edgeCount == m - 1 { break }
        }
    }
    
    return mstWeight
}
