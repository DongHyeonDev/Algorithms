//
//  2562.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2562
//  알고리즘 분류: 구현

class BOJ2562: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 438B
    func run() {
        // 입력 받기
        var numbers = [Int]()
        for _ in 1...9 {
            if let input = readLine(), let number = Int(input) {
                numbers.append(number)
            }
        }

        // 최댓값과 위치 계산
        if let maxValue = numbers.max() {
            if let maxIndex = numbers.firstIndex(of: maxValue) {
                // 최댓값 출력
                print(maxValue)
                // 최댓값 위치는 1부터 시작하므로 +1
                print(maxIndex + 1)
            }
        }
    }
}
