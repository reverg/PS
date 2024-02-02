import sys

input = sys.stdin.readline


# O(N)
def urlify(string, length):
    """function replaces single spaces with %20 and removes trailing spaces"""
    extra_spaces = 2 * s.count(" ")
    new_index = len(s) + extra_spaces
    string_list = list(string) + [" "] * extra_spaces

    for i in reversed(range(length)):
        if string[i] == " ":
            # Replace spaces
            string_list[new_index - 3 : new_index] = "%20"
            new_index -= 3
        else:
            # Move characters
            string_list[new_index - 1] = string[i]
            new_index -= 1

    return "".join(string_list)


if __name__ == "__main__":
    while True:
        try:
            s = input().rstrip()
            extended_length = len(s) + 2 * s.count(" ")
            ans = urlify(s, len(s))
            print(ans)
        except EOFError:
            break
