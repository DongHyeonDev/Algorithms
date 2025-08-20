//
//  5639.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/5639
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 트리, 재귀

class BOJ5639: Solvable {
    // 메모리: 81016KB, 시간: 60ms, 코드 길이: 637B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        var preorder = [Int]()

        // 입력: 한 줄에 하나씩, 0이 아닌 양의 정수
        while let x = fileIO.readIntOptional() {
            preorder.append(x)
        }

        // 후위 순회 출력 함수
        var output = [String]()
        func buildPostorder(_ l: Int, _ r: Int) {
            guard l < r else { return }
            let root = preorder[l]
            var m = l + 1
            // 오른쪽 서브트리 시작 인덱스 찾기
            while m < r && preorder[m] < root {
                m += 1
            }
            // 왼쪽
            buildPostorder(l + 1, m)
            // 오른쪽
            buildPostorder(m, r)
            // 루트
            output.append(String(root))
        }

        // 전체 범위 처리
        buildPostorder(0, preorder.count)

        // 결과 출력
        print(output.joined(separator: "\n"))
    }
}
