//
//  1764.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1764
//  알고리즘 분류: 자료 구조, 문자열, 정렬, 해시를 사용한 집합과 맵

class BOJ1764: Solvable {
    // 메모리: 92364KB, 시간: 96ms, 코드 길이: 895B
    func run() {
        // 첫 줄에서 N과 M 입력 받기
        if let firstLine = readLine()?.split(separator: " ").compactMap({ Int($0) }), firstLine.count == 2 {
            let n = firstLine[0]
            let m = firstLine[1]

            var unheardPeople: Set<String> = []  // 듣도 못한 사람 Set
            var unseenPeople: Set<String> = []   // 보도 못한 사람 Set

            // 듣도 못한 사람 입력받기
            for _ in 0..<n {
                if let name = readLine() {
                    unheardPeople.insert(name)
                }
            }
            
            for _ in 0..<m {
                if let name = readLine() {
                    unseenPeople.insert(name)
                }
            }

            // 교집합 구하기 (듣도 + 보도 못한 사람)
            let both = unheardPeople.intersection(unseenPeople)
            
            // 사전순 정렬
            let sortedBoth = both.sorted()

            // 결과 출력
            print(both.count)
            for name in sortedBoth {
                print(name)
            }
        }
    }
}
