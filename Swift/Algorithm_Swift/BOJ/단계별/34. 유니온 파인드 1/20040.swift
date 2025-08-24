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
        // Union-Find 자료구조
        var parent: [Int] = []

        @inline(__always) func find(_ x: Int) -> Int {
            if parent[x] != x {
                parent[x] = find(parent[x])
            }
            return parent[x]
        }

        @inline(__always) func union(_ x: Int, _ y: Int) -> Bool {
            let rootX = find(x)
            let rootY = find(y)
            
            if rootX == rootY {
                return false  // 이미 같은 집합 (사이클 생성)
            }
            
            parent[rootX] = rootY
            return true  // 성공적으로 합침
        }

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
