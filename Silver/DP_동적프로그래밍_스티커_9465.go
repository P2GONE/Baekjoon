package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

// dp

func calc(n int) {
	// 입력받기
	board := make([][]int, 2)
	for i := 0; i < 2; i++ {
		board[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Fscan(reader, &board[i][j])
		}
	}

	dp := make([][3]int, n)
	dp[0][0] = 0
	dp[0][1] = board[0][0] // 1열 위쪽
	dp[0][2] = board[1][0] // 1열 아래쪽

	for i := 1; i < n; i++ {
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]))
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + board[0][i]
		// 위쪽을 선택하면 이전 열 위쪽 dp[i-1][1]이랑 변을 공유하므로 제외
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + board[1][i]
		// 아래쪽을 선택하면 이전 열 아래쪽  dp[i-1][2]이랑 변을 공유하므로 제외
	}

	fmt.Println(max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])))

}

func main() {
	T, n := 0, 0
	fmt.Fscan(reader, &T)

	for i := 0; i < T; i++ {
		fmt.Fscan(reader, &n)
		calc(n)
	}

	writer.Flush()
}
