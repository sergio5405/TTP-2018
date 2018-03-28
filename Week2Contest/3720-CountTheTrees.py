dp = []

def fact(n):
	tot = 1
	for i in range(2,n+1):
		tot *= i

	return tot

def countTrees ():
	for x in range(0,301):
		dp.append(0)

	dp[0] = 1
	dp[1] = 1
	dp[2] = 2

	for i in range(3,301):
		for j in range(i):
			dp[i] += dp[j] * dp[i-j-1]




def main():
	n = int(raw_input())
	countTrees()
	while n!= 0:
		print(dp[n]*fact(n))

		n = int(raw_input())

main()
