//
//  1717.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1717
//  알고리즘 분류: 자료 구조, 분리 집합

class BOJ1717: Solvable {
    // 메모리: 97100KB, 시간: 48ms, 코드 길이: 949B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        let n = fileIO.readInt()
        let m = fileIO.readInt()

        var parent = [Int](repeating: 0, count: n + 1)
        var size   = [Int](repeating: 1, count: n + 1)
        for i in 0...n { parent[i] = i }

        func find(_ x0: Int) -> Int {
            var x = x0
            // path halving (반복형): 재귀 제거 + 두 칸씩 당겨 붙이기
            while parent[x] != x {
                parent[x] = parent[parent[x]]
                x = parent[x]
            }
            return x
        }

        func unite(_ a: Int, _ b: Int) {
            var ra = find(a), rb = find(b)
            if ra == rb { return }
            if size[ra] < size[rb] { swap(&ra, &rb) } // ra가 더 큰 집합
            parent[rb] = ra
            size[ra] += size[rb]
        }

        // 출력 버퍼 최적화
        var out = String()
        out.reserveCapacity(m * 4)

        for _ in 0..<m {
            let op = fileIO.readInt()
            let a  = fileIO.readInt()
            let b  = fileIO.readInt()
            if op == 0 {
                unite(a, b)
            } else {
                out += (find(a) == find(b) ? "YES\n" : "NO\n")
            }
        }
        print(out, terminator: "")
    }
}
