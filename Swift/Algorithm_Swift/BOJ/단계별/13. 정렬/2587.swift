//
//  2587.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2587
//  알고리즘 분류: 수학, 구현, 정렬, 사칙연산

class BOJ2587: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 347B
    func run() {
        var numbers = [Int]()

        // 5개의 자연수 입력 받기
        for _ in 0..<5 {
            if let numInput = readLine(), let num = Int(numInput) {
                numbers.append(num)
            }
        }

        // 평균 계산
        let average = numbers.reduce(0, +) / 5

        // 중앙값 계산
        let median = numbers.sorted()[2]

        // 결과 출력
        print(average)
        print(median)
    }
}
