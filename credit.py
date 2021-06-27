
count = 0
keta = 0
sum1 = 0
sum2 = 0
ketasu = 0

while True:
    number = int(input("Number: "))
    if 0 < number:
        break

count = int(len(str(number)))


# 桁数が偶数の時
if count % 2 == 0:
    for i in range(count, 0, -1):
        # 一桁ずつ計算していく
        keta = int(number / (10 ** (i - 1)))
        if i == count:
            # 最上位桁の数字を格納
            mc1 = int(keta)
        elif i == count - 1:
            # 上から二番目の数字を格納
            mc2 = int(keta)
        number = number % (10 ** (i - 1))
        # 偶数桁目
        if i % 2 == 0:
            if keta * 2 < 10:
                sum1 += keta * 2
            else:
                sum1 += int(keta * 2 / 10 + keta * 2 % 10)
        # 奇数桁目
        if i % 2 == 1:
            sum2 += keta
# 桁数が奇数の時
else:
    for i in range(count, 0, -1):
        keta = int(number / (10 ** (i - 1)))
        if i == count:
            mc1 = int(keta)
        elif i == count - 1:
            mc2 = int(keta)
        number = number % (10 ** (i - 1))
        if i % 2 == 1:
            sum1 += keta
        if i % 2 == 0:
            if keta * 2 < 10:
                sum2 += keta * 2
            else:
                sum2 += int(keta * 2 / 10 + keta * 2 % 10)

mc = mc1 * 10 + mc2

# Luhnのアルゴリズムによって種類を判定
if int((sum1 + sum2)) % 10 == 0:
    if count == 15 and (mc == 34 or mc == 37):
        print("AMEX")
    elif count == 16 and (mc == 51 or mc == 52 or mc == 53 or mc == 54 or mc == 55):
        print("MASTERCARD")
    elif mc1 == 4 and (count == 13 or count == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

