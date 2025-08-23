//
//  1976.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1976
//  알고리즘 분류: 자료 구조, 그래프 이론, 그래프 탐색, 분리 집합

class BOJ1976: Solvable {
    // 메모리: 79672KB, 시간: 12ms, 코드 길이: 1079B
    func run() {
        // Union-Find 자료구조
        var parent: [Int] = []

        @inline(__always) func find(_ x: Int) -> Int {
            if parent[x] != x {
                parent[x] = find(parent[x])
            }
            return parent[x]
        }

        @inline(__always) func union(_ x: Int, _ y: Int) {
            let px = find(x)
            let py = find(y)
            if px != py {
                parent[px] = py
            }
        }

        // 메인 실행
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let m = fileIO.readInt()

        // parent 배열 초기화 (1-indexed)
        parent = Array(0...n)

        // 연결 정보 입력 및 Union-Find 구성
        for i in 1...n {
            for j in 1...n {
                let connected = fileIO.readInt()
                if connected == 1 && i < j { // 중복 처리 방지를 위해 i < j만 처리
                    union(i, j)
                }
            }
        }

        // 여행 계획 입력
        var travelPlan: [Int] = []
        for _ in 0..<m {
            travelPlan.append(fileIO.readInt())
        }

        // 여행 계획의 모든 도시가 같은 연결 요소에 속하는지 확인
        var canTravel = true
        if m > 1 {
            let firstCityRoot = find(travelPlan[0])
            
            for i in 1..<m {
                if find(travelPlan[i]) != firstCityRoot {
                    canTravel = false
                    break
                }
            }
        }

        print(canTravel ? "YES" : "NO")
    }
}
