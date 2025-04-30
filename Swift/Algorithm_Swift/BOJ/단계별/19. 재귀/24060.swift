//
//  24060.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24060
//  알고리즘 분류: 구현, 정렬, 재귀

import Foundation

class BOJ24060: Solvable {
    // 메모리: 117188KB, 시간: 540ms, 코드 길이: 1520B
    func run() {
        // 전역 변수
        var A: [Int] = []
        var tmp: [Int] = []
        var writeCount = 0
        var targetK = 0

        // merge 함수: A[p...q]와 A[q+1...r]를 병합
        func merge(_ p: Int, _ q: Int, _ r: Int) {
            var i = p
            var j = q + 1
            var t = 0

            // tmp에 정렬된 값을 담기
            while i <= q && j <= r {
                if A[i] <= A[j] {
                    tmp[t] = A[i]
                    i += 1
                } else {
                    tmp[t] = A[j]
                    j += 1
                }
                t += 1
            }
            while i <= q {
                tmp[t] = A[i]
                i += 1; t += 1
            }
            while j <= r {
                tmp[t] = A[j]
                j += 1; t += 1
            }

            // tmp에서 A로 복사하며 저장 횟수 카운트
            for k in 0..<t {
                A[p + k] = tmp[k]
                writeCount += 1
                if writeCount == targetK {
                    print(A[p + k])
                    exit(0)  // K번째 저장 시 즉시 종료
                }
            }
        }

        // merge sort
        func mergeSort(_ p: Int, _ r: Int) {
            if p < r {
                let q = (p + r) / 2
                mergeSort(p, q)
                mergeSort(q + 1, r)
                merge(p, q, r)
            }
        }

        // 입력 처리
        if let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           firstLine.count == 2 {
            let N = firstLine[0]
            targetK = firstLine[1]
            if let arr = readLine()?.split(separator: " ").compactMap({ Int($0) }), arr.count == N {
                A = arr
                tmp = Array(repeating: 0, count: N)
                // 정렬 수행
                mergeSort(0, N - 1)
                // 저장 횟수가 K 미만인 경우
                print(-1)
            }
        }
    }
}
