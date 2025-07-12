//
//  16928.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/16928
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색

class BOJ16928: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 867B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력
        let N = fileIO.readInt()   // 사다리 개수
        let M = fileIO.readInt()   // 뱀 개수

        // 1~100 칸마다 점프(사다리/뱀) 매핑: 딕셔너리로 저장
        var jump = [Int:Int]()
        for _ in 0..<N+M {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            jump[u] = v
        }

        // BFS 세팅
        var dist = Array(repeating: -1, count: 101)
        var queue = [Int]()
        var head = 0

        // 시작 칸 1
        dist[1] = 0
        queue.append(1)

        // BFS: 주사위 1~6 던지기
        while head < queue.count {
            let cur = queue[head]; head += 1
            if cur == 100 { break }
            for d in 1...6 {
                let nxt0 = cur + d
                guard nxt0 <= 100 else { continue }
                // 사다리 or 뱀 있을 경우 최종 칸으로 이동
                let nxt = jump[nxt0] ?? nxt0
                if dist[nxt] == -1 {
                    dist[nxt] = dist[cur] + 1
                    queue.append(nxt)
                }
            }
        }

        // 출력
        // dist[100] 이 바로 최소 주사위 던진 횟수
        print(dist[100])
    }
}
