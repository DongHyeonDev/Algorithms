//
//  24313.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24313
//  알고리즘 분류: 수학

class BOJ24313: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 532B
    func run() {
        // 입력 받기
        if let input1 = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           let c = Int(readLine() ?? "0"),
           let n0 = Int(readLine() ?? "0") {
            
            let a1 = input1[0]  // f(n)의 계수 (n의 계수)
            let a0 = input1[1]  // f(n)의 상수항

            var isBigO = true
            
            // O(n)의 정의를 만족하는지 확인
            for n in n0...100 {
                if a1 * n + a0 > c * n {
                    isBigO = false
                    break
                }
            }

            // 결과 출력
            print(isBigO ? 1 : 0)
        }
    }
}
