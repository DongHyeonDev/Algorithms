//
//  1018.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1018
//  알고리즘 분류: 브루트포스 알고리즘

class BOJ1018: Solvable {
    // 메모리: 79516KB, 시간: 12ms, 코드 길이: 2292B
    func run() {
        // 입력 받기
        if let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           firstLine.count == 2 {
            
            let n = firstLine[0]  // 행의 개수
            let m = firstLine[1]  // 열의 개수
            
            // 보드 상태 입력 받기
            var board: [[Character]] = []
            for _ in 0..<n {
                if let line = readLine() {
                    board.append(Array(line))
                }
            }
            
            // 체스판 패턴 미리 생성 (체스판은 W로 시작하는 패턴과 B로 시작하는 패턴 두 가지)
            let chess1: [[Character]] = (0..<8).map { row in
                (0..<8).map { col in
                    (row + col) % 2 == 0 ? "W" : "B"
                }
            }
            
            let chess2: [[Character]] = (0..<8).map { row in
                (0..<8).map { col in
                    (row + col) % 2 == 0 ? "B" : "W"
                }
            }

            // 8x8 체스판으로 만들기 위해 다시 칠해야 하는 최소 개수 구하기
            func calculateMinRepaints() -> Int {
                var minRepaints = Int.max
                
                // 모든 가능한 8x8 영역 탐색
                for startRow in 0...(n-8) {
                    for startCol in 0...(m-8) {
                        // 첫 칸이 흰색(W)인 경우와 검은색(B)인 경우 두 가지 탐색
                        let repaintsWithWhiteStart = countRepaints(startRow: startRow, startCol: startCol, referenceBoard: chess1)
                        let repaintsWithBlackStart = countRepaints(startRow: startRow, startCol: startCol, referenceBoard: chess2)
                        
                        // 두 경우 중 작은 값 선택
                        let currentMinRepaints = min(repaintsWithWhiteStart, repaintsWithBlackStart)
                        minRepaints = min(minRepaints, currentMinRepaints)
                    }
                }
                
                return minRepaints
            }
            
            // 특정 위치에서 시작하는 8x8 체스판에서 다시 칠해야 하는 개수 계산
            func countRepaints(startRow: Int, startCol: Int, referenceBoard: [[Character]]) -> Int {
                var count = 0
                
                for i in 0..<8 {
                    for j in 0..<8 {
                        if board[startRow + i][startCol + j] != referenceBoard[i][j] {
                            count += 1
                        }
                    }
                }
                
                return count
            }
            
            // 결과 출력
            print(calculateMinRepaints())
        }
    }
}
