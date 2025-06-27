//
//  2696.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2696
//  알고리즘 분류: 자료 구조, 우선순위 큐

// 중앙값을 찾는 클래스
class MedianFinder {
    private var maxHeap = MaxHeap()  // 작은 절반을 저장
    private var minHeap = MinHeap()  // 큰 절반을 저장
    
    func addNumber(_ num: Int) {
        // 첫 번째 수거나 maxHeap의 최대값보다 작으면 maxHeap에 추가
        if maxHeap.isEmpty || num <= maxHeap.peek()! {
            maxHeap.insert(num)
        } else {
            minHeap.insert(num)
        }
        
        // 힙의 균형을 맞춤
        balanceHeaps()
    }
    
    private func balanceHeaps() {
        // maxHeap이 minHeap보다 2개 이상 많으면 하나를 이동
        if maxHeap.count > minHeap.count + 1 {
            if let max = maxHeap.extractMax() {
                minHeap.insert(max)
            }
        }
        // minHeap이 maxHeap보다 많으면 하나를 이동
        else if minHeap.count > maxHeap.count {
            if let min = minHeap.extractMin() {
                maxHeap.insert(min)
            }
        }
    }
    
    func findMedian() -> Int {
        // maxHeap의 크기가 더 크거나 같으므로 maxHeap의 최대값이 중앙값
        return maxHeap.peek()!
    }
}

class BOJ2696: Solvable {
    // 메모리: 79888KB, 시간: 16ms, 코드 길이: 1851B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let T = fileIO.readInt()
            
        for _ in 0..<T {
            let M = fileIO.readInt()
            
            let medianFinder = MedianFinder()
            var medians: [Int] = []
            
            // 숫자를 하나씩 읽어들이면서 홀수 번째마다 중앙값 계산
            for i in 0..<M {
                let number = fileIO.readInt()
                medianFinder.addNumber(number)
                
                // 홀수 번째 (1-based index이므로 i+1이 홀수인지 확인)
                if (i + 1) % 2 == 1 {
                    medians.append(medianFinder.findMedian())
                }
            }
            
            // 결과 출력
            print(medians.count)
            
            // 한 줄에 10개씩 출력
            for i in 0..<medians.count {
                if i > 0 && i % 10 == 0 {
                    print()
                }
                if i % 10 == 0 {
                    print(medians[i], terminator: "")
                } else {
                    print(" \(medians[i])", terminator: "")
                }
            }
            print() // 마지막 줄바꿈
        }
    }
}
