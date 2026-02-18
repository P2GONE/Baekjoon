package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func calc(board_n []int, board_m []int) {
	defer writer.Flush()
	count := make(map[int]int)

	for _, v := range board_n {
		count[v]++
	}
	// count[v]에서 각각 몇개 있는지 저장, map이기에 자동으로 중복제거

	for i, v := range board_m {
		if i > 0 {
			fmt.Fprint(writer, " ")
		}
		fmt.Fprint(writer, count[v])

		// 기준점인 v값 해당 값의 key값 출력
	}
	fmt.Fprintln(writer)

}

func main() {

	n := 0
	m := 0

	fmt.Fscan(reader, &n)
	board_n := make([]int, n)
	for i := range board_n {
		fmt.Fscan(reader, &board_n[i])
	}

	fmt.Fscan(reader, &m)
	board_m := make([]int, m)
	for i := range board_m {
		fmt.Fscan(reader, &board_m[i])
	}

	calc(board_n, board_m)
}
