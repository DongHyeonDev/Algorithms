//
//  2447.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2447
//  알고리즘 분류: 분할 정복, 재귀

import Foundation

class BOJ2447: Solvable {
    // 메모리: 87388KB, 시간: 308ms, 코드 길이: 639B
    func run() {
        // (i, j) 위치가 빈 칸인지 판별하는 함수
        func isBlank(_ i: Int, _ j: Int) -> Bool {
            var x = i, y = j
            while x > 0 && y > 0 {
                if x % 3 == 1 && y % 3 == 1 {
                    return true
                }
                x /= 3
                y /= 3
            }
            return false
        }

        // 입력
        guard let line = readLine(),
              let N = Int(line) else {
            // 잘못된 입력 처리: 종료
            exit(0)
        }

        // 결과를 한 번에 모아서 출력 문자열 생성
        var output = ""
        for i in 0..<N {
            for j in 0..<N {
                output += isBlank(i, j) ? " " : "*"
            }
            output += "\n"
        }

        // 출력
        print(output, terminator: "")
    }
}
