//
//  3052.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/3052
//  알고리즘 분류: 수학, 사칙연산

class BOJ3052: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 381B
    func run() {
        // 나머지를 저장할 집합
        var remainders = Set<Int>()

        // 10개의 숫자 입력받기
        for _ in 0..<10 {
            if let input = readLine(), let number = Int(input) {
                // 42로 나눈 나머지를 집합에 추가
                remainders.insert(number % 42)
            }
        }

        // 집합에 있는 서로 다른 나머지 값의 개수를 출력
        print(remainders.count)
    }
}
