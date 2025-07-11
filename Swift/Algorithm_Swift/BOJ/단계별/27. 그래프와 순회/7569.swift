//
//  7569.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/7569
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프

import Foundation

class BOJ7569: Solvable {
    // 메모리: 137352KB, 시간: 216ms, 코드 길이: 1620B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력
        let M = fileIO.readInt()   // 가로 칸 수
        let N = fileIO.readInt()   // 세로 칸 수
        let H = fileIO.readInt()   // 상자(높이) 수

        // 3차원 배열 box[h][i][j]: -1=빈칸, 0=안 익음, ≥1=익음(날짜 정보)
        var box = Array(
            repeating: Array(
                repeating: Array(repeating: 0, count: M),
                count: N
            ),
            count: H
        )

        var queue = [(h: Int, i: Int, j: Int)]()
        var head = 0

        for h in 0..<H {
            for i in 0..<N {
                for j in 0..<M {
                    let v = fileIO.readInt()
                    box[h][i][j] = v
                    if v == 1 {
                        // 익은 토마토는 BFS 시작점
                        queue.append((h,i,j))
                    }
                }
            }
        }

        // BFS (6방향)
        let dh = [ 0,  0,  0,  0,  1, -1]
        let di = [ 1, -1,  0,  0,  0,  0]
        let dj = [ 0,  0,  1, -1,  0,  0]

        var maxDay = 1

        while head < queue.count {
            let (h,i,j) = queue[head]; head += 1
            for d in 0..<6 {
                let nh = h + dh[d], ni = i + di[d], nj = j + dj[d]
                if nh >= 0 && nh < H && ni >= 0 && ni < N && nj >= 0 && nj < M {
                    if box[nh][ni][nj] == 0 {
                        // 안 익은 토마토가 익음: 날짜 +1 기록
                        box[nh][ni][nj] = box[h][i][j] + 1
                        maxDay = max(maxDay, box[nh][ni][nj])
                        queue.append((nh,ni,nj))
                    }
                }
            }
        }

        // 결과 판정
        for h in 0..<H {
            for i in 0..<N {
                for j in 0..<M {
                    if box[h][i][j] == 0 {
                        // 안 익은 토마토 남아 있으면 불가능
                        print(-1)
                        exit(0)
                    }
                }
            }
        }

        // 최초 익음 표시가 1이므로
        // 경과일 = (최대값) - 1, 모두 익어 있으면 0
        let result = maxDay > 1 ? maxDay - 1 : 0
        print(result)
    }
}
