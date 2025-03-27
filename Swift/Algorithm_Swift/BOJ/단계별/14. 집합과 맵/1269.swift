//
//  1269.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1269
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ1269: Solvable {
    // 메모리: 112232KB, 시간: 220ms, 코드 길이: 786B
    func run() {
        // 첫 줄: 집합 A와 B의 원소 개수 입력 받기
        if let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }), firstLine.count == 2 {
            
            // 둘째 줄: 집합 A 원소 입력
            if let setALine = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                let setA = Set(setALine)
                
                // 셋째 줄: 집합 B 원소 입력
                if let setBLine = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
                    let setB = Set(setBLine)

                    // 대칭 차집합 계산: (A - B) ∪ (B - A)
                    let symmetricDifference = setA.symmetricDifference(setB)
                    
                    // 결과 출력: 대칭 차집합의 원소 개수
                    print(symmetricDifference.count)
                }
            }
        }
    }
}
