//
//  2743.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/27/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2743
//  알고리즘 분류: 구현, 문자열

class BOJ2743: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine(), input.count <= 100 {
            print(input.count)
        } else {
            print("단어의 길이는 최대 100이어야 합니다.")
        }
    }
}
