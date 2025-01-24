//
//  11720.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11720
//  알고리즘 분류: 수학, 구현, 문자열

class BOJ11720: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 279B
    func run() {
        // 입력 받기
        if let nInput = readLine(), let _ = Int(nInput),
           let numbersInput = readLine() {
            // 각 숫자를 정수로 변환하여 합산
            let sum = numbersInput.compactMap { Int(String($0)) }.reduce(0, +)
            // 결과 출력
            print(sum)
        }
    }
}
