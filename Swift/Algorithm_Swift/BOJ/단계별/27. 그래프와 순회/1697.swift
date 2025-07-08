//
//  1697.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1697
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프

class BOJ1697: Solvable {
    // 메모리: 81664KB, 시간: 16ms, 코드 길이: 762B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()    // 수빈이 위치
        let K = fileIO.readInt()    // 동생 위치

        // BFS 준비
        let MAX = 100_000
        var dist = [Int](repeating: -1, count: MAX + 1)
        var queue = [Int]()
        var head = 0

        // 시작점
        dist[N] = 0
        queue.append(N)

        // BFS 수행
        while head < queue.count {
            let x = queue[head]; head += 1
            if x == K { break }  // 목표에 도달하면 종료
            let d = dist[x] + 1

            // 이동 후보: x-1, x+1, 2*x
            if x > 0, dist[x-1] == -1 {
                dist[x-1] = d
                queue.append(x-1)
            }
            if x < MAX, dist[x+1] == -1 {
                dist[x+1] = d
                queue.append(x+1)
            }
            let tx = x * 2
            if tx <= MAX, dist[tx] == -1 {
                dist[tx] = d
                queue.append(tx)
            }
        }

        // 결과 출력
        print(dist[K])
    }
}
