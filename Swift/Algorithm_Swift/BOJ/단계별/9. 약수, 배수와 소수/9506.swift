//
//  9506.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9506
//  알고리즘 분류: 수학, 구현, 정수론

class BOJ9506: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 542B
    func run() {
        while let input = readLine(), let n = Int(input), n != -1 {
            var divisors: [Int] = []

            // 1부터 n/2까지 반복하여 약수 찾기 (자기 자신 제외)
            for i in 1...(n / 2) {
                if n % i == 0 {
                    divisors.append(i)
                }
            }

            // 약수들의 합 계산
            let sum = divisors.reduce(0, +)

            // 완전수 판별 및 출력
            if sum == n {
                print("\(n) = " + divisors.map { String($0) }.joined(separator: " + "))
            } else {
                print("\(n) is NOT perfect.")
            }
        }
    }
}
