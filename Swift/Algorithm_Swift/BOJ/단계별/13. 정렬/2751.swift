//
//  2751.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2751
//  알고리즘 분류: 구현, 정렬

class BOJ2751: Solvable {
    // 메모리: 92000KB, 시간: 1136ms, 코드 길이: 335B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var numbers = [Int]()

            for _ in 0..<n {
                if let num = Int(readLine() ?? "0") {
                    numbers.append(num)
                }
            }

            // 정렬 (빠른 정렬 방법 사용)
            numbers.sort()

            // 결과 출력
            numbers.forEach { print($0) }
        }
    }
}
