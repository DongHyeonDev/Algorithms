//
//  2884.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2884
//  알고리즘 분류: 수학, 사칙연산

class BOJ2884: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 621B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let time = input.split(separator: " ").compactMap { Int($0) }
            if time.count == 2 {
                var hour = time[0]
                var minute = time[1]
                
                // 45분 일찍 설정
                minute -= 45
                
                // 분이 0보다 작을 경우 시간과 분 조정
                if minute < 0 {
                    minute += 60
                    hour -= 1
                }
                
                // 시간이 0보다 작을 경우 23시로 조정
                if hour < 0 {
                    hour = 23
                }
                
                // 결과 출력
                print("\(hour) \(minute)")
            }
        }
    }
}
