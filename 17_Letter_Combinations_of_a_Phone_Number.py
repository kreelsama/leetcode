from itertools import product

class Solution:
    def gen(self, strings):
        try:
            for each in strings[0]:
                for every in self.gen(strings[1:]):
                    yield (each,) + every
        except:
            yield ()
    
    def repeat(self, obj, times):
        for _ in range(times):
            yield obj
    
    def letterCombinations(self, digits: str):
        D = ['', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        mapped = list(map(lambda x, y: y[int(x) - 1], digits,[D] * len(digits)))
        return list(map(lambda x: ''.join(x), self.gen(mapped)))

if __name__ == '__main__':
    print(Solution().letterCombinations('23'))