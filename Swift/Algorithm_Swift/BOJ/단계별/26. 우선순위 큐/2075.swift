//
//  2075.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2075
//  알고리즘 분류: 자료 구조, 정렬, 우선순위 큐

class BOJ2075: Solvable {
    // 메모리: 122020KB, 시간: 528ms, 코드 길이: 373B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()

        // N×N 표를 순회하며 N번째로 큰 수 유지
        var heap = MinHeap()
        for _ in 0..<N {
            for _ in 0..<N {
                let x = fileIO.readInt()
                heap.insert(x)
                if heap.count > N {
                    _ = heap.extractMin()
                }
            }
        }

        // 힙 루트가 곧 N번째로 큰 수
        let result = heap.extractMin()!
        print(result)
    }
}
