//
//  1316.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1316
//  알고리즘 분류: 구현, 문자열

class BOJ1316: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 930B
    func run() {
        // 그룹 단어 판별 함수
        func isGroupWord(_ word: String) -> Bool {
            var seenCharacters = Set<Character>() // 이미 등장한 문자 저장
            var previousCharacter: Character? = nil
            
            for char in word {
                if char != previousCharacter { // 새로운 문자가 등장했을 때
                    if seenCharacters.contains(char) {
                        return false // 이전에 등장한 문자가 다시 나오면 그룹 단어가 아님
                    }
                    seenCharacters.insert(char) // 새 문자 저장
                }
                previousCharacter = char // 현재 문자를 이전 문자로 업데이트
            }
            
            return true
        }

        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var groupWordCount = 0
            
            for _ in 0..<n {
                if let word = readLine(), isGroupWord(word) {
                    groupWordCount += 1
                }
            }
            
            // 결과 출력
            print(groupWordCount)
        }
    }
}
