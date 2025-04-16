//
//  2346.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2346
//  알고리즘 분류: 자료 구조, 덱

class BOJ2346: Solvable {
    // 메모리: 79516KB, 시간: 28ms, 코드 길이: 2676B
    func run() {
        // RhynoFileIO를 사용해 빠른 입력 처리
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 풍선 번호와 해당 이동 값을 덱에 삽입
        var deque = Deque<(index: Int, move: Int)>()
        for i in 1...n {
            let move = fileIO.readInt()
            deque.pushBack((i, move))
        }

        var result: [Int] = []

        // 덱이 빌 때까지 풍선 터뜨리기 반복
        while !deque.isEmpty {
            // 현재 풍선을 터뜨리고 결과에 추가
            let current = deque.popFront()!
            result.append(current.index)

            // 모든 풍선을 터뜨렸다면 종료
            guard !deque.isEmpty else { break }

            let move = current.move

            if move > 0 {
                // 오른쪽(앞에서 뒤로): move - 1 만큼 회전
                for _ in 1..<move {
                    if let temp = deque.popFront() {
                        deque.pushBack(temp)
                    }
                }
            } else {
                // 왼쪽(뒤에서 앞으로): abs(move) 만큼 회전
                for _ in 0..<abs(move) {
                    if let temp = deque.popBack() {
                        deque.pushFront(temp)
                    }
                }
            }
        }

        // 결과 출력: 터진 순서대로 풍선 번호 출력
        print(result.map { String($0) }.joined(separator: " "))
    }
}
