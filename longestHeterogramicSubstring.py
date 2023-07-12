import random
import string


def random_string_generator(str_size):
    return ''.join(random.choice(string.ascii_lowercase)
                   for x in range(str_size))


def longestHeterogramicSubstringNaive(s: str) -> str:
    result = ""

    for i in range(len(s)):
        current = ""

        for j in range(i, len(s)):
            if s[j] in current:
                break

            current += s[j]
            if len(current) > len(result):
                result = current

    return result


def longestHeterogramicSubstring(s: str) -> str:
    if (len(s) == 1):
        return s

    result = ""
    charToPosition = {}
    startIndex = 0

    for i in range(len(s)):
        if s[i] in charToPosition:
            startIndex = max(startIndex, charToPosition[s[i]] + 1)

        charToPosition[s[i]] = i
        current = s[startIndex:i + 1]
        if len(current) > len(result):
            result = current

    return result


def test():
    for size in range(100):
        input = random_string_generator(size)
        expected = longestHeterogramicSubstringNaive(input)
        actual = longestHeterogramicSubstring(input)

        if expected != actual:
            print("failed for " + input + "\t expected: " +
                  expected + "\t actual: " + actual)


test()
