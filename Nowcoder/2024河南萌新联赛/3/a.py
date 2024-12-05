import math
Pi = 31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

if __name__ == '__main__':
	n = int(input())
	ans = int(pow(10, 101))
	P = int(pow(10, 100))
	ans_x, ans_y = 0, 0
	for i in range(n):
		x, y = map(int, input().split())
		tmp = P * x // y
		res = abs(Pi - tmp)
		if res < ans:
			ans = res
			ans_x, ans_y = x, y
		elif res == ans:
			if x < ans_x:
				ans_x, ans_y = x, y
	print(ans_x, ans_y, end = ' ')