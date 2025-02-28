//
//  5073.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/5073
//  알고리즘 분류: 수학, 구현, 기하학

class BOJ5073: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 712B
    func run() {
        while let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            if input.count != 3 { continue } // 입력값이 3개가 아닐 경우 무시

            let a = input[0], b = input[1], c = input[2]

            // 종료 조건: "0 0 0"이 입력되면 반복 종료
            if a == 0, b == 0, c == 0 {
                break
            }

            // 삼각형의 조건: 가장 긴 변이 나머지 두 변의 합보다 작아야 함
            let sides = [a, b, c].sorted()
            if sides[2] >= sides[0] + sides[1] {
                print("Invalid")
            } else if a == b && b == c {
                print("Equilateral")
            } else if a == b || b == c || a == c {
                print("Isosceles")
            } else {
                print("Scalene")
            }
        }
    }
}
