from decimal import Decimal, getcontext

getcontext().prec = 1100
A, B, K = map(int, input().split())
A = Decimal(A)
B = Decimal(B)
ans = A / B
ans = ans.quantize(Decimal('1.' + '0' * K))

print(ans)
