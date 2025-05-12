//
//  24416.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24416
//  알고리즘 분류: 수학, 다이나믹 프로그래밍

class BOJ24416: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 930B
    func run() {
        // 피보나치 코드1의 정확한 실행 횟수를 계산하는 함수
        func calculateCode1Count(_ n: Int) -> Int {
            // 1부터 n까지의 피보나치 수를 재귀로 호출할 때 기저 조건(코드1)의 실행 횟수
            var count = [Int](repeating: 0, count: n + 1)
            
            // 기저 조건
            count[1] = 1
            count[2] = 1
            
            // n이 2보다 크면 점화식 적용
            for i in 3...n {
                count[i] = count[i-1] + count[i-2]
            }
            
            return count[n]
        }

        // 코드2의 실행 횟수를 계산하는 함수
        func calculateCode2Count(_ n: Int) -> Int {
            // 동적 프로그래밍에서 코드2는 n이 3 이상일 때 n-2번 실행
            return max(0, n - 2)
        }

        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            let code1Count = calculateCode1Count(n)
            let code2Count = calculateCode2Count(n)
            
            // 결과 출력
            print("\(code1Count) \(code2Count)")
        }
    }
}
