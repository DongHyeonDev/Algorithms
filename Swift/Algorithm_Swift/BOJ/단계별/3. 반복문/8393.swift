//
//  8393.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/8393
//  알고리즘 분류: 수학, 구현

class BOJ8393: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 411B
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 1부터 n까지 합 계산
            let sum = n * (n + 1) / 2
            // 결과 출력
            print(sum)
        }
    }
}
