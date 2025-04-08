//
//  10773.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10773
//  알고리즘 분류: 구현, 자료 구조, 스택

class BOJ10773: Solvable {
    // 메모리: 81076KB, 시간: 48ms, 코드 길이: 614B
    func run() {
        // 입력받을 수를 저장할 스택
        var stack = [Int]()

        // 첫 줄에서 입력 개수 K를 안전하게 읽기
        if let kInput = readLine(), let k = Int(kInput) {
            for _ in 0..<k {
                if let line = readLine(), let num = Int(line) {
                    if num == 0 {
                        // 가장 최근의 수 제거
                        if !stack.isEmpty {
                            stack.removeLast()
                        }
                    } else {
                        // 수 추가
                        stack.append(num)
                    }
                }
            }
            // 결과 출력
            let sum = stack.reduce(0, +)
            print(sum)
        }
    }
}
