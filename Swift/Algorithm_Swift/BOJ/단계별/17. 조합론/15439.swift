//
//  15439.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15439
//  알고리즘 분류: 수학, 구현, 조합론

class BOJ15439: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 243B
    func run() {
        // 입력 처리
        if let input = readLine(), let n = Int(input) {
            // 결과 계산 및 출력
            // 전체 조합 N×N에서 같은 색 조합 N개를 제외하면 N*(N-1)
            let result = n * (n - 1)
            print(result)
        }
    }
}
