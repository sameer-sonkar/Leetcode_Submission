class StockSpanner:
    from collections import deque
    def __init__(self):
        self.stack=deque()
        

    def next(self, price: int) -> int:
        sum=1
        while self.stack and self.stack[-1][0]<=price:
            sum+=self.stack[-1][1]
            self.stack.pop()

        self.stack.append((price,sum))
        return sum
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)