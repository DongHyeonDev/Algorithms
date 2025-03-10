//
//  10807.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/23/24.
//

//  문제 링크: https://www.acmicpc.net/problem/10807
//  알고리즘 분류: 구현

class BOJ10807: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 982B
    func run() {
        // 첫 번째 줄: 정수의 개수 N 입력 받기
        if let nInput = readLine(), let n = Int(nInput), n >= 1 && n <= 100 {
            // 두 번째 줄: N개의 정수 입력 받기
            if let arrayInput = readLine() {
                let numbers = arrayInput.split(separator: " ").compactMap { Int($0) }
                
                // 배열 길이 확인
                if numbers.count == n {
                    // 세 번째 줄: 찾으려는 정수 v 입력 받기
                    if let vInput = readLine(), let v = Int(vInput), v >= -100 && v <= 100 {
                        // v의 개수 세기
                        let count = numbers.filter { $0 == v }.count
                        print(count)
                    } else {
                        print("찾으려는 정수 v는 -100 이상 100 이하의 정수여야 합니다.")
                    }
                } else {
                    print("입력된 배열의 크기가 올바르지 않습니다.")
                }
            }
        } else {
            print("N은 1 이상 100 이하의 정수여야 합니다.")
        }
    }
}
