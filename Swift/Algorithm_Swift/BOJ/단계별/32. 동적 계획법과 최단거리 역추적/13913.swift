//
//  13913.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/13913
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 역추적

class BOJ13913: Solvable {
    // 메모리: 87564KB, 시간: 40ms, 코드 길이: 1222B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let k = fileIO.readInt()

        // BFS를 위한 큐와 방문 배열
        var queue: [(Int, Int)] = [(n, 0)] // (위치, 시간)
        var visited = Array(repeating: -1, count: 100001)
        var parent = Array(repeating: -1, count: 100001)

        visited[n] = 0
        var queueIndex = 0

        // BFS 실행
        while queueIndex < queue.count {
            let (currentPos, currentTime) = queue[queueIndex]
            queueIndex += 1
            
            // 동생을 찾았다면 종료
            if currentPos == k {
                break
            }
            
            // 가능한 3가지 이동 방법
            let nextPositions = [currentPos - 1, currentPos + 1, currentPos * 2]
            
            for nextPos in nextPositions {
                // 범위 체크
                if nextPos < 0 || nextPos > 100000 {
                    continue
                }
                
                // 아직 방문하지 않은 위치라면
                if visited[nextPos] == -1 {
                    visited[nextPos] = currentTime + 1
                    parent[nextPos] = currentPos
                    queue.append((nextPos, currentTime + 1))
                }
            }
        }

        // 최단 시간 출력
        print(visited[k])

        // 경로 역추적
        var path: [Int] = []
        var current = k

        while current != -1 {
            path.append(current)
            current = parent[current]
        }

        // 경로 뒤집기 (시작점부터 끝점까지)
        path.reverse()

        // 경로 출력
        print(path.map { String($0) }.joined(separator: " "))
    }
}
