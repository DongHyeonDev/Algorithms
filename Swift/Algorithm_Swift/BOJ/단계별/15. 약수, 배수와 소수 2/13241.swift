//
//  13241.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/13241
//  알고리즘 분류: 수학, 정수론, 유클리드 호제법

class BOJ13241: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 591B
    func run() {
        // 최대공약수(GCD)를 구하는 함수 - 유클리드 호제법 사용
        func gcd(_ a: Int, _ b: Int) -> Int {
            var a = a, b = b
            while b != 0 {
                let r = a % b
                a = b
                b = r
            }
            return a
        }

        // 최소공배수(LCM) = (A * B) / GCD(A, B)
        func lcm(_ a: Int, _ b: Int) -> Int {
            return (a * b) / gcd(a, b)
        }

        // 입력 처리
        if let input = readLine() {
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            if numbers.count == 2 {
                let a = numbers[0]
                let b = numbers[1]
                print(lcm(a, b))
            }
        }
    }
}
