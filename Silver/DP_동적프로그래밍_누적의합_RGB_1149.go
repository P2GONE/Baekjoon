package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	n := 0
	fmt.Fscan(reader, &n)
	arr := make([][]int, n)

	for i := 0; i < n; i++ {
		arr[i] = make([]int, 3)
		fmt.Fscan(reader, &arr[i][0], &arr[i][1], &arr[i][2])

	}

	dp := make([][]int, n)

	for i := 0; i < n; i++ {
		dp[i] = make([]int, 3)
	}

	dp[0][0] = arr[0][0]
	dp[0][1] = arr[0][1]
	dp[0][2] = arr[0][2]

	for i := 1; i < n; i++ {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0]
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1]
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2]
	}

	answer := min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2])
	fmt.Println(answer)

	writer.Flush()
}
