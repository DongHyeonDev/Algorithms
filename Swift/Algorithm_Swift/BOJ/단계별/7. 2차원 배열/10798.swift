//
//  10798.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10798
//  알고리즘 분류: 구현, 문자열

class BOJ10798: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 673B
    func run() {
        // 5줄의 입력을 저장할 2차원 배열 (최대 5×15 크기)
        var words: [[Character]] = Array(repeating: [], count: 5)

        // 입력 받기
        for i in 0..<5 {
            if let input = readLine() {
                words[i] = Array(input) // 문자열을 문자 배열로 변환하여 저장
            }
        }

        // 최대 길이를 저장하는 변수 (최대 15)
        let maxLength = words.map { $0.count }.max() ?? 0

        // 세로 읽기 출력
        var result = ""

        for col in 0..<maxLength {
            for row in 0..<5 {
                if col < words[row].count { // 현재 열(col)에 문자가 존재하는 경우만 추가
                    result.append(words[row][col])
                }
            }
        }

        print(result)
    }
}
