package main

import "fmt"

func BFS(graph [][]int, start int) {
	visited := make([]bool, len(graph))

	queue := []int{start}
	visited[start] = true

	for len(queue) > 0 {
		// 큐에서 하나 꺼냄
		node := queue[0]
		queue = queue[1:]

		fmt.Print(node, " ")

		// 인접 노드 탐색
		for _, next := range graph[node] {
			if !visited[next] {
				visited[next] = true
				queue = append(queue, next)
			}
		}
	}
}

func main() {
	graph := [][]int{
		{1, 2},    // 0
		{0, 3, 4}, // 1
		{0, 5},    // 2
		{1},       // 3
		{1, 5},    // 4
		{2, 4},    // 5
	}

	BFS(graph, 0)
}
