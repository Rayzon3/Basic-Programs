wrd = "00110011"

count_zero = 0
count_one = 0

for letter in wrd:
    if letter == '0':
        count_zero += 1
    if letter == '1':
        count_one += 1

if count_one % 2 == 0 and count_zero % 2 == 0:
    print("Accepted")
else:
    print("Not Accepted")