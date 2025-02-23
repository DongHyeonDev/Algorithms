//
//  1085.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1085
//  알고리즘 분류: 수학, 기하학

class BOJ1085: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 455B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            let x = input[0]  // 현재 x 좌표
            let y = input[1]  // 현재 y 좌표
            let w = input[2]  // 직사각형 가로 길이
            let h = input[3]  // 직사각형 세로 길이
            
            // 가장 가까운 경계선까지의 거리 계산
            let minDistance = min(x, y, w - x, h - y)
            
            // 결과 출력
            print(minDistance)
        }
    }
}
