//
//  2470.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2470
//  알고리즘 분류: 정렬, 이분 탐색, 두 포인터

class BOJ2470: Solvable {
    // 메모리: 81724KB, 시간: 20ms, 코드 길이: 704B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력
        let N = fileIO.readInt()
        var A = [Int]()
        A.reserveCapacity(N)
        for _ in 0..<N {
            A.append(fileIO.readInt())
        }

        // 정렬
        A.sort()

        // 두 포인터로 탐색
        var lo = 0
        var hi = N - 1
        var bestSum = Int.max     // 최적의 절댓값 합
        var ansLo = 0, ansHi = 0  // 최적 용액 두 개의 인덱스

        while lo < hi {
            let sum = A[lo] + A[hi]
            let absSum = abs(sum)
            if absSum < bestSum {
                bestSum = absSum
                ansLo = lo
                ansHi = hi
                if bestSum == 0 { break } // 더 이상 줄일 수 없다
            }
            // 합이 0보다 작으면 lo++
            if sum < 0 {
                lo += 1
            }
            // 합이 0보다 크면 hi--
            else {
                hi -= 1
            }
        }

        // 결과 출력 (오름차순 보장)
        print("\(A[ansLo]) \(A[ansHi])")
    }
}
