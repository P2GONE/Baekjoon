package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	defer writer.Flush()

	N, K, idx := 0, 0, 0
	fmt.Fscan(reader, &N, &K)
	board := make([]int, N)
	for i := range board {
		board[i] = i + 1
	}

	fmt.Fprint(writer, "<")
	for len(board) > 0 {
		idx = (idx + K - 1) % len(board)
		if len(board) == 1 {
			fmt.Fprintf(writer, "%d>", board[idx])
			break
		} else {
			fmt.Fprintf(writer, "%d, ", board[idx])
			board = append(board[:idx], board[idx+1:]...)
		}
	}
	fmt.Fprintln(writer)
}
