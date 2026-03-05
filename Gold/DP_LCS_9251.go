package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

// LCS
func LCS(a, b string) {
	n := len(a)
	m := len(b)

	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if a[i-1] == b[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
				continue
			}
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])
		}
	}

	fmt.Println(dp[n][m])
}

func main() {
	var a, b string
	fmt.Fscan(reader, &a, &b)

	LCS(a, b)
}
