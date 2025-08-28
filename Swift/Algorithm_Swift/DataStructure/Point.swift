//
//  Point.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/28/25.
//

import Foundation

// 점 구조체
struct Point {
    let x: Double
    let y: Double
    
    // 두 점 사이의 유클리드 거리 계산
    func distance(to other: Point) -> Double {
        let dx = self.x - other.x
        let dy = self.y - other.y
        return sqrt(dx * dx + dy * dy)
    }
}
