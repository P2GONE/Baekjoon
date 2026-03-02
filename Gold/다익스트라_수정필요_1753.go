package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

var V, E, K int

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &V, &E)
	fmt.Fscan(reader, &K)

	graph := make([][][]int, V+1)
	for i := 0; i < E; i++ {
		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)
		graph[u] = append(graph[u], []int{v, w})
		graph[v] = append(graph[v], []int{u, w})
	}

}
