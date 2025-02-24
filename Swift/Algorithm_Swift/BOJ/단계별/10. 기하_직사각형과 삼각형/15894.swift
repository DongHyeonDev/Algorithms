//
//  15894.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15894
//  알고리즘 분류: 수학, 사칙연산

class BOJ15894: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 154B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            // 정사각형 둘레 계산
            let perimeter = 4 * n
            print(perimeter)
        }
    }
}
