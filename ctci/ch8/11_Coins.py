def make_change(n, denoms):
    map_cache = [[0] * len(denoms) for _ in range(n + 1)]
    return make_change_helper(n, denoms, 0, map_cache)


def make_change_helper(total, denoms, index, map_cache):
    # Check cache for prior result
    if map_cache[total][index] > 0:
        return map_cache[total][index]

    coin = denoms[index]
    if index == len(denoms) - 1:
        remaining = total % coin
        return 1 if remaining == 0 else 0

    number_of_ways = 0
    # Try 1 coin, then 2 coins, 3 coins, ..., recursively each time on rest
    for amount in range(0, total + 1, coin):
        number_of_ways += make_change_helper(
            total - amount, denoms, index + 1, map_cache
        )

    # Update cache with current result
    map_cache[total][index] = number_of_ways

    return number_of_ways


if __name__ == "__main__":
    denoms = [25, 10, 5, 1]
    N = int(input())
    ways = make_change(N, denoms)
    print(ways)
