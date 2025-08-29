def calculate(self, s: str) -> int:
        stack[]
        num,sign,result=0,1,0
        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            