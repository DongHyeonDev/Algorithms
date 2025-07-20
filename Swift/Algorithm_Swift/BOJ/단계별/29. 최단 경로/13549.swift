//
//  13549.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/13549
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 데이크스트라, 0-1 너비 우선 탐색

class BOJ13549: Solvable {
    // 메모리: 81660KB, 시간: 20ms, 코드 길이: 1144B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let k = fileIO.readInt()

        // 예외 처리: 수빈이가 동생과 같은 위치에 있거나 뒤에 있는 경우
        if n >= k {
            print(n - k)
            return
        }

        let maxPos = 200000  // 충분히 큰 범위 설정
        var dist = Array(repeating: -1, count: maxPos + 1)
        var deque = Deque<Int>()

        // 시작점 초기화
        dist[n] = 0
        deque.pushBack(n)

        while !deque.isEmpty {
            let current = deque.popFront()!
            
            // 목적지에 도달한 경우
            if current == k {
                print(dist[k])
                return
            }
            
            // 순간이동 (비용 0) - 덱의 앞쪽에 추가
            let teleport = current * 2
            if teleport <= maxPos && dist[teleport] == -1 {
                dist[teleport] = dist[current]
                deque.pushFront(teleport)
            }
            
            // 걷기 (비용 1) - 덱의 뒤쪽에 추가
            // 왼쪽으로 걷기
            if current - 1 >= 0 && dist[current - 1] == -1 {
                dist[current - 1] = dist[current] + 1
                deque.pushBack(current - 1)
            }
            
            // 오른쪽으로 걷기
            if current + 1 <= maxPos && dist[current + 1] == -1 {
                dist[current + 1] = dist[current] + 1
                deque.pushBack(current + 1)
            }
        }
    }
}
