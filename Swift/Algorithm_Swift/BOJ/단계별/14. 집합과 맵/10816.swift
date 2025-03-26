//
//  10816.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10816
//  알고리즘 분류: 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵

class BOJ10816: Solvable {
    // 메모리: 140492KB, 시간: 600ms, 코드 길이: 1103B
    func run() {
        // 숫자 카드 개수 입력
        if let _ = Int(readLine() ?? "") {
            // 숫자 카드 목록 입력
            if let sanggeunCards = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                var cardCount: [Int: Int] = [:] // 카드 숫자별 개수 저장용 딕셔너리
                
                // 숫자 카드 개수 카운트
                for card in sanggeunCards {
                    cardCount[card, default: 0] += 1
                }
                
                // 체크할 카드 개수 입력
                if let _ = Int(readLine() ?? "") {
                    // 체크할 카드 목록 입력
                    if let checkCards = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                        var results: [Int] = []
                        
                        // 각 카드에 대해 존재 여부 확인 및 개수 추가
                        for number in checkCards {
                            results.append(cardCount[number] ?? 0)
                        }
                        
                        // 결과 출력 (공백으로 구분)
                        print(results.map { String($0) }.joined(separator: " "))
                    }
                }
            }
        }
    }
}
