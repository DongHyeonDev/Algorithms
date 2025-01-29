//
//  5622.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/5622
//  알고리즘 분류: 수학, 구현

class BOJ5622: Solvable {
    // 메모리: 79504KB, 시간: 8ms, 코드 길이: 561B
    func run() {
        // 다이얼 숫자별 걸리는 시간 매핑
        let dialMap: [Character: Int] = [
            "A": 3, "B": 3, "C": 3,
            "D": 4, "E": 4, "F": 4,
            "G": 5, "H": 5, "I": 5,
            "J": 6, "K": 6, "L": 6,
            "M": 7, "N": 7, "O": 7,
            "P": 8, "Q": 8, "R": 8, "S": 8,
            "T": 9, "U": 9, "V": 9,
            "W": 10, "X": 10, "Y": 10, "Z": 10
        ]

        // 입력 받기
        if let input = readLine() {
            // 각 문자에 해당하는 다이얼 시간 합산
            let totalTime = input.reduce(0) { $0 + (dialMap[$1] ?? 0) }
            
            // 결과 출력
            print(totalTime)
        }
    }
}
