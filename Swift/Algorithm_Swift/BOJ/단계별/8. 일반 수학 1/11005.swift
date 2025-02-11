//
//  11005.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11005
//  알고리즘 분류: 수학, 구현

class BOJ11005: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 772B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " "),
           let N = Int(input[0]),
           let B = Int(input[1]) {

            var number = N
            var result = ""

            // 10진법 수를 B진법으로 변환
            while number > 0 {
                let remainder = number % B // B로 나눈 나머지
                let convertedChar: String

                if remainder < 10 {
                    convertedChar = String(remainder) // 0~9는 그대로 숫자
                } else {
                    let asciiValue = Character("A").asciiValue! + UInt8(remainder - 10)
                    convertedChar = String(UnicodeScalar(asciiValue))
                }

                result = convertedChar + result // 결과 문자열 앞에 추가
                number /= B // B로 나누기
            }

            // 결과 출력
            print(result)
        }
    }
}
