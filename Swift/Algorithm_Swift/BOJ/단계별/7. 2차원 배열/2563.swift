//
//  2563.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2563
//  알고리즘 분류: 구현

class BOJ2563: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 838B
    func run() {
        // 100x100 크기의 도화지 (false: 색종이가 안 붙은 상태)
        var paper = Array(repeating: Array(repeating: false, count: 100), count: 100)

        // 색종이 개수 입력
        if let n = Int(readLine() ?? "0") {
            for _ in 0..<n {
                if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                    let x = input[0]
                    let y = input[1]
                    
                    // 10x10 크기의 색종이를 도화지에 붙이기
                    for i in x..<x+10 {
                        for j in y..<y+10 {
                            paper[j][i] = true
                        }
                    }
                }
            }
        }

        // 검은색 영역(색종이가 붙은 칸) 개수 세기
        var blackArea = 0
        for i in 0..<100 {
            for j in 0..<100 {
                if paper[i][j] {
                    blackArea += 1
                }
            }
        }
        
        print(blackArea)
    }
}
