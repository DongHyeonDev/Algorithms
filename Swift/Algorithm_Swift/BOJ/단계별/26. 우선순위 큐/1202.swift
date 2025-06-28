//
//  1202.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1202
//  알고리즘 분류: 자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐

// 보석을 나타내는 구조체
struct Jewel: Comparable {
    let weight: Int
    let value: Int
    
    static func < (lhs: Jewel, rhs: Jewel) -> Bool {
        return lhs.weight < rhs.weight
    }
}

class BOJ1202: Solvable {
    // 메모리: 102876KB, 시간: 196ms, 코드 길이: 899B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let k = fileIO.readInt()

        // 보석 정보 입력
        var jewels: [Jewel] = []
        for _ in 0..<n {
            let weight = fileIO.readInt()
            let value = fileIO.readInt()
            jewels.append(Jewel(weight: weight, value: value))
        }

        // 가방 용량 입력
        var bags: [Int] = []
        for _ in 0..<k {
            bags.append(fileIO.readInt())
        }

        // 보석을 무게 기준으로 오름차순 정렬
        jewels.sort()

        // 가방을 용량 기준으로 오름차순 정렬
        bags.sort()

        var maxHeap = MaxHeap()  // 가격을 저장하는 최대 힙
        var jewelIndex = 0
        var totalValue = 0

        // 각 가방에 대해 처리
        for bagCapacity in bags {
            // 현재 가방에 넣을 수 있는 모든 보석을 힙에 추가
            while jewelIndex < jewels.count && jewels[jewelIndex].weight <= bagCapacity {
                maxHeap.insert(jewels[jewelIndex].value)
                jewelIndex += 1
            }
            
            // 힙에서 가장 비싼 보석을 선택
            if let maxValue = maxHeap.extractMax() {
                totalValue += maxValue
            }
        }

        print(totalValue)
    }
}
