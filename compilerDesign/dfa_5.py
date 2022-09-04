import re


wrd = "10111000"
matches = re.findall("0+", wrd)

zeroes = map(lambda x: len(x), matches)

if max(zeroes) == 3:
    print("Not Accepted")
else:
    print("Accepted")