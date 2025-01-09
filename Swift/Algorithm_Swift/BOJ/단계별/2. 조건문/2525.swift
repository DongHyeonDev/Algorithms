//
//  2525.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2525
//  알고리즘 분류: 수학, 사칙연산

class BOJ2525: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 680B
    func run() {
        // 입력 받기
        if let timeInput = readLine(), let cookingTimeInput = readLine() {
            let currentTime = timeInput.split(separator: " ").compactMap { Int($0) }
            let cookingTime = Int(cookingTimeInput) ?? 0
            
            if currentTime.count == 2 {
                var hours = currentTime[0]
                var minutes = currentTime[1]
                
                // 요리 시간을 현재 시각에 더하기
                minutes += cookingTime
                
                // 분 단위를 시간 단위로 변환
                hours += minutes / 60
                minutes %= 60
                
                // 24시간제 처리
                hours %= 24
                
                // 결과 출력
                print("\(hours) \(minutes)")
            }
        }
    }
}
