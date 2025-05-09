//
//  2580.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2580
//  알고리즘 분류: 백트래킹

class BOJ2580: Solvable {
    // 메모리: 79516KB, 시간: 584ms, 코드 길이: 1978B
    func run() {
        func solveSudoku(board: [[Int]]) -> [[Int]] {
            var board = board // 입력 보드를 복사하여 작업

            func isValid(_ row: Int, _ col: Int, _ num: Int) -> Bool {
                // 행 검사
                for i in 0..<9 {
                    if board[row][i] == num {
                        return false
                    }
                }

                // 열 검사
                for i in 0..<9 {
                    if board[i][col] == num {
                        return false
                    }
                }

                // 3x3 박스 검사
                let boxRowStart = row - row % 3
                let boxColStart = col - col % 3
                for i in 0..<3 {
                    for j in 0..<3 {
                        if board[boxRowStart + i][boxColStart + j] == num {
                            return false
                        }
                    }
                }

                return true
            }

            func backtrack() -> Bool {
                for row in 0..<9 {
                    for col in 0..<9 {
                        if board[row][col] == 0 {
                            for num in 1...9 {
                                if isValid(row, col, num) {
                                    board[row][col] = num

                                    if backtrack() {
                                        return true // 해를 찾았으면 true 반환
                                    } else {
                                        board[row][col] = 0 // 백트래킹: 현재 위치 초기화
                                    }
                                }
                            }
                            return false // 해당 위치에 어떤 숫자도 들어갈 수 없으면 false 반환
                        }
                    }
                }
                return true // 모든 칸이 채워졌으면 true 반환
            }

            _ = backtrack()
            return board
        }

        // 입력 읽기
        var board: [[Int]] = []
        for _ in 0..<9 {
            let line = readLine()!.split(separator: " ").map { Int($0)! }
            board.append(line)
        }

        // 스도쿠 풀기
        let solvedBoard = solveSudoku(board: board)

        // 출력
        for row in solvedBoard {
            print(row.map { String($0) }.joined(separator: " "))
        }
    }
}
