//
//  1193.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1193
//  알고리즘 분류: 수학, 구현

class BOJ1193: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 327B
    func run() {
        // X 입력 받기
        if let X = Int(readLine() ?? "0") {
            var n = 1  // 대각선 번호
            var sum = 1  // 현재 대각선의 마지막 숫자 (1, 3, 6, 10, ...)
            
            // X가 속한 대각선 찾기
            while sum < X {
                n += 1
                sum += n
            }
            
            // X번째 분수 찾기
            let indexInDiagonal = X - (sum - n)  // 현재 대각선에서의 위치
            
            if n % 2 == 0 {  // 짝수 대각선 (왼쪽 아래에서 오른쪽 위로)
                print("\(indexInDiagonal)/\(n - indexInDiagonal + 1)")
            } else {  // 홀수 대각선 (오른쪽 위에서 왼쪽 아래로)
                print("\(n - indexInDiagonal + 1)/\(indexInDiagonal)")
            }
        }
    }
}
