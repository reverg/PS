import sys

input = sys.stdin.readline


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    records = [(0, 0, C)]

    # check all cases
    st = [(0, 0, C)]
    while st:
        a, b, c = st.pop()

        # a -> b
        pour = min(B - b, a)
        if not (a - pour, b + pour, c) in records:
            records.append((a - pour, b + pour, c))
            st.append((a - pour, b + pour, c))

        # a -> c
        pour = min(C - c, a)
        if not (a - pour, b, c + pour) in records:
            records.append((a - pour, b, c + pour))
            st.append((a - pour, b, c + pour))

        # b -> a
        pour = min(A - a, b)
        if not (a + pour, b - pour, c) in records:
            records.append((a + pour, b - pour, c))
            st.append((a + pour, b - pour, c))

        # b -> c
        pour = min(C - c, b)
        if not (a, b - pour, c + pour) in records:
            records.append((a, b - pour, c + pour))
            st.append((a, b - pour, c + pour))

        # c -> a
        pour = min(A - a, c)
        if not (a + pour, b, c - pour) in records:
            records.append((a + pour, b, c - pour))
            st.append((a + pour, b, c - pour))

        # c -> b
        pour = min(B - b, c)
        if not (a, b + pour, c - pour) in records:
            records.append((a, b + pour, c - pour))
            st.append((a, b + pour, c - pour))

    c_record = []
    for record in records:
        if record[0] == 0 and (not record[2] in c_record):
            c_record.append(record[2])
    c_record.sort()

    print(*c_record)
