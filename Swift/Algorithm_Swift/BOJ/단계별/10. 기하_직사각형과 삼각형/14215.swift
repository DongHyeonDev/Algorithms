//
//  14215.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14215
//  알고리즘 분류: 수학, 구현, 기하학

class BOJ14215: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 504B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            // 세 막대를 정렬 (오름차순)
            let sides = input.sorted()

            var a = sides[0], b = sides[1], c = sides[2]

            // 삼각형 성립 조건: 가장 긴 변(c)이 나머지 두 변(a, b)의 합보다 작아야 함
            while c >= a + b {
                c -= 1 // 가장 긴 변을 줄여 삼각형을 만들 수 있도록 조정
            }

            // 최대 둘레 출력
            print(a + b + c)
        }
    }
}
