//
//  6497.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/6497
//  알고리즘 분류: 그래프 이론, 최소 스패닝 트리

class BOJ6497: Solvable {
    // 메모리: 102800KB, 시간: 160ms, 코드 길이: 549B
    func run() {
        // 메인 실행
        let fileIO = RhynoFileIO()

        while true {
            let m = fileIO.readInt()
            let n = fileIO.readInt()
            
            if m == 0 && n == 0 { break }
            
            var edges: [Edge] = []
            var totalWeight = 0
            
            for _ in 0..<n {
                let x = fileIO.readInt()
                let y = fileIO.readInt()
                let z = fileIO.readInt()
                
                edges.append(Edge(x, y, Double(z)))
                totalWeight += z
            }
            
            let mstWeight = kruskal(m, edges)
            let savedAmount = totalWeight - mstWeight
            
            print(savedAmount)
        }
    }
}
