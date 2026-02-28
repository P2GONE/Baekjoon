package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func power(a, b, mod int64) int64 {
	result := int64(1)
	a %= mod
	for b > 0 {
		if b&1 == 1 {
			result = result * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return result
}

func main() {
	defer writer.Flush()
	var A, B, C int64
	fmt.Fscan(reader, &A, &B, &C)
	fmt.Fprintln(writer, power(A, B, C))
}
