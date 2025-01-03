//
//  15552.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/30/24.
//

//  문제 링크: https://www.acmicpc.net/problem/15552
//  알고리즘 분류: 수학, 구현, 사칙연산

class BOJ15552: Solvable {
    // 메모리: 119900KB, 시간: 268ms, 코드 길이: 2060B
    func run() {
        let fileIO = RhynoFileIO()

        // 첫 번째 줄: 테스트 케이스 개수 읽기
        let testCaseCount = fileIO.readInt()

        // 결과를 저장할 배열
        var results = [String]()

        // 각 테스트 케이스 처리
        for _ in 0..<testCaseCount {
            let a = fileIO.readInt()
            let b = fileIO.readInt()
            results.append(String(a + b)) // A+B 결과를 문자열로 저장
        }

        // 결과 출력
        print(results.joined(separator: "\n"))
    }
}
