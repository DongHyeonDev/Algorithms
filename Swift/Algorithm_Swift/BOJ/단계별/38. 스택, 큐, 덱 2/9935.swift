//
//  9935.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/17/26.
//

//  문제 링크: https://www.acmicpc.net/problem/9935
//  알고리즘 분류: 자료 구조, 문자열, 스택

class BOJ9935: Solvable {
    // 메모리: 100040KB, 시간: 76ms, 코드 길이: 819B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let s = io.readString()
        let bomb = Array(io.readString())
        let bLen = bomb.count

        // 스택: (문자, 이 문자를 쌓은 후 폭발 문자열 매칭 길이)
        var stack = [(UInt8, Int)]()
        stack.reserveCapacity(s.count)
        let bombBytes = bomb.map { $0.asciiValue! }

        for ch in s.utf8 {
            let matchSoFar = stack.isEmpty ? 0 : stack.last!.1
            let nextMatch: Int
            if ch == bombBytes[matchSoFar] {
                nextMatch = matchSoFar + 1
            } else {
                // KMP 없이 단순 처리: 폭발 문자열에 중복 문자 없으므로
                nextMatch = ch == bombBytes[0] ? 1 : 0
            }
            stack.append((ch, nextMatch))
            
            if nextMatch == bLen {
                // 폭발: 폭발 문자열 길이만큼 제거
                for _ in 0..<bLen { stack.removeLast() }
            }
        }

        if stack.isEmpty {
            print("FRULA")
        } else {
            print(String(bytes: stack.map { $0.0 }, encoding: .ascii)!)
        }
    }
}
