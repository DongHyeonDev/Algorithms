//
//  11651.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11651
//  알고리즘 분류: 정렬

class BOJ11651: Solvable {
    // 메모리: 82644KB, 시간: 268ms, 코드 길이: 640B
    func run() {
        struct Point {
            let x: Int
            let y: Int
        }
        
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var points = [Point]()

            // 좌표 입력 받기
            for _ in 0..<n {
                if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                    points.append(Point(x: input[0], y: input[1]))
                }
            }

            // 정렬 (y좌표 오름차순, y좌표가 같으면 x좌표 오름차순)
            points.sort { $0.y < $1.y || ($0.y == $1.y && $0.x < $1.x) }

            // 결과 출력
            for point in points {
                print(point.x, point.y)
            }
        }
    }
}
