//
//  Edge.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/28/25.
//

// 간선 구조체
struct Edge {
    let from: Int
    let to: Int
    let weight: Double
    
    init(_ from: Int, _ to: Int, _ weight: Double) {
        self.from = from
        self.to = to
        self.weight = weight
    }
}
