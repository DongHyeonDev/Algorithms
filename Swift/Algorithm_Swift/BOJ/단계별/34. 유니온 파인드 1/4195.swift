//
//  4195.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4195
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵, 집합과 맵, 분리 집합

class BOJ4195: Solvable {
    // 메모리: 107936KB, 시간: 280ms, 코드 길이: 1830B
    func run() {
        // 크기를 추적하는 Union-Find
        final class WeightedUnionFind {
            private var parent: [Int]
            private var size: [Int]  // 각 집합의 크기
            private var nextId: Int = 0
            private var nameToId: [String: Int] = [:]
            
            init() {
                parent = []
                size = []
            }
            
            // 이름을 ID로 변환 (없으면 새로 생성)
            func getId(_ name: String) -> Int {
                if let id = nameToId[name] {
                    return id
                }
                
                let id = nextId
                nameToId[name] = id
                parent.append(id)
                size.append(1)  // 새로운 집합의 크기는 1
                nextId += 1
                return id
            }
            
            @inline(__always) func find(_ x: Int) -> Int {
                if parent[x] != x {
                    parent[x] = find(parent[x])
                }
                return parent[x]
            }
            
            @inline(__always) func union(_ x: Int, _ y: Int) -> Int {
                let rootX = find(x)
                let rootY = find(y)
                
                if rootX == rootY {
                    return size[rootX]  // 이미 같은 집합
                }
                
                // 크기가 작은 쪽을 큰 쪽에 붙이기 (Union by Size)
                if size[rootX] < size[rootY] {
                    parent[rootX] = rootY
                    size[rootY] += size[rootX]
                    return size[rootY]
                } else {
                    parent[rootY] = rootX
                    size[rootX] += size[rootY]
                    return size[rootX]
                }
            }
            
            func getSize(_ x: Int) -> Int {
                return size[find(x)]
            }
        }

        // 메인 실행
        let fileIO = RhynoFileIO()
        let testCases = fileIO.readInt()

        for _ in 0..<testCases {
            let f = fileIO.readInt()
            let uf = WeightedUnionFind()
            
            for _ in 0..<f {
                let friend1 = fileIO.readString()
                let friend2 = fileIO.readString()
                
                let id1 = uf.getId(friend1)
                let id2 = uf.getId(friend2)
                
                let networkSize = uf.union(id1, id2)
                print(networkSize)
            }
        }
    }
}
