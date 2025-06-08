//
//  2630.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2630
//  알고리즘 분류: 분할 정복, 재귀

class BOJ2630: Solvable {
    // 메모리: 79644KB, 시간: 12ms, 코드 길이: 1074B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력
        let N = fileIO.readInt()
        var paper = [[Int]](repeating: [Int](), count: N)
        for i in 0..<N {
            paper[i] = (0..<N).map { _ in fileIO.readInt() }
        }

        // 결과 카운터
        var whiteCount = 0
        var blueCount  = 0

        // 재귀 분할 함수
        func divideAndCount(_ r: Int, _ c: Int, _ size: Int) {
            // 현재 블록이 모두 같은 색인지 확인
            let first = paper[r][c]
            var same = true
            for i in r..<(r+size) {
                if !same { break }
                for j in c..<(c+size) {
                    if paper[i][j] != first {
                        same = false
                        break
                    }
                }
            }
            // 모두 같으면 카운트 후 종료
            if same {
                if first == 0 { whiteCount += 1 }
                else         { blueCount  += 1 }
                return
            }
            // 다르면 4분할
            let half = size / 2
            divideAndCount(r,        c,        half)
            divideAndCount(r,        c + half, half)
            divideAndCount(r + half, c,        half)
            divideAndCount(r + half, c + half, half)
        }

        // 전체 종이에 대해 재귀 호출
        divideAndCount(0, 0, N)

        // 출력
        print(whiteCount)
        print(blueCount)
    }
}
