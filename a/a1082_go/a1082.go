package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	num := []string{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}
	// wei := []string{"Shi", "Bai", "Qian", "Wan", "Yi"}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()

	slen := len(str)

	left := 0
	// right := slen - 1
	if str[0] == '-' {
		fmt.Print("Fu ")
		left++
	}

	rr := make([]string, 10)
	no := 0
	for i := slen - 1; i >= 0; i-- {
		n, _ := strconv.Atoi(string(str[i]))
		rr[no] = num[n]
		no++
	}

	for i := 0; i < slen-1; i++ {
		if i == 0 && rr[i] == "ling" {
			rr[i] = "a"
		} else if rr[i] == "ling" {
			rr[i] = "a"
		} else {
			break
		}
	}

	for i := 0; i < slen-1; i++ {
		if i != 0 && rr[i] == "ling" && rr[i-1] != "ling" {
			rr[i] = "b"
		} else if i != 0 && rr[i] == "ling" && rr[i-1] == "b" {
			rr[i] = "a"
		} else {
			break
		}
	}

	vv := make([]string, 50)
	vi := 0
	for i := 0; i < slen; i++ {
		if i == 8 && rr[i] != "a" {
			vv[vi] = "Yi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if i%5 == 1 && rr[i] != "a" {
			vv[vi] = "Shi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if i%5 == 2 && rr[i] != "a" {
			vv[vi] = "Bai"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if i%5 == 3 && rr[i] != "a" {
			vv[vi] = "Qian"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if i%5 == 4 && rr[i] != "a" {
			vv[vi] = "Wan"
			vi++
			vv[vi] = rr[i]
			vi++
		} else if i%5 == 0 && i != 0 && rr[i] != "a" {
			vv[vi] = "Shi"
			vi++
			vv[vi] = rr[i]
			vi++
		} else {
			vv[vi] = rr[i]
			vi++
		}

	}

	vlen := len(vv)

	for i := vlen - 1; i >= 0; i-- {
		if vv[i] == "b" {
			fmt.Print("ling ")
		} else if vv[i] != "a" {
			fmt.Print(vv[i], " ")
		}
	}
}

//g++ a1082/*.cpp -o a.out && ./a.out
