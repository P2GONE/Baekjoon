package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var globalCount int

// N-Queen Backtracking
/*
1. 한 행(row)에 하나의 Queen만 둔다
2. 다음 행으로 내려가며 배치
3. 공격 가능하면 되돌아감 (backtrack)
*/
func Nqueen(N int) {
	row := make([]int, N)
	putQueen(0, N, row)
}

func putQueen(row int, N int, rowArr []int) {
	if row == N {
		globalCount++
		return
	}

	for i := 0; i < N; i++ {
		rowArr[row] = i
		if isPromising(row, rowArr) {
			putQueen(row+1, N, rowArr)
		}
	}
	return
}

func isPromising(row int, rowArr []int) bool {
	for i := 0; i < row; i++ {
		if rowArr[i] == rowArr[row] || rowArr[i]+i == rowArr[row]+row || rowArr[i]-i == rowArr[row]-row {
			return false
		}
	}
	return true
}

func main() {
	var N int
	fmt.Fscan(reader, &N)
	Nqueen(N)

	fmt.Fprintln(writer, globalCount)
	writer.Flush()

}
