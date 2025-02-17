//
//  2501.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2501
//  알고리즘 분류: 수학, 브루트포스 알고리즘

class BOJ2501: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 542B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            let N = input[0]  // 자연수 N
            let K = input[1]  // K번째 약수

            var divisors: [Int] = []  // 약수를 저장할 배열

            // 1부터 N까지 반복하여 약수 찾기
            for i in 1...N {
                if N % i == 0 { // 약수인지 확인
                    divisors.append(i)
                }
            }

            // K번째 약수 출력 (K가 약수 개수보다 크면 0 출력)
            print(K <= divisors.count ? divisors[K - 1] : 0)
        }
    }
}
