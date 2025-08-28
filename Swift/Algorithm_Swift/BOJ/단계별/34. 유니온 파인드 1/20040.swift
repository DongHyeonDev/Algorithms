//
//  20040.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/20040
//  알고리즘 분류: 자료 구조, 분리 집합

class BOJ20040: Solvable {
    // 메모리: 128988KB, 시간: 156ms, 코드 길이: 896B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // parent 배열 초기화 (0부터 n-1까지)
        parent = Array(0..<n)

        var cycleFound = false
        var cycleRound = 0

        for round in 1...m {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            
            if !cycleFound {
                if !union(u, v) {
                    // 사이클 발견
                    cycleFound = true
                    cycleRound = round
                }
            }
        }

        print(cycleFound ? cycleRound : 0)
    }
}
