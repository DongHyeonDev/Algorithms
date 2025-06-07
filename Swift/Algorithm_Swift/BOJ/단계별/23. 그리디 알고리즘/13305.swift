//
//  13305.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/13305
//  알고리즘 분류: 그리디 알고리즘

class BOJ13305: Solvable {
    // 메모리: 82564KB, 시간: 28ms, 코드 길이: 608B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let n = fileIO.readInt()                 // 도시의 개수 N
        var dist = [Int](repeating: 0, count: n-1)
        for i in 0..<n-1 {
            dist[i] = fileIO.readInt()           // i번째 도로의 길이
        }
        var price = [Int](repeating: 0, count: n)
        for i in 0..<n {
            price[i] = fileIO.readInt()          // i번째 도시의 리터당 가격
        }

        // 그리디 계산
        var minPrice = price[0]
        var totalCost: Int64 = 0
        for i in 0..<n-1 {
            if price[i] < minPrice {
                minPrice = price[i]
            }
            // Int64 곱셈으로 오버플로우 방지
            totalCost += Int64(minPrice) * Int64(dist[i])
        }

        // 결과 출력
        print(totalCost)
    }
}
