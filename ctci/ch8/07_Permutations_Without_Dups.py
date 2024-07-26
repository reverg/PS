def get_perms(remainder):
    length = len(remainder)
    result = []

    # Base case
    if length == 0:
        result.append("")  # Be sure to return an empty string!
        return result

    for i in range(length):
        # Remove char i and find permutations of remaining characters
        before = remainder[:i]
        after = remainder[i + 1 :]
        partials = get_perms(before + after)

        # Prepend char i to each permutation
        for s in partials:
            result.append(remainder[i] + s)

    return result


if __name__ == "__main__":
    permutations = get_perms("abc")
    print("There are", len(permutations), "permutations.")
    for p in permutations:
        print(p)
