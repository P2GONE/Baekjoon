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

// --- Bellman-Ford ---
func bellmanFord(start int, N int, edges []Edge, dist []int) bool {

	dist[start] = 0

	for i := 1; i <= N; i++ {

		for _, e := range edges {

			if dist[e.from] == INF {
				continue
			}

			if dist[e.to] > dist[e.from]+e.cost {

				dist[e.to] = dist[e.from] + e.cost

				// N번째에도 갱신되면 음수 사이클
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

	var N, M int
	fmt.Fscan(reader, &N, &M)

	edges := []Edge{}

	for i := 0; i < M; i++ {

		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)

		edges = append(edges, Edge{u, v, w})
	}

	dist := make([]int, N+1)

	for i := 1; i <= N; i++ {
		dist[i] = INF
	}

	negativeCycle := bellmanFord(1, N, edges, dist)

	if negativeCycle {
		fmt.Fprintln(writer, "Negative Cycle Exists")
	} else {

		for i := 1; i <= N; i++ {

			if dist[i] == INF {
				fmt.Fprintln(writer, "INF")
			} else {
				fmt.Fprintln(writer, dist[i])
			}

		}
	}
}
