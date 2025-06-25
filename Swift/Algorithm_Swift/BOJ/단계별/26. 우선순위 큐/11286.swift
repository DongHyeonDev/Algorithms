//
//  11286.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11286
//  알고리즘 분류: 자료 구조, 우선순위 큐

class BOJ11286: Solvable {
    // 메모리: 81580KB, 시간: 40ms, 코드 길이: 395B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()

        var absHeap = AbsoluteHeap()

        for _ in 0..<N {
            let x = fileIO.readInt()

            if x == 0 {
                // 절댓값이 가장 작은 값 출력하고 제거
                if let min = absHeap.extractMin() {
                    print(min)
                } else {
                    print(0)
                }
            } else {
                // x를 힙에 삽입
                absHeap.insert(x)
            }
        }
    }
}
