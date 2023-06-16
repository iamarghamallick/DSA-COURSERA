def compute_operations(n):
    # Stores the values for the
    # minimum length of sequences
    dp = [0 for _ in range(n + 1)]
  
    # Base Case
    dp[1] = 1
  
    # Loop to build up the dp[]
    # array from 1 to n
    for i in range(1, n + 1):
  
        if dp[i] != 0:
  
            # If i + 1 is within limits
            if i + 1 < n + 1 and (dp[i + 1] == 0 \
            or dp[i + 1] > dp[i] + 1):
                  
                # Update the state of i + 1 
                # in dp[] array to minimum
                dp[i + 1] = dp[i] + 1
  
            # If i * 2 is within limits
            if i * 2 < n + 1 and (dp[i * 2] == 0 \
            or dp[i * 2] > dp[i] + 1):
                  
                # Update the state of i * 2
                # in dp[] array to minimum
                dp[i * 2] = dp[i] + 1
  
            # If i * 3 is within limits
            if i * 3 < n + 1 and (dp[i * 3] == 0 \
            or dp[i * 3] > dp[i] + 1):
                  
                # Update the state of i * 3
                # in dp[] array to minimum
                dp[i * 3] = dp[i] + 1
  
    # Generate the sequence by
    # traversing the array
    sequence = []
    while n >= 1:
  
        # Append n to the sequence
        sequence.append(n)
  
        # If the value of n in dp
        # is obtained from n - 1:
        if dp[n - 1] == dp[n] - 1:
            n = n - 1
  
        # If the value of n in dp[]
        # is obtained from n / 2:
        elif n % 2 == 0 \
        and dp[n // 2] == dp[n] - 1:
            n = n // 2
  
        # If the value of n in dp[]
        # is obtained from n / 3:
        elif n % 3 == 0 \
        and dp[n // 3] == dp[n] - 1:
            n = n // 3
  
    # Return the sequence
    # in reverse order
    return sequence[::-1]

if __name__ == '__main__':
    input_n = int(input())
    output_sequence = compute_operations(input_n)
    print(len(output_sequence) - 1)
    print(*output_sequence)


# Python3 program to implement
# the above approach
  
# Function to generate 
# the minimum sequence
# def find_sequence(n):
  
#     # Stores the values for the
#     # minimum length of sequences
#     dp = [0 for _ in range(n + 1)]
  
#     # Base Case
#     dp[1] = 1
  
#     # Loop to build up the dp[]
#     # array from 1 to n
#     for i in range(1, n + 1):
  
#         if dp[i] != 0:
  
#             # If i + 1 is within limits
#             if i + 1 < n + 1 and (dp[i + 1] == 0 \
#             or dp[i + 1] > dp[i] + 1):
                  
#                 # Update the state of i + 1 
#                 # in dp[] array to minimum
#                 dp[i + 1] = dp[i] + 1
  
#             # If i * 2 is within limits
#             if i * 2 < n + 1 and (dp[i * 2] == 0 \
#             or dp[i * 2] > dp[i] + 1):
                  
#                 # Update the state of i * 2
#                 # in dp[] array to minimum
#                 dp[i * 2] = dp[i] + 1
  
#             # If i * 3 is within limits
#             if i * 3 < n + 1 and (dp[i * 3] == 0 \
#             or dp[i * 3] > dp[i] + 1):
                  
#                 # Update the state of i * 3
#                 # in dp[] array to minimum
#                 dp[i * 3] = dp[i] + 1
  
#     # Generate the sequence by
#     # traversing the array
#     sequence = []
#     while n >= 1:
  
#         # Append n to the sequence
#         sequence.append(n)
  
#         # If the value of n in dp
#         # is obtained from n - 1:
#         if dp[n - 1] == dp[n] - 1:
#             n = n - 1
  
#         # If the value of n in dp[]
#         # is obtained from n / 2:
#         elif n % 2 == 0 \
#         and dp[n // 2] == dp[n] - 1:
#             n = n // 2
  
#         # If the value of n in dp[]
#         # is obtained from n / 3:
#         elif n % 3 == 0 \
#         and dp[n // 3] == dp[n] - 1:
#             n = n // 3
  
#     # Return the sequence
#     # in reverse order
#     return sequence[::-1]
  
# # Driver Code
  
# # Given Number N
# n = 1
  
# # Function Call
# sequence = find_sequence(n)
  
# # Print the length of
# # the minimal sequence
# print(len(sequence) - 1)
  
# # Print the sequence
# print(*sequence)