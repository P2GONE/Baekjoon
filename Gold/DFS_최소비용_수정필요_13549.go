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
		deque = deque[1:]
		if now == end {
			return dist[now]
		}
		newN1 = now + 1
		newN2 = now - 1
		newN3 = now * 2

		if newN3 <= max && dist[newN3] == -1 {
			dist[newN3] = dist[now]
			deque = append(deque, newN3)
		}
		if newN1 <= max && dist[newN1] == -1 {
			dist[newN1] = dist[now] + 1
			deque = append(deque, newN1)
		}
		if newN2 >= 0 && dist[newN2] == -1 {
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
