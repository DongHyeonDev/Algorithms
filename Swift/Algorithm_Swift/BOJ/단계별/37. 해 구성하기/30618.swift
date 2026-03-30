//
//  30618.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/30/26.
//

//  문제 링크: https://www.acmicpc.net/problem/30618
//  알고리즘 분류: 해 구성하기

class BOJ30618: Solvable {
    // 메모리: 86752KB, 시간: 64ms, 코드 길이: 508B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()

        // 각 위치의 계수 = i * (N - i + 1) (1-indexed)
        // 계수 내림차순으로 위치 정렬 후 큰 값 순서대로 배치
        var positions = Array(1...N)
        positions.sort { $0 * (N - $0 + 1) > $1 * (N - $1 + 1) }

        var result = [Int](repeating: 0, count: N + 1)
        for (idx, pos) in positions.enumerated() {
            result[pos] = N - idx  // 가장 큰 값부터 배치
        }

        var output = ""
        output.reserveCapacity(N * 3)
        for i in 1...N {
            if i > 1 { output += " " }
            output += "\(result[i])"
        }
        print(output)
    }
}
