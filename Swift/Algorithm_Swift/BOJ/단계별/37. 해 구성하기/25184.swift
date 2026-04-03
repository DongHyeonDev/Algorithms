//
//  25184.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/3/26.
//

//  문제 링크: https://www.acmicpc.net/problem/25184
//  알고리즘 분류: 해 구성하기

class BOJ25184: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 473B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()

        let half = N / 2
        var result = [Int]()
        result.reserveCapacity(N)

        // 큰 그룹(half+1..N)과 작은 그룹(1..half)을 번갈아 배치
        var lo = 1, hi = half + 1
        while hi <= N || lo <= half {
            if hi <= N { result.append(hi); hi += 1 }
            if lo <= half { result.append(lo); lo += 1 }
        }

        var output = ""
        output.reserveCapacity(N * 4)
        for i in 0..<N {
            if i > 0 { output += " " }
            output += "\(result[i])"
        }
        print(output)
    }
}
