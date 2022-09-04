word = "011"

for index in range(len(word)):
    if word[index] == "1":
        print("Not Accepted")
        break
    if word[index] == "0":
        if(word[index + 1] == "1"):
            print("Accepted")
        else:
            print("Not Accepted")
            break