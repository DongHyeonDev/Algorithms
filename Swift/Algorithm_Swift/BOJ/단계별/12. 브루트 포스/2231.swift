//
//  2231.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2231
//  알고리즘 분류: 브루트포스 알고리즘

class BOJ2231: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 556B
    func run() {
        // 입력 받기
        if let input = readLine(), let N = Int(input) {
            
            var result = 0  // 가장 작은 생성자 저장 변수
            
            // 가능한 최소 생성자는 (N - 9 * 자릿수) 부터 시작
            let start = max(1, N - String(N).count * 9)

            for num in start..<N {
                let sum = num + String(num).compactMap { $0.wholeNumberValue }.reduce(0, +)
                if sum == N {
                    result = num
                    break  // 가장 작은 생성자를 찾으면 종료
                }
            }

            // 결과 출력
            print(result)
        }
    }
}
