//
//  2740.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2740
//  알고리즘 분류: 수학, 구현, 선형대수학

class BOJ2740: Solvable {
    // 메모리: 79832KB, 시간: 12ms, 코드 길이: 856B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let M = fileIO.readInt()

        // 행렬 A 입력 (크기 N×M)
        var A = [[Int]](repeating: [Int](), count: N)
        for i in 0..<N {
            var row = [Int]()
            for _ in 0..<M {
                row.append(fileIO.readInt())
            }
            A[i] = row
        }

        let M2 = fileIO.readInt()  // M2 == M
        let K  = fileIO.readInt()

        // 행렬 B 입력 (크기 M×K)
        var B = [[Int]](repeating: [Int](), count: M2)
        for i in 0..<M2 {
            var row = [Int]()
            for _ in 0..<K {
                row.append(fileIO.readInt())
            }
            B[i] = row
        }

        // 결과 행렬 C 계산 (크기 N×K)
        var output = String()
        for i in 0..<N {
            for j in 0..<K {
                var sum = 0
                for t in 0..<M {
                    sum += A[i][t] * B[t][j]
                }
                output += "\(sum)"
                if j < K-1 { output += " " }
            }
            output += "\n"
        }

        // 결과 출력
        print(output, terminator: "")
    }
}
