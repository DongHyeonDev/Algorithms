//
//  10986.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/31/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10986
//  알고리즘 분류: 수학, 누적 합

class BOJ10986: Solvable {
    // 메모리: 98640KB, 시간: 120ms, 코드 길이: 654B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()    // 수열의 길이 (1 ≤ N ≤ 1e6)
        let M = fileIO.readInt()    // 나누는 수 (2 ≤ M ≤ 1e3)

        // 모듈로 빈도 배열 및 초기값
        // freq[r] = 지금까지 누적합 % M == r 가 나온 횟수
        var freq = [Int](repeating: 0, count: M)
        var sumMod = 0
        freq[0] = 1  // 빈 구간(처음)도 하나의 누적합 0

        // 누적합 % M 계산 및 빈도 집계
        for _ in 0..<N {
            let a = fileIO.readInt()
            sumMod = (sumMod + (a % M)) % M
            freq[sumMod] += 1
        }

        // 동일한 모듈로가 나온 쌍의 수 계산
        // C(freq[r], 2) = freq[r] * (freq[r] - 1) / 2
        var answer: Int64 = 0
        for f in freq {
            if f >= 2 {
                answer += Int64(f) * Int64(f - 1) / 2
            }
        }

        // 결과 출력
        print(answer)
    }
}
