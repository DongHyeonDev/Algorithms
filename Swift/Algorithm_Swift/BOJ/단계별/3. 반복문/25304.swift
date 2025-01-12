//
//  25304.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25304
//  알고리즘 분류: 수학, 구현, 사칙연산

class BOJ25304: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 658B
    func run() {
        // 입력 받기
        if let totalInput = readLine(), let totalAmount = Int(totalInput),
           let nInput = readLine(), let n = Int(nInput) {
            var calculatedTotal = 0
            
            for _ in 0..<n {
                if let itemInput = readLine() {
                    let itemData = itemInput.split(separator: " ").compactMap { Int($0) }
                    if itemData.count == 2 {
                        let price = itemData[0]
                        let quantity = itemData[1]
                        calculatedTotal += price * quantity
                    }
                }
            }
            
            // 결과 확인
            if calculatedTotal == totalAmount {
                print("Yes")
            } else {
                print("No")
            }
        }
    }
}
