//
//  24263.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24263
//  알고리즘 분류: 구현, 시뮬레이션

class BOJ24263: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 201B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            // 수행 횟수 출력
            print(n) // 코드1은 n번 수행됨
            print(1) // O(n)이므로 최고차항의 차수는 1
        }
    }
}
