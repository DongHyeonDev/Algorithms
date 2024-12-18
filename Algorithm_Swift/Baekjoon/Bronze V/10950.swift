//
//  10950.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/18/24.
//

import Foundation

// 입력 받기
if let tInput = readLine(), let t = Int(tInput) {
    // 테스트 케이스 수만큼 반복
    for _ in 0..<t {
        if let input = readLine() {
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            if numbers.count == 2 {
                let a = numbers[0]
                let b = numbers[1]
                
                // 조건 확인: 0 < A, B < 10
                if a > 0 && b > 0 && a < 10 && b < 10 {
                    print(a + b)
                }
            }
        }
    }
}
