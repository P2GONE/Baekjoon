package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

type Board struct {
	n, m  int
	board [][]byte
}

func NewBoard() *Board {
	b := &Board{}
	fmt.Fscan(reader, &b.n, &b.m)

	b.board = make([][]byte, b.n)
	// char **board = (char **)malloc(sizeof(char *) * n);
	for i := 0; i < b.n; i++ {
		var s string
		fmt.Fscan(reader, &s)
		b.board[i] = []byte(s)
	}
	return b
}

// 특정 8x8 부분보드에서 최소 다시 칠할 개수
func (b *Board) countRepaint(startR, startC int) int {
	count := 0
	for i := 0; i < 8; i++ {
		for j := 0; j < 8; j++ {
			expected := byte('W')
			if (i+j)%2 == 1 {
				expected = 'B'
			}
			if b.board[startR+i][startC+j] != expected {
				count++
			}
		}
	}
	// 패턴1 vs 패턴2 (반전)
	return min(count, 64-count)
}

// 모든 8x8 부분보드 탐색
func (b *Board) MinRepaint() int {
	result := 64
	for i := 0; i <= b.n-8; i++ {
		for j := 0; j <= b.m-8; j++ {
			cnt := b.countRepaint(i, j)
			if cnt < result {
				result = cnt
			}
		}
	}
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	b := NewBoard()
	fmt.Println(b.MinRepaint())
}
