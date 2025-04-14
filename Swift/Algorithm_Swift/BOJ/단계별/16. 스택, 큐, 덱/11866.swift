//
//  11866.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11866
//  알고리즘 분류: 구현, 자료 구조, 큐

class BOJ11866: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 483B
    func run() {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        let n = input[0], k = input[1]

        var people = Array(1...n)  // 1부터 n까지의 사람
        var result: [Int] = []
        var index = 0

        while !people.isEmpty {
            index = (index + k - 1) % people.count // 제거할 인덱스 계산
            result.append(people.remove(at: index)) // 제거 후 결과에 추가
        }

        // 결과 출력
        let output = result.map { String($0) }.joined(separator: ", ")
        print("<\(output)>")
    }
}
