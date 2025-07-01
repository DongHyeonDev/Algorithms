//
//  24444.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/24444
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 정렬, 너비 우선 탐색

class BOJ24444: Solvable {
    // 메모리: 93568KB, 시간: 104ms, 코드 길이: 951B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let M = fileIO.readInt()
        let R = fileIO.readInt()

        // 인접 리스트 생성 및 입력
        var graph = [[Int]](repeating: [], count: N + 1)
        for _ in 0..<M {
            let u = fileIO.readInt()
            let v = fileIO.readInt()
            graph[u].append(v)
            graph[v].append(u)
        }
        // “오름차순” 방문을 위해 각 리스트 정렬
        for i in 1...N {
            graph[i].sort()
        }

        // BFS 준비
        var visitOrder = [Int](repeating: 0, count: N + 1)
        var order = 1
        var queue = [Int]()
        queue.reserveCapacity(N)
        var head = 0

        // 시작 정점
        visitOrder[R] = order
        order += 1
        queue.append(R)

        // BFS 순회
        while head < queue.count {
            let u = queue[head]
            head += 1
            for v in graph[u] {
                if visitOrder[v] == 0 {
                    visitOrder[v] = order
                    order += 1
                    queue.append(v)
                }
            }
        }

        // 결과 출력
        var out = String()
        out.reserveCapacity(N * 4)
        for i in 1...N {
            out += "\(visitOrder[i])\n"
        }
        print(out, terminator: "")
    }
}
