class Solution:
    def isPalindrome(self, x: int) -> bool:
        t = str(x)
        return t == t[::-1]

if __name__ == '__main__':
    print(Solution().isPalindrome(121))    