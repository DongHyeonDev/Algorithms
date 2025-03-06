//
//  19532.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/19532
//  알고리즘 분류: 수학, 브루트포스 알고리즘

import Foundation

class BOJ19532: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 485B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            let a = input[0], b = input[1], c = input[2]
            let d = input[3], e = input[4], f = input[5]

            // 연립 방정식 해 찾기
            for x in -999...999 {
                for y in -999...999 {
                    if a * x + b * y == c && d * x + e * y == f {
                        print(x, y)
                        exit(0) // 정답을 찾으면 프로그램 종료
                    }
                }
            }
        }
    }
}
