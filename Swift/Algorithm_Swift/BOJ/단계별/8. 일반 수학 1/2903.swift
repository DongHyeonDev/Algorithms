//
//  2903.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2903
//  알고리즘 분류: 수학

class BOJ2903: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 364B
    func run() {
        // N 입력 받기
        if let N = Int(readLine() ?? "0") {
            // 초기 정사각형의 점 개수는 2x2 격자에서 시작 (점 4개)
            var points = 2
            
            // N번 반복하면서 점 개수 업데이트
            for _ in 1...N {
                points = points * 2 - 1
            }
            
            // 최종 점 개수 출력 (points^2)
            print(points * points)
        }
    }
}
