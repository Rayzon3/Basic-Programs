myList = ['a', 'b']

wrd = 'ababb'
count = 0

for letter in wrd:
    if myList.__contains__(letter):
        count += 1


if count == len(wrd):
    print("Accepted")
else:
    print("Not Accepted")