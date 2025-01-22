//
//  10818.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10818
//  알고리즘 분류: 수학, 구현

class BOJ10818: Solvable {
    // 메모리: 144104KB, 시간: 364ms, 코드 길이: 346B
    func run() {
        // 입력 받기
        if let nInput = readLine(), let _ = Int(nInput), let numbersInput = readLine() {
            let numbers = numbersInput.split(separator: " ").compactMap { Int($0) }
            // 최솟값과 최댓값 계산
            if let minValue = numbers.min(), let maxValue = numbers.max() {
                print("\(minValue) \(maxValue)")
            }
        }
    }
}
