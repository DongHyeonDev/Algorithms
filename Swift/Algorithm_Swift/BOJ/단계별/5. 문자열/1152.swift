//
//  1152.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1152
//  알고리즘 분류: 구현, 문자열

class BOJ1152: Solvable {
    // 메모리: 105120KB, 시간: 76ms, 코드 길이: 223B
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 문자열을 공백으로 분리하여 배열로 변환
            let words = input.split(separator: " ")
            // 단어 개수 출력
            print(words.count)
        }
    }
}
