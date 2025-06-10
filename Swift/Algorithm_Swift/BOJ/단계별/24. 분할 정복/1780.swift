//
//  1780.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1780
//  알고리즘 분류: 분할 정복, 재귀

class BOJ1780: Solvable {
    // 메모리: 130936KB, 시간: 416ms, 코드 길이: 988B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()
        var paper = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)
        for i in 0..<N {
            for j in 0..<N {
                paper[i][j] = fileIO.readInt()  // -1, 0, or 1
            }
        }

        // 카운터: idx 0→-1, 1→0, 2→1
        var counts = [0, 0, 0]

        func dfs(_ r: Int, _ c: Int, _ size: Int) {
            let first = paper[r][c]
            var same = true
            for i in r..<r+size {
                if !same { break }
                for j in c..<c+size {
                    if paper[i][j] != first {
                        same = false
                        break
                    }
                }
            }
            if same {
                // 색이 first인 정사각 종이 하나
                let idx = first + 1  // -1+1=0, 0+1=1, 1+1=2
                counts[idx] += 1
            } else {
                let s = size / 3
                for dr in 0..<3 {
                    for dc in 0..<3 {
                        dfs(r + dr*s, c + dc*s, s)
                    }
                }
            }
        }

        // 재귀 호출
        dfs(0, 0, N)

        // 결과 출력
        print(counts[0])
        print(counts[1])
        print(counts[2])
    }
}
