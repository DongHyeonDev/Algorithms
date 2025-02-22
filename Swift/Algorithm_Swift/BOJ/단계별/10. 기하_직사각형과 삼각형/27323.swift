//
//  27323.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/27323
//  알고리즘 분류: 수학, 기하학, 사칙연산

class BOJ27323: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 178B
    func run() {
        // A, B 입력 받기
        if let A = Int(readLine() ?? "0"),
           let B = Int(readLine() ?? "0") {
            // 직사각형의 넓이 계산 후 출력
            print(A * B)
        }
    }
}
