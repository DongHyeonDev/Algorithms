//
//  18258.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/18258
//  알고리즘 분류: 자료 구조, 큐

class BOJ18258: Solvable {
    // 메모리: 149944KB, 시간: 332ms, 코드 길이: 2960B
    func run() {
        // 빠른 출력을 위한 설정
        let fileIO = RhynoFileIO()
        var output = ""

        // 명령 수 읽기
        let n = fileIO.readInt()

        var queue = Queue()

        for _ in 0..<n {
            let command = fileIO.readString()
            
            switch command {
            case "push":
                let x = fileIO.readInt()
                queue.enqueue(x)
            case "pop":
                output += "\(queue.dequeue())\n"
            case "size":
                output += "\(queue.size())\n"
            case "empty":
                output += "\(queue.isEmpty() ? 1 : 0)\n"
            case "front":
                output += "\(queue.front())\n"
            case "back":
                output += "\(queue.back())\n"
            default:
                break
            }
        }

        // 한 번에 출력
        print(output, terminator: "")
    }
}
