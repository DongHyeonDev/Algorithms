//
//  1181.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1181
//  알고리즘 분류: 정렬

class BOJ1181: Solvable {
    // 메모리: 82644KB, 시간: 268ms, 코드 길이: 640B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var words = Set<String>() // 중복 제거를 위한 Set 사용

            // 단어 입력 받기
            for _ in 0..<n {
                if let word = readLine() {
                    words.insert(word)
                }
            }

            // 정렬 (길이 우선, 길이가 같으면 사전순)
            let sortedWords = words.sorted {
                $0.count < $1.count || ($0.count == $1.count && $0 < $1)
            }

            // 결과 출력
            for word in sortedWords {
                print(word)
            }
        }
    }
}
