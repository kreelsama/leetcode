/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
package main

import (
	"fmt"
)

// @lc code=start
func searchRange(nums []int, target int) []int {
	res := []int{-1, -1}
	if len(nums) == 0 {
		return res
	}
	var left, right int = 0, len(nums) - 1
	for right != left {
		mid := (left + right) / 2
		if nums[mid] < target {
			left = mid
		} else {
			right = mid
		}
		if right-left == 1 && nums[left] != target {
			left++
		}
	}
	if nums[left] != target {
		return res
	}
	res[0] = left
	left, right = 0, len(nums)-1
	for right != left {
		mid := (left + right) / 2
		if nums[mid] <= target {
			left = mid
		} else {
			right = mid
		}
		if right-left == 1 {
			if nums[right] != target {
				right--
			}
			break
		}
	}
	res[1] = right
	return res
}

// @lc code=end
func main() {
	nums := []int{0, 0, 0, 1, 2, 2}
	for _, num := range searchRange(nums, 2) {
		fmt.Printf("%d ", num)
	}
}
