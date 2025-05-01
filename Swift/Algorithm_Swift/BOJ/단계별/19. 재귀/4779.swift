//
//  4779.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4779
//  알고리즘 분류: 분할 정복, 재귀

class BOJ4779: Solvable {
    // 메모리: 89104KB, 시간: 80ms, 코드 길이: 1302B
    func run() {
        /// 재귀적으로 칸토어 집합을 그리는 함수
        /// - Parameters:
        ///   - depth: 남은 재귀 단계 (0이 되면 길이 1 짜리 선을 그린다)
        ///   - start: 현재 구간의 시작 인덱스
        ///   - length: 현재 구간의 총 길이 (3^depth)
        ///   - arr: 출력할 문자 배열
        func drawCantor(_ depth: Int, _ start: Int, _ length: Int, _ arr: inout [Character]) {
            if depth == 0 {
                // 더 이상 나눌 수 없을 때 선 하나('-')를 찍는다
                arr[start] = "-"
            } else {
                // 중간 구간 길이
                let segment = length / 3
                // 왼쪽 구간 그리기
                drawCantor(depth - 1, start, segment, &arr)
                // 오른쪽 구간 그리기
                drawCantor(depth - 1, start + 2 * segment, segment, &arr)
                // 가운데 구간은 기본값인 공백(' ') 그대로 둔다
            }
        }
        
        // 입력이 여러 줄로 주어지므로, EOF까지 읽어서 처리
        while let line = readLine(), let N = Int(line) {
            // 3^N 계산
            var length = 1
            for _ in 0..<N { length *= 3 }
            // 결과를 담을 배열을 공백으로 초기화
            var arr = Array(repeating: Character(" "), count: length)
            // 칸토어 집합 그리기
            drawCantor(N, 0, length, &arr)
            // 한 줄로 출력
            print(String(arr))
        }
    }
}
