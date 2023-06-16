from sys import stdin


# def maximum_gold(capacity, weights):
#     assert False


# if __name__ == '__main__':
#     input_capacity, n, *input_weights = list(map(int, stdin.read().split()))
#     assert len(input_weights) == n

#     print(maximum_gold(input_capacity, input_weights))


# This is the memoization approach of
# 0 / 1 Knapsack in Python in simple
# we can say recursion + memoization = DP
 
 
def knapsack(wt, val, W, n):
 
    # base conditions
    if n == 0 or W == 0:
        return 0
    if t[n][W] != -1:
        return t[n][W]
 
    # choice diagram code
    if wt[n-1] <= W:
        t[n][W] = max(
            val[n-1] + knapsack(
                wt, val, W-wt[n-1], n-1),
            knapsack(wt, val, W, n-1))
        return t[n][W]
    elif wt[n-1] > W:
        t[n][W] = knapsack(wt, val, W, n-1)
        return t[n][W]
 
# Driver code
if __name__ == '__main__':
    # W, n, *weight = list(map(int, stdin.read().split()))
    W, n = input().split()
    weight = list(map(int, input().strip().split()))

    W = int(W)
    n = int(n)

    # profit = [1, 4, 8]
    # weight = [1, 4, 8]
    # W = 10
    # n = len(weight)
    
    # We initialize the matrix with -1 at first.
    t = [[-1 for i in range(W + 1)] for j in range(n + 1)]
    print(knapsack(weight, weight, W, n))
 
# This code is contributed by Prosun Kumar Sarkar