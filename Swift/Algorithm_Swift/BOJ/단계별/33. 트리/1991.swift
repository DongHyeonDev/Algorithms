//
//  1991.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1991
//  알고리즘 분류: 트리, 재귀

class BOJ1991: Solvable {
    // 메모리: 79520KB, 시간: 8ms, 코드 길이: 2244B
    func run() {
        // 이진 트리 노드 클래스
        class TreeNode {
            let value: Character
            var left: TreeNode?
            var right: TreeNode?
            
            init(_ value: Character) {
                self.value = value
            }
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 노드들을 저장할 딕셔너리
        var nodes: [Character: TreeNode] = [:]

        // 입력 처리 및 트리 구성
        for _ in 0..<n {
            let parentChar = Character(fileIO.readString())
            let leftChar = fileIO.readString()
            let rightChar = fileIO.readString()
            
            // 부모 노드 생성 또는 가져오기
            if nodes[parentChar] == nil {
                nodes[parentChar] = TreeNode(parentChar)
            }
            let parentNode = nodes[parentChar]!
            
            // 왼쪽 자식 설정
            if leftChar != "." {
                let leftCharacter = Character(leftChar)
                if nodes[leftCharacter] == nil {
                    nodes[leftCharacter] = TreeNode(leftCharacter)
                }
                parentNode.left = nodes[leftCharacter]
            }
            
            // 오른쪽 자식 설정
            if rightChar != "." {
                let rightCharacter = Character(rightChar)
                if nodes[rightCharacter] == nil {
                    nodes[rightCharacter] = TreeNode(rightCharacter)
                }
                parentNode.right = nodes[rightCharacter]
            }
        }

        // 루트 노드 (항상 'A')
        let root = nodes["A"]!

        // 전위 순회 (Preorder): 루트 → 왼쪽 → 오른쪽
        func preorderTraversal(_ node: TreeNode?) -> String {
            guard let node = node else { return "" }
            
            var result = String(node.value)
            result += preorderTraversal(node.left)
            result += preorderTraversal(node.right)
            
            return result
        }

        // 중위 순회 (Inorder): 왼쪽 → 루트 → 오른쪽
        func inorderTraversal(_ node: TreeNode?) -> String {
            guard let node = node else { return "" }
            
            var result = ""
            result += inorderTraversal(node.left)
            result += String(node.value)
            result += inorderTraversal(node.right)
            
            return result
        }

        // 후위 순회 (Postorder): 왼쪽 → 오른쪽 → 루트
        func postorderTraversal(_ node: TreeNode?) -> String {
            guard let node = node else { return "" }
            
            var result = ""
            result += postorderTraversal(node.left)
            result += postorderTraversal(node.right)
            result += String(node.value)
            
            return result
        }

        // 결과 출력
        print(preorderTraversal(root))   // 전위 순회
        print(inorderTraversal(root))    // 중위 순회
        print(postorderTraversal(root))  // 후위 순회
    }
}
