package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

const INF = 1 << 30

type Edge struct{ to, cost int }
type PQ []Edge

func (pq PQ) Len() int            { return len(pq) }
func (pq PQ) Less(i, j int) bool  { return pq[i].cost < pq[j].cost }
func (pq PQ) Swap(i, j int)       { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PQ) Push(x interface{}) { *pq = append(*pq, x.(Edge)) }
func (pq *PQ) Pop() interface{} {
	old := *pq
	x := old[len(old)-1]
	*pq = old[:len(old)-1]
	return x
}

var V, E, K int

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

func main() {
	defer writer.Flush()

	var V, E, K int
	fmt.Fscan(reader, &V, &E, &K)

	graph := make([][]Edge, V+1)
	for i := 0; i < E; i++ {
		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)
		graph[u] = append(graph[u], Edge{v, w})
	}

	dist := make([]int, V+1)
	for i := range dist {
		dist[i] = INF
	}

	dijkstra(K, graph, dist)

	for i := 1; i <= V; i++ {
		if dist[i] == INF {
			fmt.Fprintln(writer, "INF")
		} else {
			fmt.Fprintln(writer, dist[i])
		}
	}

}
