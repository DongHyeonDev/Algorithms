//
//  2263.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2263
//  알고리즘 분류: 트리, 분할 정복, 재귀

class BOJ2263: Solvable {
    // 메모리: 104408KB, 시간: 76ms, 코드 길이: 1321B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 인오더, 포스트오더 입력
        var inorder = [Int](repeating: 0, count: n)
        var postorder = [Int](repeating: 0, count: n)

        for i in 0..<n {
            inorder[i] = fileIO.readInt()
        }
        for i in 0..<n {
            postorder[i] = fileIO.readInt()
        }

        // 인오더에서 값 -> 인덱스 매핑
        var inorderIndex = [Int: Int]()
        for (i, value) in inorder.enumerated() {
            inorderIndex[value] = i
        }

        // 결과 저장 (출력 최적화)
        var result = [String]()

        // 분할 정복 (재귀)
        func buildPreorder(inStart: Int, inEnd: Int, postStart: Int, postEnd: Int) {
            if inStart > inEnd || postStart > postEnd { return }
            
            // 루트는 postorder 마지막 원소
            let root = postorder[postEnd]
            result.append(String(root))
            
            // 루트 기준으로 왼쪽, 오른쪽 분할
            let rootIndex = inorderIndex[root]!
            let leftSize = rootIndex - inStart
            
            // 왼쪽 서브트리
            buildPreorder(inStart: inStart,
                          inEnd: rootIndex - 1,
                          postStart: postStart,
                          postEnd: postStart + leftSize - 1)
            
            // 오른쪽 서브트리
            buildPreorder(inStart: rootIndex + 1,
                          inEnd: inEnd,
                          postStart: postStart + leftSize,
                          postEnd: postEnd - 1)
        }

        // 실행
        buildPreorder(inStart: 0, inEnd: n-1, postStart: 0, postEnd: n-1)

        // 출력
        print(result.joined(separator: " "))
    }
}
