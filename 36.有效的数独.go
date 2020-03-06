/*
 * @lc app=leetcode.cn id=36 lang=golang
 *
 * [36] 有效的数独
 */
package main

import (
	"fmt"
)

// @lc code=start
func toInt(b byte) int {
	zero := 48
	res := int(b) - zero
	if res < 0 {
		res = 0
	}
	return res
}

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		validBox := [10]bool{}
		validRow := [10]bool{}
		validCol := [10]bool{}
		for j := 0; j < 9; j++ {
			numBox := toInt(board[3*(i/3)+j/3][3*(i%3)+j%3])
			numRow := toInt(board[i][j])
			numCol := toInt(board[j][i])
			if validBox[numBox] || validRow[numRow] || validCol[numCol] {
				return false
			}
			validBox[numBox], validRow[numRow], validCol[numCol] = true, true, true
			validBox[0], validRow[0], validCol[0] = false, false, false
		}
	}
	return true
}

// @lc code=end
func main() {
	x := byte('9')
	fmt.Println(toInt(x))
}
