//
//  24264.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24264
//  알고리즘 분류: 수학, 구현, 사칙연산, 시뮬레이션

class BOJ24264: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 223B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            // 수행 횟수 출력 (이중 반복문이므로 n^2번 수행됨)
            print(n * n)
            print(2) // O(n^2)이므로 최고차항의 차수는 2
        }
    }
}
