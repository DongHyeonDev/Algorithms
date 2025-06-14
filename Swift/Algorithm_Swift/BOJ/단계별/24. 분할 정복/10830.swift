//
//  10830.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10830
//  알고리즘 분류: 수학, 분할 정복, 분할 정복을 이용한 거듭제곱, 선형대수학

class BOJ10830: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 1137B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let B = fileIO.readInt()

        // 입력받은 행렬 A (크기 N×N), 각 원소는 0..1000
        var A = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)
        for i in 0..<N {
            for j in 0..<N {
                A[i][j] = fileIO.readInt() % 1000
            }
        }

        // 두 행렬을 곱한 뒤 mod 1000
        func multiply(_ X: [[Int]], _ Y: [[Int]]) -> [[Int]] {
            var C = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)
            for i in 0..<N {
                for j in 0..<N {
                    var sum = 0
                    for k in 0..<N {
                        sum += X[i][k] * Y[k][j]
                    }
                    C[i][j] = sum % 1000
                }
            }
            return C
        }

        // 빠른 거듭제곱을 이용한 행렬 거듭제곱
        func matrixPower(_ base: [[Int]], _ e: Int) -> [[Int]] {
            if e == 1 { return base }
            let half = matrixPower(base, e / 2)
            let halfSq = multiply(half, half)
            return e % 2 == 0 ? halfSq : multiply(halfSq, base)
        }

        // A^B 계산
        let result = matrixPower(A, B)

        // 출력
        var out = ""
        for i in 0..<N {
            for j in 0..<N {
                out += "\(result[i][j])"
                if j < N-1 { out += " " }
            }
            out += "\n"
        }
        print(out, terminator: "")
    }
}
