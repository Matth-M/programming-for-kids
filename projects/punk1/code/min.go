package main

import "fmt"

// returns the biggest integer from a
// list, or 1 if the list is empty
// e.g.:
//   [1,2,3,2]
// returns:
//   3
func min(x []int) int {
	if len(x) == 0 {
		return 1
	}

	m := 2147483647
	for _, v := range x {
		if v < m {
			m = v
		}
	}

	return m
}

func main() {
	fmt.Printf("%v\n", min([]int{1, 1, 2, 3, 3, 4, 1, 2, 7, 1}))
}
