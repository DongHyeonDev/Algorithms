//
//  1931.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1931
//  알고리즘 분류: 그리디 알고리즘, 정렬

class BOJ1931: Solvable {
    // 메모리: 83124KB, 시간: 32ms, 코드 길이: 781B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let N = fileIO.readInt()  // 회의의 개수 (1 ≤ N ≤ 100,000)

        // 회의 정보를 (종료시간, 시작시간) 쌍으로 읽어서 배열에 저장 
        var meetings = [(end: Int, start: Int)](repeating: (0,0), count: N)
        for i in 0..<N {
            let s = fileIO.readInt()  // 시작시간
            let e = fileIO.readInt()  // 끝나는시간
            meetings[i] = (e, s)
        }

        // 그리디를 위해 정렬
        // 종료시간이 빠른 순으로 정렬하고, 종료시간이 같으면 시작시간이 빠른 순으로 정렬
        meetings.sort {
            if $0.end == $1.end {
                return $0.start < $1.start
            }
            return $0.end < $1.end
        }

        // 선택 로직: 그리디 방식으로 최대 개수 구하기
        var count = 0             // 선택된 회의 개수
        var currentEndTime = 0    // “마지막으로 선택한 회의”의 끝나는 시간

        for (e, s) in meetings {
            // 만약 이 회의의 시작시간이 “현재 끝나는 시각”보다 크거나 같으면(겹치지 않으면)
            if s >= currentEndTime {
                count += 1
                currentEndTime = e
            }
        }

        // 정답 출력
        print(count)
    }
}
