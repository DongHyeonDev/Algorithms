//
//  11659.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11659
//  알고리즘 분류: 누적 합

class BOJ11659: Solvable {
    // 메모리: 84404KB, 시간: 44ms, 코드 길이: 456B
    func run() {
        let fileIO = RhynoFileIO()

        // 입력 처리
        let n = fileIO.readInt()    // 수의 개수
        let m = fileIO.readInt()    // 질의 개수

        // 누적합 배열 생성 (1-based indexing)
        var ps = [Int](repeating: 0, count: n + 1)
        for i in 1...n {
            ps[i] = ps[i-1] + fileIO.readInt()
        }

        // 질의 처리: [l..r] 구간 합 = ps[r] - ps[l-1]
        var output = ""
        for _ in 0..<m {
            let l = fileIO.readInt()
            let r = fileIO.readInt()
            output += "\(ps[r] - ps[l-1])\n"
        }

        // 결과 출력
        print(output)
    }
}
