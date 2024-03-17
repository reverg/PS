def build_freq_table(s):
    freq_map = {}
    for c in s:
        freq_map[c] = freq_map.get(c, 0) + 1
    return freq_map


def print_perms(freq_map, prefix, remaining, result):
    if remaining == 0:
        result.append(prefix)
        return

    for c in freq_map:
        count = freq_map[c]
        if count > 0:
            freq_map[c] -= 1
            print_perms(freq_map, prefix + c, remaining - 1, result)
            freq_map[c] += 1


def get_perms(s):
    result = []
    freq_map = build_freq_table(s)
    print_perms(freq_map, "", len(s), result)
    return result


if __name__ == "__main__":
    s = "aabbccc"
    result = get_perms(s)

    for r in result:
        print(r)
    print("Count:", len(result))
