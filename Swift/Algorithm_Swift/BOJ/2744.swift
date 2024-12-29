//
//  2744.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/28/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2744
//  알고리즘 분류: 구현, 문자열

class BOJ2744: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine(), input.count <= 100 {
            // 대소문자 변환
            let result = input.map { char -> Character in
                if char.isLowercase {
                    return Character(char.uppercased())
                } else if char.isUppercase {
                    return Character(char.lowercased())
                }
                return char
            }
            // 결과 출력
            print(String(result))
        } else {
            print("단어의 길이는 최대 100이어야 합니다.")
        }
    }
}
