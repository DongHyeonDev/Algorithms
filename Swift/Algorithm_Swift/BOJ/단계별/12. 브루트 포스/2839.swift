//
//  2839.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2839
//  알고리즘 분류: 수학, 다이나믹 프로그래밍, 그리디 알고리즘

import Foundation

class BOJ2839: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 550B
    func run() {
        // N 입력 받기
        if let input = readLine(), let N = Int(input) {
            var sugar = N
            var count = 0
            
            // 5kg 봉지를 최대한 많이 사용
            while sugar >= 0 {
                if sugar % 5 == 0 { // 5로 나누어 떨어지는 경우
                    count += sugar / 5 // 5kg 봉지 개수 추가
                    print(count)
                    exit(0)
                }
                sugar -= 3 // 5로 나누어 떨어지지 않으면 3kg 봉지 사용
                count += 1
            }
            
            // 정확하게 Nkg를 만들 수 없는 경우
            print(-1)
        }
    }
}
