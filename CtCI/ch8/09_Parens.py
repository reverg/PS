def add_paren(list, left_rem, right_rem, string):
    if left_rem < 0 or right_rem < left_rem:
        return  # invalid state

    if left_rem == 0 and right_rem == 0:
        # all out of left and right parentheses
        list.append(string)
    else:
        string += "("  # Add left and recurse
        add_paren(list, left_rem - 1, right_rem, string)

        string += ")"  # Add right and recurse
        add_paren(list, left_rem, right_rem - 1, string)


def generate_parens(count):
    string = ""
    result = []
    add_paren(result, count, count, string)
    return result


if __name__ == "__main__":
    result = generate_parens(6)
    for s in result:
        print(s)
    print(len(result))
