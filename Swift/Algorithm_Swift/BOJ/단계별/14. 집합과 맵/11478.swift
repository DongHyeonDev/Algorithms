//
//  11478.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11478
//  알고리즘 분류: 자료 구조, 문자열, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ11478: Solvable {
    // 메모리: 289460KB, 시간: 940ms, 코드 길이: 425B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let s = Array(input)
            var substrings = Set<String>()

            // 모든 부분 문자열 생성
            for start in 0..<s.count {
                var temp = ""
                for end in start..<s.count {
                    temp += String(s[end])
                    substrings.insert(temp)
                }
            }

            // 서로 다른 부분 문자열의 개수 출력
            print(substrings.count)
        }
    }
}
