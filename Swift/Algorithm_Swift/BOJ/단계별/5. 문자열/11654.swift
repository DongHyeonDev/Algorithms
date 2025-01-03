//
//  11654.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/26/24.
//

//  문제 링크: https://www.acmicpc.net/problem/11654
//  알고리즘 분류: 구현

class BOJ11654: Solvable {
    // 메모리: 79504KB, 시간: 8ms, 코드 길이: 299B
    func run() {
        // 입력 받기
        if let input = readLine(), input.count == 1 {
            if let asciiValue = input.first?.asciiValue {
                print(asciiValue)
            } else {
                print("올바른 문자 입력이 아닙니다.")
            }
        } else {
            print("한 개의 문자만 입력해주세요.")
        }
    }
}
