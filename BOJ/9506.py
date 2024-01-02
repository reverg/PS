while True:
    n = int(input())
    if n == -1:
        break

    num_list = []
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            num_list.append(i)
            sum += i

    if sum == n:
        tmp = " + ".join(str(i) for i in num_list)
        print(f"{n} =", tmp)
    else:
        print(f"{n} is NOT perfect.")
