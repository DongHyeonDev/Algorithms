//
//  18870.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/18870
//  알고리즘 분류: 정렬, 값 / 좌표 압축

class BOJ18870: Solvable {
    // 메모리: 155336KB, 시간: 900ms, 코드 길이: 603B
    func run() {
        // 입력 받기
        if let _ = Int(readLine() ?? "0"),
           let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            
            // 중복을 제거한 정렬된 좌표 리스트 생성
            let sortedUnique = Array(Set(input)).sorted()

            // 좌표 압축 결과 저장 딕셔너리 생성
            var compressedDict = [Int: Int]()
            for (index, value) in sortedUnique.enumerated() {
                compressedDict[value] = index
            }

            // 입력 좌표를 압축된 값으로 변환 후 출력
            print(input.map { compressedDict[$0]! }.map(String.init).joined(separator: " "))
        }
    }
}
