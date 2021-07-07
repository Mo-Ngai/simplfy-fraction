def count(x):
    list = []
    m = 0
    while m < x:
        m+=1
        list.append(m)
    return list

def duplicate(n, d):
    l1 = count(n)
    l2 = count(d)
    ln = l1 + l2
    listn = []
    for x in ln:
        if ln.count(x) > 1:
            listn.append(x)
    listn.reverse()
    div = 0
    dlist = []
    while div < listn[0]:
        div += 1
        dlist.append(div)
    return dlist

def divisor(n, d):
    lf = []
    if n > d:
        for x in duplicate(n, d):
            if n%x == 0:
                if d%x == 0:
                    lf.append(x)
    else:
        for x in duplicate(n, d):
            if d%x == 0:
                if n%x == 0:
                    lf.append(x)
    lf.reverse()
    return lf[0]

def division(n, d):
    div = divisor(n, d)
    n2 = n//div
    d2 = d//div
    next = "\n"
    divide = "---"
    step1 = f"step1:{next}{n}{next}{divide}{next}{d}"
    step2 = f"step2:{next}{n}/{div}{next}{divide}{next}{d}/{div}"
    step3 = f"step3:{next}{n2}{next}{divide}{next}{d2}"
    print(step1 + "\n")
    print(step2 + "\n")
    print(step3 + "\n")

def calculator(n, d):
    if n % 1 != 0 and d % 1 != 0:
        pn = len(str(n).split(".")[1])
        pd = len(str(d).split(".")[1])
        if pd >= pn:
            n = n * (10 ** pd)
            d = d * (10 ** pd)
            division(n, d)
            print("the initial value has been multiplied by: " + 10**pd)
        else:
            n = n * (10 ** pn)
            d = d * (10 ** pn)
            division(n, d)
            print("the initial value has been multiplied by: " + 10 ** pn)
    elif n % 1 != 0:
        pn = len(str(n).split(".")[1])
        n = n * (10 ** pn)
        d = d * (10 ** pn)
        division(n, d)
        print("the initial value has been multiplied by: " + 10 ** pn)
    elif d % 1 != 0:
        pd = len(str(d).split(".")[1])
        n = n * (10 ** pd)
        d = d * (10 ** pd)
        division(n, d)
        print("the initial value has been multiplied by: " + 10 ** pd)
    else:
        division(n, d)

while True:
    try:
        n = float(input("numerator: "))
        d = float(input("denominator: "))

        calculator(n, d)
    except:
        print("please input numbers")

        continue
    else:
        break
