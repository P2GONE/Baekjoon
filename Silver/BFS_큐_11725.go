package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

// BFS
func BFS(graph [][]int, parent []int, visited []bool) {
	queue := []int{1}
	visited[1] = true
	parent[1] = -1

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]
		fmt.Println(cur)
		for _, next := range graph[cur] {
			if !visited[next] {
				visited[next] = true
				parent[next] = cur
				queue = append(queue, next)
			}
		}
	}
}

// DFS

func main() {
	defer writer.Flush()

	N := 0
	fmt.Fscan(reader, &N)

	graph := make([][]int, N+1) // 인접 리스트
	for i := 0; i < N-1; i++ {
		l, r := 0, 0
		fmt.Fscan(reader, &l, &r)
		graph[l] = append(graph[l], r)
		graph[r] = append(graph[r], l)
	}

	parent := make([]int, N+1)
	visited := make([]bool, N+1)

	BFS(graph, parent, visited)

	for i := 2; i <= N; i++ {
		fmt.Fprintln(writer, parent[i])
	}
}
