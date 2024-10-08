class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = ""
        i = len(a) - 1
        j = len(b) - 1
        carry = 0

        # Traverse both strings from the end
        while i >= 0 or j >= 0 or carry:
            sum = carry

            # Add current digit of string a (if valid)
            if i >= 0:
                sum += int(a[i])  # 'a[i] - '0'' can be written as int(a[i])
                i -= 1

            # Add current digit of string b (if valid)
            if j >= 0:
                sum += int(b[j])  # 'b[j] - '0'' can be written as int(b[j])
                j -= 1

            # Append the current binary digit (sum % 2)
            result += str(sum % 2)  # Convert back to string
            
            # Update carry
            carry = sum // 2

        # Reverse the result string since it's built backwards
        return result[::-1]
