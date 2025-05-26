//
//  9251.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9251
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ9251: Solvable {
    // 메모리: 79512KB, 시간: 28ms, 코드 길이: 676B
    func run() {
        // 빠른 입출력 준비
        let fileIO = RhynoFileIO()
        func readString() -> String { fileIO.readString() }

        // 입력 처리
        let S = readString()         // 첫 번째 문자열
        let T = readString()         // 두 번째 문자열
        let n = S.count, m = T.count
        let s = Array(S)             // 인덱스 접근 편의를 위해 배열로
        let t = Array(T)

        // DP 배열 초기화 (2행만 사용)
        var prev = [Int](repeating: 0, count: m + 1)
        var curr = [Int](repeating: 0, count: m + 1)

        // DP 전이
        for i in 1...n {
            for j in 1...m {
                if s[i-1] == t[j-1] {
                    curr[j] = prev[j-1] + 1
                } else {
                    curr[j] = max(prev[j], curr[j-1])
                }
            }
            // 다음 i에 대비해 행 스왑
            swap(&prev, &curr)
        }

        // 결과 출력
        print(prev[m])
    }
}
