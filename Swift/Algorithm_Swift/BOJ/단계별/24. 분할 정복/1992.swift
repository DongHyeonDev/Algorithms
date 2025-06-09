//
//  1992.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1992
//  알고리즘 분류: 분할 정복, 재귀

class BOJ1992: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 943B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()
        var grid = [[Character]](repeating: [], count: N)
        for i in 0..<N {
            grid[i] = Array(fileIO.readString())
        }

        // 쿼드트리 압축 재귀 함수
        var result = String()

        func quad(_ r: Int, _ c: Int, _ size: Int) {
            // 현재 블록의 첫 문자
            let first = grid[r][c]
            // 모두 같은지 검사
            var same = true
            for i in r..<r+size {
                if !same { break }
                for j in c..<c+size {
                    if grid[i][j] != first {
                        same = false
                        break
                    }
                }
            }
            // 같으면 한 문자로 압축
            if same {
                result.append(first)
            } else {
                // 다르면 4분할
                let half = size / 2
                result.append("(")
                quad(r,      c,      half)
                quad(r,      c+half, half)
                quad(r+half, c,      half)
                quad(r+half, c+half, half)
                result.append(")")
            }
        }

        // 실행
        quad(0, 0, N)

        // 결과 출력
        print(result)
    }
}
