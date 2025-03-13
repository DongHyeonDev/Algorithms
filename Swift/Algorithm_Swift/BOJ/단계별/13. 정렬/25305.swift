//
//  25305.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25305
//  알고리즘 분류: 구현, 정렬

class BOJ25305: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 501B
    func run() {
        // 첫 번째 줄 입력 받기
        if let firstInput = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           let secondInput = readLine()?.split(separator: " ").compactMap({ Int($0) }) {

            let _ = firstInput[0]  // 응시자 수
            let k = firstInput[1]  // 상을 받는 사람 수
            var scores = secondInput  // 학생들의 점수 리스트

            // 점수를 내림차순 정렬
            scores.sort(by: >)

            // k번째로 높은 점수 출력
            print(scores[k - 1])
        }
    }
}
