package main

import (
	"bufio"
	"fmt"
	"os"
)

// bag problem

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	N, K := 0, 0
	fmt.Fscan(reader, &N, &K)

	weights := make([]int, N)
	values := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &weights[i], &values[i])
	}

	dp := make([]int, K+1)

	for i := 0; i < N; i++ {
		// 역순으로 순회해야 같은 물건을 두 번 안 씀
		for w := K; w >= weights[i]; w-- {
			candidate := dp[w-weights[i]] + values[i]
			if candidate > dp[w] {
				dp[w] = candidate
			}
		}
	}

	fmt.Fprintln(writer, dp[K])

	writer.Flush()
}
