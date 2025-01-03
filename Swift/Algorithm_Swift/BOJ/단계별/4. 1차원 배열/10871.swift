//
//  10871.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/22/24.
//

//  문제 링크: https://www.acmicpc.net/problem/10871
//  알고리즘 분류: 구현

class BOJ10871: Solvable {
    // 메모리: 80424KB, 시간: 12ms, 코드 길이: 954B
    func run() {
        // 입력 받기
        if let firstLine = readLine(), let secondLine = readLine() {
            // 첫 번째 줄: N과 X
            let firstNumbers = firstLine.split(separator: " ").compactMap { Int($0) }
            if firstNumbers.count == 2 {
                let n = firstNumbers[0]
                let x = firstNumbers[1]
                
                // 두 번째 줄: 수열 A
                let sequence = secondLine.split(separator: " ").compactMap { Int($0) }
                
                // 조건 확인: N개의 숫자, 수열 길이 일치 여부
                if sequence.count == n {
                    // X보다 작은 수 필터링
                    let result = sequence.filter { $0 < x }
                    // 결과 출력
                    print(result.map { String($0) }.joined(separator: " "))
                } else {
                    print("수열의 길이가 잘못되었습니다.")
                }
            } else {
                print("N과 X를 정확히 입력해주세요.")
            }
        } else {
            print("입력이 잘못되었습니다.")
        }
    }
}
