class Solution:
    def isPalindrome(self, x: int) -> bool:
        t = str(x)
        if list(t) == list(t)[::-1]:
            return True
        return False

if __name__ == '__main__':
    print(Solution().isPalindrome(-121))    