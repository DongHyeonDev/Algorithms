//
//  9063.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9063
//  알고리즘 분류: 수학, 구현, 기하학

class BOJ9063: Solvable {
    // 메모리: 79512KB, 시간: 68ms, 코드 길이: 699B
    func run() {
        // 점의 개수 입력
        if let n = Int(readLine() ?? "0"), n > 0 {
            var xMin = Int.max
            var xMax = Int.min
            var yMin = Int.max
            var yMax = Int.min
            
            // N개의 좌표 입력
            for _ in 0..<n {
                if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }), input.count == 2 {
                    let x = input[0]
                    let y = input[1]
                    
                    // 최소, 최대 x, y 좌표 갱신
                    xMin = min(xMin, x)
                    xMax = max(xMax, x)
                    yMin = min(yMin, y)
                    yMax = max(yMax, y)
                }
            }
            
            // 직사각형 넓이 계산
            let area = (xMax - xMin) * (yMax - yMin)
            print(area)
        }
    }
}
