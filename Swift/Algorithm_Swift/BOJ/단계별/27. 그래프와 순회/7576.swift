//
//  7576.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/7576
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프

import Foundation

class BOJ7576: Solvable {
    // 메모리: 119360KB, 시간: 168ms, 코드 길이: 1230B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력
        let M = fileIO.readInt()   // 가로 칸 수
        let N = fileIO.readInt()   // 세로 칸 수

        // 상자 상태: -1=빈칸, 0=안 익음, 1=익음
        var box = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
        var queue = [(Int,Int)]()  // BFS용
        var head = 0

        for i in 0..<N {
            for j in 0..<M {
                let v = fileIO.readInt()
                box[i][j] = v
                if v == 1 {
                    // 이미 익은 토마토는 BFS의 시작점(날짜 0)
                    queue.append((i,j))
                }
            }
        }

        // BFS로 하루씩 익히기
        let dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        var days = 0

        while head < queue.count {
            let (x,y) = queue[head]; head += 1
            for (dx,dy) in dirs {
                let nx = x + dx, ny = y + dy
                if nx >= 0, nx < N, ny >= 0, ny < M, box[nx][ny] == 0 {
                    // 안 익은 토마토가 익음
                    box[nx][ny] = box[x][y] + 1
                    queue.append((nx,ny))
                    days = max(days, box[nx][ny])
                }
            }
        }

        // 결과 판단
        var answer = 0
        for i in 0..<N {
            for j in 0..<M {
                if box[i][j] == 0 {
                    // 아직 안 익은 게 남아 있으면 불가능
                    print(-1)
                    exit(0)
                }
                answer = max(answer, box[i][j])
            }
        }

        // 익은 토마토는 초기값 1이므로
        // 최대값(날짜 누적)에서 1을 빼면 실제 경과일
        print(answer > 1 ? answer - 1 : 0)
    }
}
