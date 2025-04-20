//
//  11050.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11050
//  알고리즘 분류: 수학, 구현, 조합론

class BOJ11050: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 482B
    func run() {
        // 입력 처리
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }), input.count == 2 {
            let N = input[0]
            let K = input[1]
            
            // 이항 계수 계산 (K를 더 작은 쪽으로 선택해 계산량 절약)
            let k = min(K, N - K)
            var result = 1
            
            // C(N, k) = N×(N-1)×...×(N-k+1) / (1×2×...×k)
            for i in 0..<k {
                result = result * (N - i) / (i + 1)
            }
            
            // 결과 출력
            print(result)
        }
    }
}
