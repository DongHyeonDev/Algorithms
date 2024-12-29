//
//  9498.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/15/24.
//


class BOJ9498: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 입력 문자열을 공백 기준으로 나누고 정수로 변환
            let score = input.split(separator: " ").compactMap { Int($0) }
            if score.count == 1 {
                let a = score[0]
                
                // 조건 확인: 0 < A, B < 10
                if a >= 0 && a <= 100 {
                    switch a {
                    case 90...100:
                        print("A")
                    case 80..<90:
                        print("B")
                    case 70..<80:
                        print("C")
                    case 60..<70:
                        print("D")
                    default:
                        print("F")
                    }
                } else {
                    print("입력 값은 0보다 크거나 같고 100보다 작거나 같은 정수여야 합니다.")
                }
            } else {
                print("한 개의 정수를 입력해주세요.")
            }
        } else {
            print("입력이 잘못되었습니다.")
        }
    }
}
