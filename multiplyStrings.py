# Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

# Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        len1, len2 = len(num1), len(num2)
        result = [0] * (len1 + len2)

        for i in range(len1 - 1, -1, -1):
            carry = 0
            for j in range(len2 - 1, -1, -1):
                temp_sum = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0')) + result[i + j + 1] + carry
                result[i + j + 1] = temp_sum % 10
                carry = temp_sum // 10

            result[i] += carry

        result_str = ''.join(map(str, result))
        return result_str.lstrip('0') or '0'
