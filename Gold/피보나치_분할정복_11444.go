package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

const MOD int64 = 1000000007

// 모듈러 거듭제곱

func fib(n int64) (int64, int64) {

	if n == 0 {
		return 0, 1
	}

	a, b := fib(n / 2)

	c := (a * ((2*b%MOD - a + MOD) % MOD)) % MOD
	d := (a*a%MOD + b*b%MOD) % MOD

	if n%2 == 0 {
		return c, d
	}

	return d, (c + d) % MOD
}

func main() {

	defer writer.Flush()

	var n int64
	fmt.Fscan(reader, &n)

	result, _ := fib(n)

	fmt.Fprintln(writer, result)
}
