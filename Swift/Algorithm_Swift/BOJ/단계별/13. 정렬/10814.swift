//
//  10814.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10814
//  알고리즘 분류: 정렬

class BOJ10814: Solvable {
    // 메모리: 85768KB, 시간: 192ms, 코드 길이: 805B
    func run() {
        // 회원 정보를 저장할 구조체
        struct Member {
            let age: Int
            let name: String
            let order: Int // 가입 순서
        }

        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var members = [Member]()

            // 회원 정보 입력 받기
            for i in 0..<n {
                if let input = readLine()?.split(separator: " ") {
                    if let age = Int(input[0]) {
                        let name = String(input[1])
                        members.append(Member(age: age, name: name, order: i))
                    }
                }
            }

            // 정렬: 나이 오름차순, 나이가 같으면 가입 순서(order) 오름차순
            members.sort { $0.age < $1.age || ($0.age == $1.age && $0.order < $1.order) }

            // 결과 출력
            for member in members {
                print(member.age, member.name)
            }
        }
    }
}
