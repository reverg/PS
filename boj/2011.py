import sys

input = sys.stdin.readline


def crypto_code(enc_str):
    dp = [0 for _ in range(len(enc_str) + 1)]
    dp[0] = 1

    if enc_str[0] == "0":
        return 0
    else:
        dp[1] = 1

    for i in range(2, len(enc_str) + 1):
        # length 1 numbers
        if enc_str[i - 1] == "0":
            if not (enc_str[i - 2] == "1" or enc_str[i - 2] == "2"):
                return 0
        else:
            dp[i] += dp[i - 1]

        # length 2 numbers
        if 10 <= int(enc_str[i - 2] + enc_str[i - 1]) <= 26:
            dp[i] += dp[i - 2]

        dp[i] %= 1000000

    return dp[len(enc_str)]


if __name__ == "__main__":
    enc_str = input().rstrip()

    print(crypto_code(enc_str))
