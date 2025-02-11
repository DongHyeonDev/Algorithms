//
//  2720.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2720
//  알고리즘 분류: 수학, 그리디 알고리즘, 사칙연산

class BOJ2720: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 693B
    func run() {
        // 테스트 케이스 개수 입력
        if let T = Int(readLine() ?? "0") {
            let coins = [25, 10, 5, 1] // Quarter, Dime, Nickel, Penny

            // 각 테스트 케이스에 대해 실행
            for _ in 0..<T {
                if let C = Int(readLine() ?? "0") {
                    var change = C
                    var result: [Int] = []

                    // 각 동전 단위별 개수 계산
                    for coin in coins {
                        result.append(change / coin) // 해당 동전으로 거슬러 줄 개수
                        change %= coin // 남은 금액 업데이트
                    }

                    // 결과 출력
                    print(result.map { String($0) }.joined(separator: " "))
                }
            }
        }
    }
}
