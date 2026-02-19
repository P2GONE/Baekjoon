package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

type BinaryTree struct {
	root *BinaryNode
}

type BinaryNode struct {
	data  string
	left  *BinaryNode
	right *BinaryNode
}

func (b *BinaryTree) insert(data string) {
	if b.root == nil {
		b.root = &BinaryNode{data: data}
		return
	}
	b.root.insert(data)
}
func (b *BinaryNode) insert(data string) {
	if b == nil {
		return
	}
	if data <= b.data {
		if b.left == nil {
			b.left = &BinaryNode{data: data}
			return
		}
		b.left.insert(data)
	} else {
		if b.right == nil {
			b.right = &BinaryNode{data: data}
			return
		}
		b.right.insert(data)
	}
}

// VLR
func (b *BinaryTree) preOrder() {
	if b.root == nil {
		return
	}
	b.root.preOrder()
	writer.WriteString("\n")
	writer.Flush()
}
func (b *BinaryNode) preOrder() {
	if b == nil {
		return
	}
	writer.WriteString(b.data) 	// 현재 출력
	//writer.WriteString(" ")
	b.left.preOrder()  			// 왼쪽으로
	b.right.preOrder() 			// 오른쪽으로
}

// LVR
func (b *BinaryTree) inOrder() {
	if b.root == nil {
		return
	}
	b.root.inOrder()
	writer.WriteString("\n")
	writer.Flush()
}
func (b *BinaryNode) inOrder() {
	if b == nil {
		return
	}
	b.left.inOrder()           	// 왼쪽으로
	writer.WriteString(b.data) 	// 현재 출력
	//writer.WriteString(" ")
	b.right.inOrder() 			// 오른쪽으로
}

// LRV
func (b *BinaryTree) postOrder() {
	if b.root == nil {
		return
	}
	b.root.postOrder()
	writer.WriteString("\n")
	writer.Flush()
}
func (b *BinaryNode) postOrder() {
	if b == nil {
		return
	}
	b.left.postOrder()         // 왼쪽으로
	b.right.postOrder()        // 오른쪽으로
	writer.WriteString(b.data) // 현재 출력
	//writer.WriteString(" ")
}

func main() {
	tree := &BinaryTree{}
	var N int
	var node, L, R string

	nodes := make(map[string]*BinaryNode)

	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &node, &L, &R)

		// 노드가 없으면 새로 생성
		if _, ok := nodes[node]; !ok {
			nodes[node] = &BinaryNode{data: node}
		}
		cur := nodes[node]

		if L != "." {
			if _, ok := nodes[L]; !ok {
				nodes[L] = &BinaryNode{data: L}
			}
			cur.left = nodes[L]
		}
		if R != "." {
			if _, ok := nodes[R]; !ok {
				nodes[R] = &BinaryNode{data: R}
			}
			cur.right = nodes[R]
		}
	}

	tree.root = nodes["A"]

	tree.preOrder()
	tree.inOrder()
	tree.postOrder()
}
