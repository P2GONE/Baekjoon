package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func calc(arr [][]int, n int) {
	// DP
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, i+1)
	}
	dp[0][0] = arr[0][0]

	for i := 1; i < n; i++ {
		for j := 0; j <= i; j++ {
			left, right := 0, 0
			if j > 0 {
				left = dp[i-1][j-1]
			}
			if j < i {
				right = dp[i-1][j]
			}
			dp[i][j] = arr[i][j] + max(left, right)
		}
	}
	// dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j])

	ans := 0
	for i := 0; i < n; i++ {
		if dp[n-1][i] > ans {
			ans = dp[n-1][i]
		}
	}
	fmt.Fprintln(writer, ans)

}

func main() {
	n := 0
	fmt.Fscan(reader, &n)
	arr := make([][]int, n)

	for i := 0; i < n; i++ {
		arr[i] = make([]int, i+1) // i번째 행은 i+1개
		for j := 0; j < i+1; j++ {
			fmt.Fscan(reader, &arr[i][j])
		}
	}

	calc(arr, n)

	writer.Flush()
}
