package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var s [1010]string
	var z string = ""
	n := 0
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i] = scanner.Text()
		s[i] = reverse_str(s[i])

	}

	for i := 0; i < n; i++ {
		if i == 0 {
			z = s[i]
			continue
		}
		var slen int = 0
		if len(z) > len(s[i]) {
			slen = len(s[i])
		} else {
			slen = len(z)
		}

		t := ""
		for j := 0; j < slen; j++ {
			if s[i][j] == z[j] {
				t = t + string(s[i][j])
			} else {
				z = t
				break
			}
		}
	}

	zlen := len(z)
	if zlen > 0 {
		for i := zlen - 1; i >= 0; i-- {
			fmt.Printf("%s", string(z[i]))
		}
	} else {
		fmt.Print("nai")
	}

}

func reverse_str(str string) string {
	result := ""
	slen := len(str)
	num := 0
	for i := slen - 1; i >= 0; i-- {
		result = result + string(str[i])
		num++
	}
	return result
}
