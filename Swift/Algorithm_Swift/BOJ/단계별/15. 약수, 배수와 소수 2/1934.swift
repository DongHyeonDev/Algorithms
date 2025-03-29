//
//  1934.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1934
//  알고리즘 분류: 수학, 정수론, 유클리드 호제법

class BOJ1934: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 602B
    func run() {
        // 최대공약수(GCD) 계산 (유클리드 호제법)
        func gcd(_ a: Int, _ b: Int) -> Int {
            var a = a, b = b
            while b != 0 {
                let r = a % b
                a = b
                b = r
            }
            return a
        }

        // 최소공배수(LCM) 계산
        func lcm(_ a: Int, _ b: Int) -> Int {
            return (a * b) / gcd(a, b)
        }

        // 입력 받기
        if let t = Int(readLine() ?? "") {
            for _ in 0..<t {
                if let line = readLine()?.split(separator: " ").compactMap({ Int($0) }), line.count == 2 {
                    let a = line[0]
                    let b = line[1]
                    print(lcm(a, b))
                }
            }
        }
    }
}
