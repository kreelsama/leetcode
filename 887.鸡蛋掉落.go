/*
 * @lc app=leetcode.cn id=887 lang=golang
 *
 * [887] 鸡蛋掉落
 */
package main

import (
	"fmt"
)

// @lc code=start

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

/*
func output(drops [][]int, K, N int) {
	for i := 1; i <= K; i++ {
		for j := 1; j <= N; j++ {
			fmt.Printf("%5d ", drops[i][j])
		}
		fmt.Printf("\n")
	}
}
*/

func superEggDropOknLGn(K int, N int) int {
	drops := make([][]int, K+1)
	for i := 1; i <= K; i++ {
		drops[i] = make([]int, N+1)
		drops[i][1] = 1
	}
	for i := 1; i <= N; i++ {
		drops[1][i] = i
	}
	for k := 2; k <= K; k++ {
		for n := 2; n <= N; n++ {
			//O(n3) is not acceptable.
			//binsearch may optimize to O(n2logn)
			low := 1
			high := n
			for high-low > 1 {
				mid := (low + high) / 2
				if drops[k-1][mid-1] < drops[k][n-mid] {
					low = mid
				} else if drops[k-1][mid-1] > drops[k][n-mid] {
					high = mid
				} else {
					low, high = mid, mid
					break
				}
			}
			//fmt.Println(k, n, min+1)
			drops[k][n] = Min(Max(drops[k-1][low-1], drops[k][n-low]), Max(drops[k-1][high-1], drops[k][n-high])) + 1
		}
	}
	//output(drops, K, N)
	return drops[K][N]
}

// @lc code=end

func main() {
	fmt.Println(superEggDrop(3, 14))
}
