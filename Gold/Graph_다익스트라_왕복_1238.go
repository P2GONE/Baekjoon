package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type Edge struct{ to, cost int }
type PQ []Edge

func (pq PQ) Len() int           { return len(pq) }
func (pq PQ) Less(i, j int) bool { return pq[i].cost < pq[j].cost }
func (pq PQ) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PQ) Push(x interface{}) {
	*pq = append(*pq, x.(Edge))
}

func (pq *PQ) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[:n-1]
	return item
}

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

const INF = 1 << 30

var V, E, W int

// --- 다익스트라 ---
func dijkstra(start int, graph [][]Edge, dist []int) {
	dist[start] = 0
	pq := &PQ{{start, 0}}
	heap.Init(pq)

	for pq.Len() > 0 {
		cur := heap.Pop(pq).(Edge)
		if cur.cost > dist[cur.to] {
			continue
		}
		for _, next := range graph[cur.to] {
			if newCost := cur.cost + next.cost; newCost < dist[next.to] {
				dist[next.to] = newCost
				heap.Push(pq, Edge{next.to, newCost})
			}
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {

	defer writer.Flush()

	var N, M, X int
	fmt.Fscan(reader, &N, &M, &X)

	graph := make([][]Edge, N+1)
	graph_reverse := make([][]Edge, N+1)

	for i := 0; i < M; i++ {
		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)

		graph[u] = append(graph[u], Edge{v, w})
		graph_reverse[v] = append(graph_reverse[v], Edge{u, w})
	}

	dist := make([]int, N+1)
	dist_reverse := make([]int, N+1)

	for i := 1; i <= N; i++ {
		dist[i] = INF
		dist_reverse[i] = INF
	}

	dijkstra(X, graph, dist)
	dijkstra(X, graph_reverse, dist_reverse)

	answer := 0
	for i := 1; i <= N; i++ {
		if dist[i] != INF && dist_reverse[i] != INF {
			answer = max(answer, dist[i]+dist_reverse[i])
		}
	}

	fmt.Fprintln(writer, answer)
}
