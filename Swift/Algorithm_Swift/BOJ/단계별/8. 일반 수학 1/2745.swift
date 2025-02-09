//
//  2745.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2745
//  알고리즘 분류: 수학, 구현, 문자열

import Foundation

class BOJ2745: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 880B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " "), let B = Int(input[1]) {
            let N = String(input[0]) // B진법 수 (문자열)
            
            var decimalValue = 0 // 변환된 10진법 값

            // 문자열의 각 자리수를 변환 (가장 오른쪽부터 순회)
            for (i, char) in N.reversed().enumerated() {
                let digitValue: Int

                if let num = char.wholeNumberValue { // 숫자인 경우
                    digitValue = num
                } else if let ascii = char.asciiValue {
                    digitValue = Int(ascii) - Int(Character("A").asciiValue ?? 65) + 10
                } else {
                    continue // 예외 처리 (잘못된 입력이 있으면 건너뜀)
                }

                // B진법 변환 (자리값 곱하기 B^i)
                decimalValue += digitValue * Int(pow(Double(B), Double(i)))
            }

            // 결과 출력
            print(decimalValue)
        }
    }
}
