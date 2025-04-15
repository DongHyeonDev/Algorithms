//
//  28279.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/28279
//  알고리즘 분류: 자료 구조, 덱

class BOJ28279: Solvable {
    // 메모리: 111808KB, 시간: 204ms, 코드 길이: 2464B
    func run() {
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt() // 명령 수 입력
        var deque = Deque<Int>() // 덱 초기화
        var output = "" // 결과 문자열

        // 명령 처리
        for _ in 0..<n {
            let cmd = fileIO.readInt()

            switch cmd {
            case 1:
                deque.pushFront(fileIO.readInt()) // 1 X: 앞에 삽입
            case 2:
                deque.pushBack(fileIO.readInt()) // 2 X: 뒤에 삽입
            case 3:
                output += "\(deque.popFront() ?? -1)\n" // 3: 앞 제거
            case 4:
                output += "\(deque.popBack() ?? -1)\n" // 4: 뒤 제거
            case 5:
                output += "\(deque.count)\n" // 5: 개수 출력
            case 6:
                output += deque.isEmpty ? "1\n" : "0\n" // 6: 비었는지 확인
            case 7:
                output += "\(deque.front() ?? -1)\n" // 7: 앞 요소 조회
            case 8:
                output += "\(deque.back() ?? -1)\n" // 8: 뒤 요소 조회
            default:
                break
            }
        }

        print(output) // 결과 출력
    }
}
