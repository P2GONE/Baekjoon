package main

import "fmt"

type Graph struct {
	vert int
	adj  [][]int
}

func NewGraph(v int) *Graph {
	return &Graph{
		vert: v,
		adj:  make([][]int, v),
	}
}

func (g *Graph) AddEdge(u, v int) {
	g.adj[u] = append(g.adj[u], v)
	g.adj[v] = append(g.adj[v], u) // 무방향 그래프
}

func (g *Graph) DFS(start int) {
	visited := make([]bool, g.vert)
	g.dfsUtil(start, visited)
}

func (g *Graph) dfsUtil(node int, visited []bool) {
	visited[node] = true
	fmt.Print(node, " ")

	for _, next := range g.adj[node] {
		if !visited[next] {
			g.dfsUtil(next, visited)
		}
	}
}

func main() {

	g := NewGraph(6)

	g.AddEdge(0, 1)
	g.AddEdge(0, 2)
	g.AddEdge(1, 3)
	g.AddEdge(1, 4)
	g.AddEdge(2, 5)

	fmt.Print("DFS: ")
	g.DFS(0)

}
