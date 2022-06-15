import collections
class WordsFrequency:

    def __init__(self, book: List[str]):
        self.word_dict = collections.defaultdict(int)

        for word in book:
            self.word_dict[word] += 1

    def get(self, word: str) -> int:
        return self.word_dict[word]