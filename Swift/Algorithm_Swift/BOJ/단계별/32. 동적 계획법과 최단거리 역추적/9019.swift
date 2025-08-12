//
//  9019.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9019
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 역추적

class BOJ9019: Solvable {
    // 메모리: 80200KB, 시간: 5140ms, 코드 길이: 2259B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let t = fileIO.readInt()

        // 각 연산을 수행하는 함수들
        func operationD(_ n: Int) -> Int {
            return (n * 2) % 10000
        }

        func operationS(_ n: Int) -> Int {
            return n == 0 ? 9999 : n - 1
        }

        func operationL(_ n: Int) -> Int {
            return (n % 1000) * 10 + n / 1000
        }

        func operationR(_ n: Int) -> Int {
            return (n % 10) * 1000 + n / 10
        }

        for _ in 0..<t {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            
            if a == b {
                print("")
                continue
            }
            
            // BFS를 위한 자료구조
            var queue = [Int](repeating: 0, count: 40000)
            var head = 0, tail = 0
            var visited = [Bool](repeating: false, count: 10000)
            var parent = [Int](repeating: -1, count: 10000)
            var command = [Character](repeating: " ", count: 10000)
            
            func push(_ v: Int) {
                queue[tail] = v
                tail += 1
            }
            
            // 시작점 설정
            visited[a] = true
            push(a)
            
            // BFS 실행
            while head < tail {
                let current = queue[head]
                head += 1
                
                if current == b {
                    break
                }
                
                // D 연산
                let nextD = operationD(current)
                if !visited[nextD] {
                    visited[nextD] = true
                    parent[nextD] = current
                    command[nextD] = "D"
                    push(nextD)
                }
                
                // S 연산
                let nextS = operationS(current)
                if !visited[nextS] {
                    visited[nextS] = true
                    parent[nextS] = current
                    command[nextS] = "S"
                    push(nextS)
                }
                
                // L 연산
                let nextL = operationL(current)
                if !visited[nextL] {
                    visited[nextL] = true
                    parent[nextL] = current
                    command[nextL] = "L"
                    push(nextL)
                }
                
                // R 연산
                let nextR = operationR(current)
                if !visited[nextR] {
                    visited[nextR] = true
                    parent[nextR] = current
                    command[nextR] = "R"
                    push(nextR)
                }
            }
            
            // 경로 역추적
            var result = [Character]()
            var current = b
            
            while parent[current] != -1 {
                result.append(command[current])
                current = parent[current]
            }
            
            result.reverse()
            print(String(result))
        }
    }
}
