//
//  24266.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24266
//  알고리즘 분류: 수학, 구현, 시뮬레이션

class BOJ24266: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 234B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            // 수행 횟수 계산 (삼중 반복문: n * n * n)
            let count = n * n * n
            print(count)
            print(3) // O(n^3)이므로 최고차항의 차수는 3
        }
    }
}
