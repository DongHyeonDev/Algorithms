//
//  2798.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2798
//  알고리즘 분류: 브루트포스 알고리즘

class BOJ2798: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 825B
    func run() {
        // 입력 받기
        if let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           let secondLine = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            
            let N = firstLine[0]  // 카드 개수
            let M = firstLine[1]  // 목표 값
            let cards = secondLine  // 카드 숫자 배열
            
            var maxSum = 0  // M 이하의 최대 합 저장

            // 3중 반복문을 이용한 완전 탐색 (브루트포스)
            for i in 0..<N-2 {
                for j in i+1..<N-1 {
                    for k in j+1..<N {
                        let sum = cards[i] + cards[j] + cards[k]
                        
                        if sum <= M && sum > maxSum {
                            maxSum = sum  // M을 넘지 않는 최대값 갱신
                        }
                    }
                }
            }

            // 결과 출력
            print(maxSum)
        }
    }
}
