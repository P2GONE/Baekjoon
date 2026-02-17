package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

func calc(board []int) int {
	for len(board) > 1 {
		board = board[1:]                   // 첫 번째 삭제
		board = append(board[1:], board[0]) // 두 번째를 맨 뒤로
	}
	return board[0]
}

func main() {
	var n int
	fmt.Fscan(reader, &n)

	board := make([]int, n)

	for i := range board {
		board[i] = i + 1
	}

	result := calc(board)
	fmt.Println(result)

}
