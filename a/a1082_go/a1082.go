package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	result := ""
	num := []string{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}
	// wei := []string{"Shi", "Bai", "Qian", "Wan", "Yi"}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()

	if str == "0" || str == "-0" {
		fmt.Print("ling")
		return
	}

	slen := len(str)

	left := 0
	if str[0] == '-' {
		result += "Fu "
		left++
	}

	var wflag bool = true

	if slen-left >= 9 {
		if str[0+left] != '0' && str[1+left] == '0' && str[2+left] == '0' && str[3+left] == '0' && str[4+left] == '0' {
			wflag = false
		}
	}

	rr := make([]string, slen)
	no := 0
	for i := slen - 1; i >= left; i-- {
		n, _ := strconv.Atoi(string(str[i]))
		rr[no] = num[n]
		no++
	}

	for i := 0; i < slen-left; i++ {
		if i == 0 && rr[i] == "ling" {
			rr[i] = "a"
		} else if i != 0 && rr[i] == "ling" && rr[i-1] != "ling" && rr[i-1] != "b" && rr[i-1] != "a" {
			rr[i] = "b"
		} else if i != 0 && rr[i] == "ling" && (rr[i-1] == "b" || rr[i-1] == "a") {
			rr[i] = "a"
		}
	}

	vv := make([]string, 100)
	vi := 0
	for i := 0; i < slen-left; i++ {
		if i == 8 && rr[i] != "a" && rr[i] != "b" {
			vv[vi] = "Yi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if (i-1)%4 == 0 && rr[i] != "a" && rr[i] != "b" {
			vv[vi] = "Shi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if (i-1)%4 == 1 && rr[i] != "a" && rr[i] != "b" {
			vv[vi] = "Bai"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if (i-1)%4 == 2 && rr[i] != "a" && rr[i] != "b" {
			vv[vi] = "Qian"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if (i-1)%4 == 3 {
			if wflag {
				vv[vi] = "Wan"
				vi++
			}
			if rr[i] != "b" && rr[i] != "a" {
				vv[vi] = rr[i]
				vi++
			}
		} else if (i-1)%4 == 0 && i != 0 && rr[i] != "a" && rr[i] != "b" {
			vv[vi] = "Shi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else {
			vv[vi] = rr[i]
			vi++
		}

	}

	for i := 99; i >= 0; i-- {
		if vv[i] == "b" {
			result += "ling "
		} else if vv[i] != "" && vv[i] != "a" {
			result += vv[i]
			if i != 0 {
				result += " "
			}
		}
	}
	fmt.Println(strings.TrimSpace(result))
}

//go build && ./a1082_go
