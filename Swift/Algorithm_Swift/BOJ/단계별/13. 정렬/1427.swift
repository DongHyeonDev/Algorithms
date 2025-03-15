//
//  1427.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1427
//  알고리즘 분류: 문자열, 정렬

class BOJ1427: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 243B
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 문자열을 배열로 변환 후 내림차순 정렬
            let sortedNumber = input.sorted(by: >).map { String($0) }.joined()

            // 결과 출력
            print(sortedNumber)
        }
    }
}
