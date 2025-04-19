//
//  24723.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24723
//  알고리즘 분류: 수학, 사칙연산

class BOJ24723: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 296B
    func run() {
        // 입력 처리
        if let line = readLine(), let N = Int(line) {
            // 각 층마다 내려갈 때마다 선택지는 두 가지(왼쪽 또는 오른쪽)
            // 총 N개 층을 내려오므로 2^N 경로가 존재
            let result = 1 << N
            // 결과 출력
            print(result)
        }
    }
}
