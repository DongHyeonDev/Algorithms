//
//  1541.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1541
//  알고리즘 분류: 수학, 그리디 알고리즘, 문자열, 파싱

class BOJ1541: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 614B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 식 전체를 문자열로 입력 받기
        let expr = fileIO.readString()

        // '-'를 기준으로 분할
        let minusParts = expr.split(separator: "-").map { String($0) }

        // 첫 번째 부분 덧셈 처리
        let firstChunk = minusParts[0]
        let initialSum = firstChunk
            .split(separator: "+")
            .map { Int($0)! }
            .reduce(0, +)

        // 두 번째 부분부터 모두 뺄셈 처리
        var total = initialSum
        for i in 1..<minusParts.count {
            let chunk = minusParts[i]
            // "50+40"처럼 '+'끼리 더한 값을 구한다.
            let chunkSum = chunk
                .split(separator: "+")
                .map { Int($0)! }
                .reduce(0, +)
            total -= chunkSum
        }

        // 결과 출력
        print(total)
    }
}
