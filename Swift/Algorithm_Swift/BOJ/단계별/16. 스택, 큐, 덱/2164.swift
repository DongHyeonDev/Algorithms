//
//  2164.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2164
//  알고리즘 분류: 자료 구조, 큐

class BOJ2164: Solvable {
    // 메모리: 91232KB, 시간: 24ms, 코드 길이: 393B
    func run() {
        // 입력 받기
        let n = Int(readLine() ?? "") ?? 0

        // 1부터 N까지 큐 초기화
        var queue = Array(1...n)
        var front = 0

        // 카드가 한 장 남을 때까지 반복
        while queue.count - front > 1 {
            front += 1 // 카드 버리기
            queue.append(queue[front]) // 다음 카드 맨 뒤로 이동
            front += 1
        }

        // 결과 출력 (남은 카드)
        print(queue[front])
    }
}
