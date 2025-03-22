//
//  10815.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10815
//  알고리즘 분류: 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵

class BOJ10815: Solvable {
    // 메모리: 122096KB, 시간: 512ms, 코드 길이: 657B
    func run() {
        // 상근이가 가지고 있는 숫자 카드 개수
        if let _ = Int(readLine() ?? "0"),
           let sangGeunCards = readLine()?.split(separator: " ").compactMap({ Int($0) }),
           let _ = Int(readLine() ?? "0"),
           let numbersToCheck = readLine()?.split(separator: " ").compactMap({ Int($0) }) {

            // 상근이 카드들을 Set으로 저장하여 빠른 탐색 가능
            let cardSet = Set(sangGeunCards)
            
            // 주어진 숫자가 상근이 카드에 있는지 여부를 확인
            let result = numbersToCheck.map { cardSet.contains($0) ? "1" : "0" }
            
            // 결과 출력
            print(result.joined(separator: " "))
        }
    }
}
