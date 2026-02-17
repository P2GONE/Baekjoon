package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

func calc(board []string) {

	for _, line := range board { // 한 줄을 line이라고 생각
		stack := []rune{}
		valid := true

		for _, char := range line {
			if char == '(' {
				stack = append(stack, char) // push
			} else if char == ')' {
				if len(stack) > 0 {
					stack = stack[:len(stack)-1] // pop
				} else {
					valid = false
					break
				}
			}
		}

		if valid && len(stack) == 0 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func main() {
	var n int
	fmt.Fscan(reader, &n)

	board := make([]string, n)

	for i := range board {
		fmt.Fscan(reader, &board[i])
	}

	calc(board)
}
