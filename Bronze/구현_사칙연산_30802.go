package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	defer writer.Flush() // defer 예약자, 함수가 끝날 떄 실행됨

	var N int
	fmt.Fscan(reader, &N)

	sizes := make([]int, 6) // make 동적할당
	for i := 0; i < 6; i++ {
		fmt.Fscan(reader, &sizes[i])
	}

	var T, P int
	fmt.Fscan(reader, &T, &P)

	// 티셔츠: 각 사이즈별 ceil(s/T) 합산
	totalBundles := 0
	for _, s := range sizes { // go 슬라이스 순회
		totalBundles += (s + T - 1) / T
	}

	/*
		for (int i = 0; i < 6; i++) {
			totalBundles += (sizes[i] + T - 1) / T;
		}
	*/

	// 펜: 최대 묶음 수, 낱개 수
	penBundles := N / P
	penIndividual := N % P

	fmt.Fprintf(writer, "%d\n", totalBundles)
	fmt.Fprintf(writer, "%d %d\n", penBundles, penIndividual)
}
