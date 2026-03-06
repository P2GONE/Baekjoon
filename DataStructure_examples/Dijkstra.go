package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

const INF = int(1e9)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

// 우선순위 큐 정의
type Item struct {
	node, cost int
}

type PQ []Item

func (pq PQ) Len() int            { return len(pq) }
func (pq PQ) Less(i, j int) bool  { return pq[i].cost < pq[j].cost } // 비용 작은게 우선
func (pq PQ) Swap(i, j int)       { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PQ) Push(x interface{}) { *pq = append(*pq, x.(Item)) }
func (pq *PQ) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[:n-1]
	return x
}

func main() {
	defer writer.Flush()

	var V, E, K int
	fmt.Fscan(reader, &V, &E)
	fmt.Fscan(reader, &K)

	// 인접 리스트
	graph := make([][][]int, V+1)
	for i := 0; i < E; i++ {
		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)
		graph[u] = append(graph[u], []int{v, w}) // 단방향
	}

	// 다익스트라
	dist := make([]int, V+1)
	for i := range dist {
		dist[i] = INF
	}
	dist[K] = 0

	pq := &PQ{{K, 0}}
	heap.Init(pq)

	for pq.Len() > 0 {
		cur := heap.Pop(pq).(Item)
		node, cost := cur.node, cur.cost

		// 이미 더 짧은 경로로 방문했으면 스킵
		if cost > dist[node] {
			continue
		}

		for _, edge := range graph[node] {
			next, w := edge[0], edge[1]
			newCost := cost + w
			if newCost < dist[next] {
				dist[next] = newCost
				heap.Push(pq, Item{next, newCost})
			}
		}
	}

	// 출력
	for i := 1; i <= V; i++ {
		if dist[i] == INF {
			fmt.Fprintln(writer, "INF")
		} else {
			fmt.Fprintln(writer, dist[i])
		}
	}
}
