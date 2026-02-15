package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	defer writer.Flush()

	var total_num int
	fmt.Fscan(reader, &total_num)

	arr := make([]int, total_num)
	for i := 0; i < total_num; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	sort.Ints(arr) //introsort

	for i := 0; i < total_num; i++ {
		fmt.Fprintf(writer, "%d\n", arr[i])
	}
}
