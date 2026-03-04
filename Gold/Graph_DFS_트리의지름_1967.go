package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

type Edge struct {
	to int
	w  int
}

type Graph struct {
	vert int
	adj  [][]Edge
}

func NewGraph(v int) *Graph {
	return &Graph{
		vert: v,
		adj:  make([][]Edge, v),
	}
}

func (g *Graph) AddEdge(u, v, w int) {
	g.adj[u] = append(g.adj[u], Edge{v, w})
	g.adj[v] = append(g.adj[v], Edge{u, w})
}

var diameter int

func (g *Graph) dfsUtil(node, parent int) int {

	longest := 0
	second := 0

	for _, e := range g.adj[node] {

		next := e.to
		weight := e.w

		if next == parent {
			continue
		}

		length := g.dfsUtil(next, node) + weight

		if length > longest {
			second = longest
			longest = length
		} else if length > second {
			second = length
		}
	}

	if longest+second > diameter {
		diameter = longest + second
	}

	return longest
}

func main() {
	defer writer.Flush()

	n := 0
	fmt.Fscan(reader, &n)

	g := NewGraph(n + 1)

	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Fscan(reader, &u, &v, &w)

		g.AddEdge(u, v, w)
	}

	diameter = 0
	g.dfsUtil(1, -1)

	fmt.Fprintln(writer, diameter)
}
