//
//  25288.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/5/26.
//

//  문제 링크: https://www.acmicpc.net/problem/25288
//  알고리즘 분류: 문자열, 애드 혹, 해 구성하기

class BOJ25288: Solvable {
    // 메모리: 79772KB, 시간: 12ms, 코드 길이: 232B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()
        let s = io.readString()

        // 알파벳 정렬
        var chars = Array(s).sorted()
        let unit = String(chars)

        // N번 반복
        var output = String(repeating: unit, count: N)
        print(output)
    }
}
