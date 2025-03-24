//
//  1620.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1620
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵

class BOJ1620: Solvable {
    // 메모리: 101832KB, 시간: 184ms, 코드 길이: 1169B
    func run() {
        // 첫 번째 줄에서 N과 M을 입력받음
        if let nm = readLine()?.split(separator: " ").compactMap({ Int($0) }), nm.count == 2 {
            let n = nm[0]
            let m = nm[1]
            
            var nameToNumber = [String: Int]() // 이름 → 번호
            var numberToName = [String]() // 번호 → 이름, 1-based index

            // 포켓몬 이름 입력 받기
            for _ in 0..<n {
                if let name = readLine() {
                    nameToNumber[name] = numberToName.count + 1 // 현재 인덱스 + 1이 번호
                    numberToName.append(name)
                }
            }

            // 문제 입력 처리 및 결과 저장
            var result = ""
            for _ in 0..<m {
                if let query = readLine() {
                    if let number = Int(query) {
                        // 숫자 입력 → 이름 출력
                        if number >= 1 && number <= n {
                            result += numberToName[number - 1] + "\n"
                        }
                    } else {
                        // 문자열 입력 → 번호 출력
                        if let number = nameToNumber[query] {
                            result += "\(number)\n"
                        }
                    }
                }
            }

            // 결과 출력
            print(result)
        }
    }
}
