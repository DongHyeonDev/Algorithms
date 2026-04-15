//
//  14601.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/15/26.
//

//  문제 링크: https://www.acmicpc.net/problem/14601
//  알고리즘 분류: 구현, 분할 정복, 재귀

class BOJ14601: Solvable {
    // 메모리: 79780KB, 시간: 16ms, 코드 길이: 1650B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let K = io.readInt()
        let x = io.readInt(), y = io.readInt()
        let size = 1 << K

        // grid[row][col]: row=0은 y=2^K(위), row=size-1은 y=1(아래)
        var grid = [[Int]](repeating: [Int](repeating: 0, count: size), count: size)
        var tileNum = 0

        let drainRow = size - y      // y좌표 → 행 인덱스
        let drainCol = x - 1        // x좌표 → 열 인덱스
        grid[drainRow][drainCol] = -1

        // (r,c): 블록 좌상단, sz: 블록 크기, (sr,sc): 특수 칸 위치
        func solve(_ r: Int, _ c: Int, _ sz: Int, _ sr: Int, _ sc: Int) {
            if sz == 1 { return }
            tileNum += 1
            let t = tileNum
            let half = sz / 2
            let mr = r + half  // 중앙 경계 행
            let mc = c + half  // 중앙 경계 열

            let inTop  = sr < mr
            let inLeft = sc < mc

            // 특수 칸이 없는 3개 사분면의 중앙 모서리에 타일 배치
            if !(inTop  && inLeft)  { grid[mr-1][mc-1] = t }  // TL 중앙
            if !(inTop  && !inLeft) { grid[mr-1][mc]   = t }  // TR 중앙
            if !(!inTop && inLeft)  { grid[mr][mc-1]   = t }  // BL 중앙
            if !(!inTop && !inLeft) { grid[mr][mc]     = t }  // BR 중앙

            // 4개 사분면 재귀
            // TL: 특수 칸이 TL이면 (sr,sc), 아니면 방금 놓은 타일 위치
            solve(r,  c,  half, inTop  && inLeft  ? sr : mr-1, inTop  && inLeft  ? sc : mc-1)
            solve(r,  mc, half, inTop  && !inLeft ? sr : mr-1, inTop  && !inLeft ? sc : mc  )
            solve(mr, c,  half, !inTop && inLeft  ? sr : mr,   !inTop && inLeft  ? sc : mc-1)
            solve(mr, mc, half, !inTop && !inLeft ? sr : mr,   !inTop && !inLeft ? sc : mc  )
        }

        solve(0, 0, size, drainRow, drainCol)

        var output = ""
        output.reserveCapacity(size * size * 4)
        for row in 0..<size {
            output += grid[row].map { String($0) }.joined(separator: " ")
            output += "\n"
        }
        print(output, terminator: "")
    }
}
