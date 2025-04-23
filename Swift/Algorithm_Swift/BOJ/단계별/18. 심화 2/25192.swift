//
//  25192.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25192
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ25192: Solvable {
    // 메모리: 86444KB, 시간: 76ms, 코드 길이: 685B
    func run() {
        // 입력 처리
        if let n = Int(readLine() ?? "") {
            var greeted = Set<String>()  // 현재 세션에서 이미 인사한 사람 기록
            var count = 0                // 곰곰티콘 사용 횟수

            for _ in 0..<n {
                guard let line = readLine() else { continue }
                if line == "ENTER" {
                    // 새로운 세션 시작: 기존 기록 초기화
                    greeted.removeAll()
                } else {
                    // 닉네임이 처음 인사하는 경우에만 카운트
                    if !greeted.contains(line) {
                        count += 1
                        greeted.insert(line)
                    }
                }
            }

            // 결과 출력
            print(count)
        }
    }
}
