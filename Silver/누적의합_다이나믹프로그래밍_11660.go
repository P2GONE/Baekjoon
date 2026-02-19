package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

/* 시간초과
func main() {
	N, M := 0, 0
	fmt.Fscan(reader, &N, &M)
	board := make([][]int, N)

	for i := 0; i < N; i++ {
		board[i] = make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Fscan(reader, &board[i][j])
		}
	}

	x1, x2, y1, y2 := 0, 0, 0, 0
	calc := 0

	for i := 0; i < M; i++ {
		fmt.Fscan(reader, &x1, &y1, &x2, &y2)
		for i := x1 - 1; i < x2; i++ {
			for j := y1 - 1; j < y2; j++ {
				calc += board[i][j]
			}
		}
		fmt.Fprintln(writer, calc)
		calc = 0
	}
	writer.Flush()

}
*/

func input(N int) [][]int {
	board := make([][]int, N+1)
	for i := 1; i < N+1; i++ {
		board[i] = make([]int, N+1)
		for j := 1; j < N+1; j++ {
			fmt.Fscan(reader, &board[i][j])
		}
	}
	return board
}

func BuildPrefix(board [][]int) [][]int {
	N := len(board) - 1
	prefix := make([][]int, N+1)

	for i := 0; i < N+1; i++ {
		prefix[i] = make([]int, N+1)
	}

	for i := 1; i < N+1; i++ {
		for j := 1; j < N+1; j++ {
			prefix[i][j] = board[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
		}
	}
	return prefix
}
func main() {
	N, M := 0, 0
	fmt.Fscan(reader, &N, &M)

	board := input(N)
	prefix := BuildPrefix(board)

	for i := 0; i < M; i++ {
		x1, x2, y1, y2 := 0, 0, 0, 0
		fmt.Fscan(reader, &x1, &y1, &x2, &y2)
		fmt.Fprintln(writer, prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1])
	}

	writer.Flush()
}
