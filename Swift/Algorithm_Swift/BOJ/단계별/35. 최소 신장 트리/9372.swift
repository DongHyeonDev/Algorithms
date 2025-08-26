//
//  9372.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9372
//  알고리즘 분류: 그래프 이론, 트리

class BOJ9372: Solvable {
    // 메모리: 81608KB, 시간: 20ms, 코드 길이: 410B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let t = fileIO.readInt()

        for _ in 0..<t {
            let n = fileIO.readInt()  // 국가 수
            let m = fileIO.readInt()  // 비행기 종류 수
            
            // 간선 정보는 읽기만 하고 사용하지 않음
            // (문제에서 연결 그래프임을 보장)
            for _ in 0..<m {
                let _ = fileIO.readInt()  // a
                let _ = fileIO.readInt()  // b
            }
            
            // 연결된 그래프에서 모든 정점을 방문하기 위한 최소 간선 수
            print(n - 1)
        }
    }
}
