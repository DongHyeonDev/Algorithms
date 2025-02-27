//
//  10101.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10101
//  알고리즘 분류: 구현, 기하학

class BOJ10101: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 654B
    func run() {
        // 삼각형의 세 각 입력 받기
        var angles = [Int]()
        for _ in 0..<3 {
            if let input = readLine(), let angle = Int(input) {
                angles.append(angle)
            }
        }

        // 세 각의 합 구하기
        let sum = angles[0] + angles[1] + angles[2]

        // 삼각형 종류 판별
        if sum != 180 {
            print("Error")
        } else if angles[0] == angles[1] && angles[1] == angles[2] {
            print("Equilateral")  // 세 각이 모두 60도인 경우
        } else if angles[0] == angles[1] || angles[1] == angles[2] || angles[0] == angles[2] {
            print("Isosceles")  // 두 각이 같은 경우
        } else {
            print("Scalene")  // 세 각이 모두 다른 경우
        }
    }
}
