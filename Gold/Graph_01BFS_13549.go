package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

var N, K, newN1, newN2, newN3 int

func bfs01(start, end int) int {
	max := 100000
	dist := make([]int, max+1)
	for i := 0; i <= max; i++ {
		dist[i] = -1
	}
	dist[start] = 0
	deque := []int{start}

	for len(deque) > 0 {
		now := deque[0]
		INF := 1 << 30
		for i := range dist {
			if dist[i] == -1 {
				dist[i] = INF
			}
		}
		deque = deque[1:]
		if now == end {
			return dist[now]
		}
		newN1 := now + 1
		newN2 := now - 1
		newN3 := now * 2

		// 비용이 0인 것은 front, 비용이 드는것은 back에 넣는다.
		// ...은 슬라이스를 펼쳐서 개별 원소로 전달하는 문법이다
		if newN3 <= max && dist[now] < dist[newN3] {
			dist[newN3] = dist[now]
			deque = append([]int{newN3}, deque...)
		}
		if newN1 <= max && dist[now]+1 < dist[newN1] {
			dist[newN1] = dist[now] + 1
			deque = append(deque, newN1)
		}
		if newN2 >= 0 && dist[now]+1 < dist[newN2] {
			dist[newN2] = dist[now] + 1
			deque = append(deque, newN2)
		}

	}
	return -1
}

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &N, &K)
	fmt.Println(bfs01(N, K))

}
