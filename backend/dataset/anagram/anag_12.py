
def isAnagram(self, s: str, t: str) -> bool:
        return collections.Counter(t)==collections.Counter(s)