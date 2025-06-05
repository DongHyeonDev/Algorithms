//
//  11399.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11399
//  알고리즘 분류: 그리디 알고리즘, 정렬

class BOJ11399: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 555B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()              // 사람 수 N (1 ≤ N ≤ 1,000)
        var times = [Int](repeating: 0, count: N)
        for i in 0..<N {
            times[i] = fileIO.readInt()       // i번째 사람이 돈을 인출하는 데 걸리는 시간 Pi
        }

        // 그리디: 인출 시간을 오름차순 정렬
        times.sort()

        // 누적합(prefix sum)을 구하면서 “각 사람의 대기시간 누적” 합 계산
        var result = 0      // 최종 답: 모든 사람이 줄 서서 돈을 뽑을 때 소요된 “합산 대기시간”
        var prefix = 0      // 지금까지 더해진 누적 인출 시간
        for t in times {
            prefix += t     // 이 사람이 인출을 시작할 때까지 대기해야 하는 시간누적
            result += prefix
        }

        // 결과 출력
        print(result)
    }
}
