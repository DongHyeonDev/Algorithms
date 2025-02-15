//
//  2869.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2869
//  알고리즘 분류: 수학

class BOJ2869: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 597B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            let A = input[0] // 낮에 올라가는 거리
            let B = input[1] // 밤에 미끄러지는 거리
            let V = input[2] // 목표 높이

            // 정상에 도달하기 전까지 하루 동안 실제 올라가는 거리
            let dailyClimb = A - B
            
            // 마지막 날에는 미끄러지지 않으므로 (V - A)를 dailyClimb로 나누고, 나머지가 있다면 하루 추가
            let days = (V - A + dailyClimb - 1) / dailyClimb + 1
            
            // 결과 출력
            print(days)
        }
    }
}
