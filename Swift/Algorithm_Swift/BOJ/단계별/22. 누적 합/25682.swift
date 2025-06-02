//
//  25682.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25682
//  알고리즘 분류: 누적 합

class BOJ25682: Solvable {
    // 메모리: 118832KB, 시간: 244ms, 코드 길이: 2053B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리: N행, M열, K를 읽음
        let N = fileIO.readInt()
        let M = fileIO.readInt()
        let K = fileIO.readInt()

        // 보드 입력: 1-based 편의를 위해 row 1..N, col 1..M 으로 저장
        // board[i][j]: 'W' 또는 'B' 에 대응하는 UInt8 값을 저장 ('W' = 87, 'B' = 66)
        var board = [[UInt8]](repeating: [UInt8](repeating: 0, count: M + 1), count: N + 1)
        for i in 1...N {
            // 문자열 전체를 한 번에 읽어서 [UInt8]으로 저장
            // 예: "WBWB" → [87,66,87,66]
            let rowBytes = fileIO.readByteSequenceWithoutSpaceAndLineFeed()
            for j in 1...M {
                board[i][j] = rowBytes[j - 1]
            }
        }

        // whiteError[i][j] 계산:
        // (i+j)%2 == 0 이면 기대 색 = 'W', else = 'B'.
        // 만약 board[i][j] != 기대색(white-start) 이면 1, 같으면 0
        //
        // whiteError 에 대해 2D prefixSum을 만든다.
        // prefix[i][j] = (1,1)부터 (i,j)까지의 whiteError 합
        var prefix = [[Int]](repeating: [Int](repeating: 0, count: M + 1), count: N + 1)

        for i in 1...N {
            var rowSum = 0
            for j in 1...M {
                // 기대 색이 'W'인지 'B'인지 확인
                let expected: UInt8 = ((i + j) & 1) == 0 ? UInt8(UInt8(ascii: "W")) : UInt8(UInt8(ascii: "B"))
                let isMismatch = (board[i][j] != expected) ? 1 : 0
                rowSum += isMismatch
                // 위(prefix[i-1][j]) + 현재 행 누적(rowSum)
                prefix[i][j] = prefix[i - 1][j] + rowSum
            }
        }

        // 모든 K×K 부분판을 검사하면서 최소로 칠해야 할 칸 수를 구함
        // 부분판 (r,c)부터 (r+K-1, c+K-1) 일 때 whiteMismatch =
        //   S = prefix[r+K-1][c+K-1]
        //     - prefix[r-1][c+K-1]
        //     - prefix[r+K-1][c-1]
        //     + prefix[r-1][c-1]
        // blackMismatch = K*K - whiteMismatch
        //
        // 두 값 중 작은 것을 정답 후보로 삼고, 최종적으로 최소값을 출력
        var answer = Int.max
        let area = K * K

        for r in 1...N - K + 1 {
            let r2 = r + K - 1
            for c in 1...M - K + 1 {
                let c2 = c + K - 1
                // 2D 누적합을 이용해 (r..r2, c..c2) 구간의 white-error 합
                let whiteMismatch = prefix[r2][c2]
                                  - prefix[r - 1][c2]
                                  - prefix[r2][c - 1]
                                  + prefix[r - 1][c - 1]
                let blackMismatch = area - whiteMismatch
                answer = min(answer, whiteMismatch, blackMismatch)
            }
        }

        // 결과 출력
        print(answer)
    }
}
