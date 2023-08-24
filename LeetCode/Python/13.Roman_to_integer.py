class Solution:
    def romanToInt(self, s: str) -> int:
        if s is None:
            return 0
        R = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
            }
        if s[0] in R and len(s) == 1:
            return R[s[0]]

        sum = 0
        prev = R[s[0]]
        for char in s[1:]:
            curr = R[char]
            if prev >= curr:
                sum += prev
            else:
                sum -= prev
            prev = curr
        sum += curr
        return sum

