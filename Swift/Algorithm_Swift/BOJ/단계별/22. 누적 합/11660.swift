//
//  11660.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11660
//  알고리즘 분류: 다이나믹 프로그래밍, 누적 합

class BOJ11660: Solvable {
    // 메모리: 97824KB, 시간: 112ms, 코드 길이: 1257B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리: N(격자 크기)과 M(쿼리 수) 읽기
        let N = fileIO.readInt()
        let M = fileIO.readInt()

        // 원본 그리드 입력과 동시에 2D 누적합 배열을 계산하기 위해,
        // prefix[i][j] := (1,1)부터 (i,j)까지의 직사각형 구간 합
        // 배열 크기를 (N+1)x(N+1)로 만들어 1-based 인덱스를 편리하게 처리
        var prefix = [[Int]](repeating: [Int](repeating: 0, count: N + 1), count: N + 1)

        // 원본 값을 입력받으며 2D 누적합 초기화
        // prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + value[i][j]
        for i in 1...N {
            var rowSum = 0
            for j in 1...N {
                let value = fileIO.readInt()
                rowSum += value
                // 위쪽 누적합 + 현재 행의 누적 합 - 위 왼쪽 이중 중복 부분
                prefix[i][j] = prefix[i - 1][j] + rowSum
            }
        }

        // 쿼리 처리
        // 각 쿼리 (x1, y1, x2, y2)에 대해 2D 누적합으로 O(1)에 답을 구함:
        // 답 = prefix[x2][y2] - prefix[x1-1][y2]
        //        - prefix[x2][y1-1] + prefix[x1-1][y1-1]
        var output = [String]()
        output.reserveCapacity(M)

        for _ in 0..<M {
            let x1 = fileIO.readInt()
            let y1 = fileIO.readInt()
            let x2 = fileIO.readInt()
            let y2 = fileIO.readInt()

            let total = prefix[x2][y2]
                       - prefix[x1 - 1][y2]
                       - prefix[x2][y1 - 1]
                       + prefix[x1 - 1][y1 - 1]
            output.append(String(total))
        }

        // 결과 한 번에 출력
        print(output.joined(separator: "\n"))
    }
}
