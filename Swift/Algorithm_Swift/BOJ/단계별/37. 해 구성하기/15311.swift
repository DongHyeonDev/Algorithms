//
//  15311.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/13/26.
//

//  문제 링크: https://www.acmicpc.net/problem/15311
//  알고리즘 분류: 수학, 애드 혹, 해 구성하기

class BOJ15311: Solvable {
    // 메모리: 80488KB, 시간: 52ms, 코드 길이: 119B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let _ = io.readInt() // N = 1,000,000 항상

        // 1000개의 1, 999개의 1001
        print(1999)
        var output = String(repeating: "1 ", count: 1000)
        output += (0..<999).map { _ in "1001" }.joined(separator: " ")
        print(output)
    }
}
