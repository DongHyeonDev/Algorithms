//
//  11054.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11054
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ11054: Solvable {
    // 메모리: 79512KB, 시간: 16ms, 코드 길이: 859B
    func run() {
        // 빠른 입출력을 위한 File I/O
        let fileIO = RhynoFileIO()

        // 입력 처리
        let n = fileIO.readInt()
        var A = [Int](repeating: 0, count: n)
        for i in 0..<n {
            A[i] = fileIO.readInt()
        }

        // DP 배열 준비
        // lis[i]: A[0...i] 중 A[i]를 끝으로 하는 최장 증가 부분수열 길이
        // lds[i]: A[i...n-1] 중 A[i]를 시작으로 하는 최장 감소 부분수열 길이
        var lis = [Int](repeating: 1, count: n)
        var lds = [Int](repeating: 1, count: n)

        // lis 계산 (왼쪽에서 오른쪽으로)
        for i in 0..<n {
            for j in 0..<i {
                if A[j] < A[i] && lis[j] + 1 > lis[i] {
                    lis[i] = lis[j] + 1
                }
            }
        }

        // lds 계산 (오른쪽에서 왼쪽으로)
        for i in (0..<n).reversed() {
            for j in (i+1)..<n {
                if A[j] < A[i] && lds[j] + 1 > lds[i] {
                    lds[i] = lds[j] + 1
                }
            }
        }

        // 답 계산: lis[i] + lds[i] - 1 의 최대값
        var answer = 0
        for i in 0..<n {
            answer = max(answer, lis[i] + lds[i] - 1)
        }

        // 결과 출력
        print(answer)
    }
}
