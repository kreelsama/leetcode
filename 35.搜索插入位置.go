/*
 * @lc app=leetcode.cn id=35 lang=golang
 *
 * [35] 搜索插入位置
 */
package main

import (
	"fmt"
)

// @lc code=start
func searchInsert(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}
	var left, right int = 0, len(nums) - 1
	if nums[right] < target {
		return right + 1
	}
	for right >= left {
		mid := (left + right) / 2
		if nums[mid] < target {
			left = mid + 1
		} else if nums[mid] > target {
			right = mid - 1
		} else {
			return mid
		}
	}
	return left
}

// @lc code=end

func main() {
	nums := []int{1, 2, 4, 5}
	fmt.Println(searchInsert(nums, 5))
}
