//
//  3009.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/3009
//  알고리즘 분류: 구현, 기하학

class BOJ3009: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 643B
    func run() {
        // x, y 좌표를 저장할 배열
        var xCoords = [Int]()
        var yCoords = [Int]()

        // 3개의 점 입력 받기
        for _ in 0..<3 {
            if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                xCoords.append(input[0])
                yCoords.append(input[1])
            }
        }

        // x, y 좌표 중 하나만 존재하는 값을 찾기 (직사각형의 네 번째 점)
        let fourthX = xCoords[0] == xCoords[1] ? xCoords[2] : (xCoords[0] == xCoords[2] ? xCoords[1] : xCoords[0])
        let fourthY = yCoords[0] == yCoords[1] ? yCoords[2] : (yCoords[0] == yCoords[2] ? yCoords[1] : yCoords[0])

        // 결과 출력
        print(fourthX, fourthY)
    }
}
