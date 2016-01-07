# 大数乘法，用py很简单的
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if not num1 or not num2:
            return "0"
        return str(int(num1)*int(num2))
        
