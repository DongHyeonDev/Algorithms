//
//  1037.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1037
//  알고리즘 분류: 수학, 정수론

class BOJ1037: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 334B
    func run() {
        // 입력 처리
        if let line = readLine(), let count = Int(line),
           let parts = readLine()?.split(separator: " ").compactMap({ Int($0) }), parts.count == count {
            // 최소값과 최대값 찾기
            let mn = parts.min()!
            let mx = parts.max()!
            // N은 최소 약수 × 최대 약수
            print(mn * mx)
        }
    }
}
