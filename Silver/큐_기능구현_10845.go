package main

import (
	"bufio"
	"fmt"
	"os"
)

type Queue []interface{}

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

// Enqueue
func (q *Queue) Enqueue(data interface{}) {
	*q = append(*q, data)
}

// Dequeue
func (q *Queue) Dequeue() interface{} {
	if q.IsEmpty() {
		fmt.Fprintln(writer, -1)
		return nil
	}
	data := (*q)[0]
	*q = (*q)[1:]
	fmt.Fprintln(writer, data)
	return data
}

// Size
func (q *Queue) Size() int {
	return len(*q)
}

// IsEmpty
func (q *Queue) IsEmpty() bool {
	return len(*q) == 0
}

// Front
func (q *Queue) Front() interface{} {
	if q.IsEmpty() {
		fmt.Fprintln(writer, -1)
		return nil
	}
	fmt.Fprintln(writer, (*q)[0])
	return (*q)[0]
}

// Back
func (q *Queue) Back() interface{} {
	if q.IsEmpty() {
		fmt.Fprintln(writer, -1)
		return nil
	}
	fmt.Fprintln(writer, (*q)[len(*q)-1])
	return (*q)[len(*q)-1]
}

func main() {
	defer writer.Flush()

	N := 0
	fmt.Fscan(reader, &N)
	q := make(Queue, 0, N)
	command := ""

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &command)
		switch command {
		case "push":
			var data int
			fmt.Fscan(reader, &data)
			q.Enqueue(data)
		case "pop":
			q.Dequeue()
		case "size":
			fmt.Fprintln(writer, q.Size())
		case "empty":
			if q.IsEmpty() {
				fmt.Fprintln(writer, 1)
			} else {
				fmt.Fprintln(writer, 0)
			}
		case "front":
			q.Front()
		case "back":
			q.Back()
		}
	}
}
