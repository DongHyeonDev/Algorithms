//
//  10813.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10813
//  알고리즘 분류: 구현, 시뮬레이션

class BOJ10813: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 903B
    func run() {
        // 입력 받기
        if let firstLine = readLine() {
            let nm = firstLine.split(separator: " ").compactMap { Int($0) }
            let n = nm[0] // 바구니 개수
            let m = nm[1] // 공 교환 횟수

            // 초기 바구니 상태 (1번 바구니부터 N번 바구니까지 초기화)
            var baskets = Array(1...n)

            // M번의 공 교환 처리
            for _ in 0..<m {
                if let input = readLine() {
                    let swapCommand = input.split(separator: " ").compactMap { Int($0) }
                    let i = swapCommand[0] - 1 // 배열 인덱스로 변환
                    let j = swapCommand[1] - 1 // 배열 인덱스로 변환

                    // i번 바구니와 j번 바구니의 공 교환
                    let temp = baskets[i]
                    baskets[i] = baskets[j]
                    baskets[j] = temp
                }
            }

            // 결과 출력
            print(baskets.map { String($0) }.joined(separator: " "))
        }
    }
}
