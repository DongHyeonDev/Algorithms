//
//  11047.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11047
//  알고리즘 분류: 그리디 알고리즘

class BOJ11047: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 535B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()  // 동전 종류 개수
        var K = fileIO.readInt()  // 만들고자 하는 금액

        // 동전 가치 읽어서 배열에 저장 (오름차순, Ai는 Ai-1의 배수)
        var coins = [Int](repeating: 0, count: N)
        for i in 0..<N {
            coins[i] = fileIO.readInt()
        }

        // 그리디로 해결: 가장 큰 가치부터 가능한 만큼 사용
        var answer = 0
        for i in stride(from: N - 1, through: 0, by: -1) {
            if K == 0 { break }
            let value = coins[i]
            // 이 동전으로 최대 몇 개를 쓸 수 있는지
            let cnt = K / value
            answer += cnt
            K -= cnt * value
        }

        // 결과 출력
        print(answer)
    }
}
