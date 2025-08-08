//
//  14003.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14003
//  알고리즘 분류: 이분 탐색, 역추적, 가장 긴 증가하는 부분 수열 문제

class BOJ14003: Solvable {
    // 메모리: 146592KB, 시간: 412ms, 코드 길이: 1323B
    func run() {
        // 이분 탐색으로 lower bound 찾기
        func lowerBound(_ arr: [Int], _ target: Int) -> Int {
            var left = 0
            var right = arr.count
            
            while left < right {
                let mid = (left + right) / 2
                if arr[mid] < target {
                    left = mid + 1
                } else {
                    right = mid
                }
            }
            
            return left
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        var A = [Int](repeating: 0, count: N)
        for i in 0..<N { A[i] = fileIO.readInt() }

        // tailsVal[len-1]: 길이가 len인 LIS의 최소 끝값
        // tailsIdx[len-1]: 그 끝값이 있는 원배열 인덱스
        var tailsVal = [Int]()
        var tailsIdx = [Int]()

        // prev[i]: LIS에서 A[i] 바로 앞 원소의 원배열 인덱스
        var prev = [Int](repeating: -1, count: N)

        for i in 0..<N {
            let x = A[i]
            let pos = lowerBound(tailsVal, x)
            if pos == tailsVal.count {
                tailsVal.append(x)
                tailsIdx.append(i)
            } else {
                tailsVal[pos] = x
                tailsIdx[pos] = i
            }
            if pos > 0 { prev[i] = tailsIdx[pos - 1] }
        }

        // 경로 복원
        let L = tailsVal.count
        var seq = [Int]()
        seq.reserveCapacity(L)
        var cur = tailsIdx[L - 1]
        while cur != -1 {
            seq.append(A[cur])
            cur = prev[cur]
        }
        seq.reverse()

        // 출력 (메모리 효율적으로)
        var out = String()
        out.reserveCapacity(L * 3)
        for i in 0..<L {
            if i > 0 { out.append(" ") }
            out.append(String(seq[i]))
        }
        print(L)
        print(out)
    }
}
