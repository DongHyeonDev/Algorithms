//
//  10811.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10811
//  알고리즘 분류: 수학, 사칙연산

class BOJ10811: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 381B
    func run() {
        // 입력 받기
        if let firstLine = readLine() {
            let nm = firstLine.split(separator: " ").compactMap { Int($0) }
            let n = nm[0] // 바구니 개수
            let m = nm[1] // 명령의 개수
            
            // 초기 바구니 상태 (1번부터 N번까지)
            var baskets = Array(1...n)
            
            // M번 뒤집기 연산 수행
            for _ in 0..<m {
                if let commandLine = readLine() {
                    let command = commandLine.split(separator: " ").compactMap { Int($0) }
                    let i = command[0] - 1 // 배열 인덱스로 변환 (1-based -> 0-based)
                    let j = command[1] - 1 // 배열 인덱스로 변환
                    
                    // Swift 배열은 0번 인덱스부터 시작하므로 범위를 (i-1)..<j 로 설정
                    baskets[i...j].reverse()
                }
            }
            
            // 결과 출력
            print(baskets.map { String($0) }.joined(separator: " "))
        }
    }
}
