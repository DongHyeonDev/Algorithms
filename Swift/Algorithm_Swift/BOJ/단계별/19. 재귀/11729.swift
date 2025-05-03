//
//  11729.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11729
//  알고리즘 분류: 재귀

import Foundation

class BOJ11729: Solvable {
    // 메모리: 87388KB, 시간: 244ms, 코드 길이: 850B
    func run() {
        // 재귀적으로 하노이 탑 이동 과정을 문자열에 버퍼링합니다.
        func solveHanoi(_ n: Int, _ from: Int, _ to: Int, _ aux: Int, _ buffer: inout String) {
            if n == 1 {
                // 원판 1개는 바로 from -> to
                buffer += "\(from) \(to)\n"
                return
            }
            // n-1개를 from에서 aux로 옮기기
            solveHanoi(n - 1, from, aux, to, &buffer)
            // 가장 큰 원판을 from에서 to로
            buffer += "\(from) \(to)\n"
            // n-1개를 aux에서 to로 옮기기
            solveHanoi(n - 1, aux, to, from, &buffer)
        }

        guard let line = readLine(), let N = Int(line) else {
            exit(0)
        }

        // 이동 횟수는 2^N - 1
        let moves = (1 << N) - 1

        // 결과 문자열 버퍼
        var output = "\(moves)\n"
        // 이동 과정 기록
        solveHanoi(N, 1, 3, 2, &output)

        // 한 번에 출력
        print(output, terminator: "")
    }
}
