package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	x, y  int
	breakWall int
	dist  int
}

var reader = bufio.NewReader(os.Stdin)

func BFS(graph [][]int, N, M int) int {

	// visited[x][y][wall]
	visited := make([][][]bool, N)
	for i := 0; i < N; i++ {
		visited[i] = make([][]bool, M)
		for j := 0; j < M; j++ {
			visited[i][j] = make([]bool, 2)
		}
	}

	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, -1, 1}

	queue := []Node{{0, 0, 0, 1}}
	visited[0][0][0] = true

	for len(queue) > 0 {

		cur := queue[0]
		queue = queue[1:]

		x := cur.x
		y := cur.y
		wall := cur.breakWall
		dist := cur.dist

		// 도착
		if x == N-1 && y == M-1 {
			return dist
		}

		for d := 0; d < 4; d++ {

			nx := x + dx[d]
			ny := y + dy[d]

			if nx < 0 || ny < 0 || nx >= N || ny >= M {
				continue
			}

			// 빈칸
			if graph[nx][ny] == 0 && !visited[nx][ny][wall] {
				visited[nx][ny][wall] = true
				queue = append(queue, Node{nx, ny, wall, dist + 1})
			}

			// 벽인데 아직 안부숨
			if graph[nx][ny] == 1 && wall == 0 {
				if !visited[nx][ny][1] {
					visited[nx][ny][1] = true
					queue = append(queue, Node{nx, ny, 1, dist + 1})
				}
			}
		}
	}

	return -1
}

func main() {

	var N, M int
	fmt.Fscan(reader, &N, &M)

	graph := make([][]int, N)

	for i := 0; i < N; i++ {

		var row string
		fmt.Fscan(reader, &row)

		graph[i] = make([]int, M)

		for j := 0; j < M; j++ {
			graph[i][j] = int(row[j] - '0')
		}
	}

	fmt.Println(BFS(graph, N, M))
}
