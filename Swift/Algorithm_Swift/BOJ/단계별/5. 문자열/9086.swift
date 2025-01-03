//
//  9086.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9086
//  알고리즘 분류: 구현, 문자열

class BOJ9086: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 409B
    func run() {
        // 첫 번째 줄: 테스트 케이스 개수 입력 받기
        if let tInput = readLine(), let t = Int(tInput), t >= 1 && t <= 10 {
            for _ in 0..<t {
                if let str = readLine(), str.count > 0 {
                    // 첫 글자와 마지막 글자 추출
                    let firstChar = str.first!
                    let lastChar = str.last!
                    print("\(firstChar)\(lastChar)")
                }
            }
        }
    }
}
