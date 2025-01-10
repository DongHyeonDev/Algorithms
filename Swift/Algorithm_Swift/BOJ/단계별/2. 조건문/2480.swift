//
//  2480.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2480
//  알고리즘 분류: 수학, 구현, 사칙연산, 많은 조건 분기

class BOJ2480: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 779B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let dice = input.split(separator: " ").compactMap { Int($0) }
            
            if dice.count == 3 {
                let a = dice[0], b = dice[1], c = dice[2]
                
                // 상금 계산
                var prize = 0
                if a == b && b == c {
                    // 같은 눈 3개
                    prize = 10000 + a * 1000
                } else if a == b || a == c {
                    // 같은 눈 2개 (a와 b가 같거나 a와 c가 같음)
                    prize = 1000 + a * 100
                } else if b == c {
                    // 같은 눈 2개 (b와 c가 같음)
                    prize = 1000 + b * 100
                } else {
                    // 모두 다른 눈
                    prize = max(a, b, c) * 100
                }
                
                // 결과 출력
                print(prize)
            }
        }
    }
}
