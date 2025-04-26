//
//  20920.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/20920
//  알고리즘 분류: 자료 구조, 문자열, 정렬, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ20920: Solvable {
    // 메모리: 88804KB, 시간: 888ms, 코드 길이: 932B
    func run() {
        // 1. 입력 처리
        guard let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }),
              firstLine.count == 2 else {
            fatalError("입력 형식 오류")
        }
        let N = firstLine[0]
        let M = firstLine[1]

        // 2. 단어 빈도수 세기 (길이 ≥ M인 단어만)
        var freq: [String: Int] = [:]
        for _ in 0..<N {
            guard let word = readLine() else { continue }
            if word.count >= M {
                freq[word, default: 0] += 1
            }
        }

        // 3. 정렬 기준에 따라 단어 목록 생성
        let sortedWords = freq.keys.sorted { a, b in
            let fa = freq[a]!      // a의 빈도
            let fb = freq[b]!      // b의 빈도
            if fa != fb {
                return fa > fb     // 1) 빈도 내림차순
            }
            if a.count != b.count {
                return a.count > b.count  // 2) 길이 내림차순
            }
            return a < b          // 3) 사전 오름차순
        }

        // 4. 결과 출력
        for word in sortedWords {
            print(word)
        }
    }
}
