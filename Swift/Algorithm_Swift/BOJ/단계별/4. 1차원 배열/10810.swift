//
//  10810.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10810
//  알고리즘 분류: 구현, 시뮬레이션

class BOJ10810: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 844B
    func run() {
        // 입력 받기
        if let firstLine = readLine() {
            let nm = firstLine.split(separator: " ").compactMap { Int($0) }
            let n = nm[0] // 바구니 개수
            let m = nm[1] // 공을 넣는 횟수
            
            // 바구니 초기화
            var baskets = Array(repeating: 0, count: n)
            
            // M번의 공 넣기 처리
            for _ in 0..<m {
                if let input = readLine() {
                    let command = input.split(separator: " ").compactMap { Int($0) }
                    let i = command[0]
                    let j = command[1]
                    let k = command[2]
                    
                    // i번 바구니부터 j번 바구니까지 k번 공을 넣기
                    for index in (i-1)...(j-1) {
                        baskets[index] = k
                    }
                }
            }
            
            // 결과 출력
            print(baskets.map { String($0) }.joined(separator: " "))
        }
    }
}
