class Solution:
    def reverse(self, x: int) -> int:
        p = -1 if x < 0 else 1
        x *= p
        res = p*int(''.join(reversed(str(x))))
        if res <= -pow(2,31) or res >= pow(2,32):
            return 0
        return res

if __name__ == "__main__":
    print(Solution().reverse(1534236469))