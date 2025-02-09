def main(n, s):
    matrix = [[" " for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if j == 0 or i == 0 or i == n - 1 or j == n - 1:
                matrix[i][j] = s

    for row in matrix:
        print("".join(row))

s = input()
n = int(input())
main(n, s)
