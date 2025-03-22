//
//  14425.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14425
//  알고리즘 분류: 자료 구조, 문자열, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ14425: Solvable {
    // 메모리: 85364KB, 시간: 100ms, 코드 길이: 619B
    func run() {
        // N과 M 입력
        if let firstLine = readLine()?.split(separator: " "),
           let n = Int(firstLine[0]),
           let m = Int(firstLine[1]) {
            
            var stringSet = Set<String>()  // 집합 S를 저장할 Set
            var count = 0

            // N개의 문자열을 Set에 저장
            for _ in 0..<n {
                if let word = readLine() {
                    stringSet.insert(word)
                }
            }

            // M개의 문자열을 검사
            for _ in 0..<m {
                if let word = readLine() {
                    if stringSet.contains(word) {
                        count += 1
                    }
                }
            }

            // 결과 출력
            print(count)
        }
    }
}
