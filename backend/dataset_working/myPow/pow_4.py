class Solution:

    def myPow(self, x: float, n: int) -> float:
        if x == 0: return 0.0
        if x == 1 or n == 0: return 1.0
        
        power = abs(n)
        stored_power = {}
        res = self.get_positive_power(x, power, stored_power)
        return 1/res if n < 0 else res 
		
    def get_positive_power(self, x, power, stored_power):
        if power == 1: return x
        if power == 2: return x*x
        
        if stored_power.get(power): return stored_power[power]
        
        prev_power = 1
        next_power = 2
        prev_val = x
        
        while next_power < power:
            prev_val = prev_val*prev_val
            stored_power[next_power] = prev_val
            prev_power = next_power
            next_power *= 2
        
        stored_power[power] = prev_val * self.get_positive_power(x, power-prev_power, stored_power)
        return stored_power[power]

