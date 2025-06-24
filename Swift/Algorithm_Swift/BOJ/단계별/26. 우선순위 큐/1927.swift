//
//  1927.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1927
//  알고리즘 분류: 자료 구조, 우선순위 큐

class BOJ1927: Solvable {
    // 메모리: 83672KB, 시간: 76ms, 코드 길이: 381B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        
        var minHeap = MinHeap()
        
        for _ in 0..<N {
            let x = fileIO.readInt()
            
            if x == 0 {
                // 최솟값 출력하고 제거
                if let min = minHeap.extractMin() {
                    print(min)
                } else {
                    print(0)
                }
            } else {
                // x를 힙에 삽입
                minHeap.insert(x)
            }
        }
    }
}
