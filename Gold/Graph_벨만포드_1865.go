package main

import (
	"bufio"
	"fmt"
	"os"
)

type Edge struct {
	from int
	to   int
	cost int
}

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

const INF = 1 << 30

// Bellman-Ford
func bellmanFord(N int, edges []Edge) bool {

	dist := make([]int, N+1)

	for i := 1; i <= N; i++ {
		dist[i] = 0
	}

	for i := 1; i <= N; i++ {

		for _, e := range edges {

			if dist[e.to] > dist[e.from]+e.cost {

				dist[e.to] = dist[e.from] + e.cost

				if i == N {
					return true
				}
			}
		}
	}

	return false
}

func main() {

	defer writer.Flush()

	var TC int
	fmt.Fscan(reader, &TC)

	for t := 0; t < TC; t++ {

		var N, M, W int
		fmt.Fscan(reader, &N, &M, &W)

		edges := []Edge{}

		// 도로 (양방향)
		for i := 0; i < M; i++ {

			var S, E, T int
			fmt.Fscan(reader, &S, &E, &T)

			edges = append(edges, Edge{S, E, T})
			edges = append(edges, Edge{E, S, T})
		}

		// 웜홀 (단방향 음수)
		for i := 0; i < W; i++ {

			var S, E, T int
			fmt.Fscan(reader, &S, &E, &T)

			edges = append(edges, Edge{S, E, -T})
		}

		if bellmanFord(N, edges) {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}
