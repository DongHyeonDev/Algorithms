//
//  28065.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/1/26.
//

//  문제 링크: https://www.acmicpc.net/problem/28065
//  알고리즘 분류: 해 구성하기

class BOJ28065: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 404B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()

        // N, 1, N-1, 2, N-2, 3, ...
        var result = [Int]()
        result.reserveCapacity(N)
        var lo = 1, hi = N
        while lo <= hi {
            result.append(hi); hi -= 1
            if lo <= hi { result.append(lo); lo += 1 }
        }

        var output = ""
        output.reserveCapacity(N * 3)
        for i in 0..<N {
            if i > 0 { output += " " }
            output += "\(result[i])"
        }
        print(output)
    }
}
