//
//  7562.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/7562
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 격자 그래프

class BOJ7562: Solvable {
    // 메모리: 83744KB, 시간: 52ms, 코드 길이: 1159B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 나이트의 8가지 이동
        let moves = [
            (-2,-1),(-2, 1),
            (-1,-2),(-1, 2),
            ( 1,-2),( 1, 2),
            ( 2,-1),( 2, 1),
        ]

        let T = fileIO.readInt()
        for _ in 0..<T {
            // 입력
            let l = fileIO.readInt()
            let startX = fileIO.readInt(), startY = fileIO.readInt()
            let targetX = fileIO.readInt(), targetY = fileIO.readInt()

            // 거리 배열 초기화 (-1 = 미방문)
            var dist = [[Int]](
                repeating: [Int](repeating: -1, count: l),
                count: l
            )

            // BFS 준비
            var queue = [(Int,Int)]()
            var head = 0

            dist[startX][startY] = 0
            queue.append((startX, startY))

            // BFS
            while head < queue.count {
                let (x,y) = queue[head]; head += 1
                let d = dist[x][y] + 1

                // 목표 도착 시 바로 종료
                if x == targetX && y == targetY {
                    break
                }

                // 8방향 탐색
                for (dx,dy) in moves {
                    let nx = x + dx, ny = y + dy
                    if nx >= 0, nx < l, ny >= 0, ny < l, dist[nx][ny] == -1 {
                        dist[nx][ny] = d
                        queue.append((nx,ny))
                    }
                }
            }

            // 결과 출력
            print(dist[targetX][targetY])
        }
    }
}
