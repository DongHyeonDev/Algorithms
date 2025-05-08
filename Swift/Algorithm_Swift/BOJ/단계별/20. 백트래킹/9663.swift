//
//  9663.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9663
//  알고리즘 분류: 브루트포스 알고리즘, 백트래킹

class BOJ9663: Solvable {
    // 메모리: 79508KB, 시간: 9620ms, 코드 길이: 1372B
    func run() {
        func solveNQueens(_ n: Int) -> Int {
            // 이미 놓인 퀸들의 위치를 저장하는 배열
            // queens[i] = j는 i번째 행의 j번째 열에 퀸이 위치한다는 의미
            var queens = [Int](repeating: -1, count: n)
            var count = 0
            
            // 특정 위치에 퀸을 놓을 수 있는지 검사하는 함수
            func isValid(_ row: Int, _ col: Int) -> Bool {
                for i in 0..<row {
                    // 같은 열에 있거나 대각선 상에 있는지 검사
                    if queens[i] == col || abs(queens[i] - col) == abs(i - row) {
                        return false
                    }
                }
                return true
            }
            
            // 백트래킹을 통해 퀸을 배치하는 함수
            func placeQueens(_ row: Int) {
                if row == n {
                    // n개의 퀸을 모두 배치했으면 경우의 수 증가
                    count += 1
                    return
                }
                
                // 현재 행의 각 열에 퀸을 놓아보기
                for col in 0..<n {
                    if isValid(row, col) {
                        queens[row] = col  // 퀸 배치
                        placeQueens(row + 1)  // 다음 행으로 진행
                        queens[row] = -1  // 백트래킹
                    }
                }
            }
            
            placeQueens(0)
            return count
        }

        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 결과 출력
            print(solveNQueens(n))
        }
    }
}
