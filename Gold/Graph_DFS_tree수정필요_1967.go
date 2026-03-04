package main

import (
	"fmt"
)

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

func (g *Graph) dfs(node, parent int) int {

	longest := 0
	second := 0

	for _, e := range g.adj[node] {

		next := e.to
		weight := e.w

		if next == parent {
			continue
		}

		length := g.dfs(next, node) + weight

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

	var n int
	fmt.Scan(&n)

	g := NewGraph(n + 1)

	for i := 0; i < n; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)

		g.AddEdge(u, v, w)
	}

	diameter = 0
	g.dfs(0, -1)

	fmt.Println(diameter)
}
