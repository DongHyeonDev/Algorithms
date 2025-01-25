//
//  10809.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10809
//  알고리즘 분류: 구현, 문자열

class BOJ10809: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 667B
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 결과를 저장할 배열, 초기값은 -1로 설정
            var positions = Array(repeating: -1, count: 26)
            
            // 각 문자의 위치 계산
            for (index, char) in input.enumerated() {
                if let asciiValue = char.asciiValue {
                    let charIndex = Int(asciiValue - Character("a").asciiValue!)
                    // 해당 문자가 처음 등장한 경우에만 위치 저장
                    if positions[charIndex] == -1 {
                        positions[charIndex] = index
                    }
                }
            }
            
            // 결과 출력
            print(positions.map { String($0) }.joined(separator: " "))
        }
    }
}
