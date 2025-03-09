//
//  2750.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2750
//  알고리즘 분류: 구현, 정렬

class BOJ2750: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 422B
    func run() {
        // N 입력 받기
        if let input = readLine(), let N = Int(input) {
            var numbers = [Int]()
            
            // 숫자 입력 받기
            for _ in 0..<N {
                if let numInput = readLine(), let num = Int(numInput) {
                    numbers.append(num)
                }
            }
            
            // 오름차순 정렬
            numbers.sort()
            
            // 정렬된 숫자 출력
            for number in numbers {
                print(number)
            }
        }
    }
}
