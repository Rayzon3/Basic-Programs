matrix(1 : 9, nrow = 3)
matrix(1 : 9, nrow = 3, byrow = TRUE)
matrix(1 : 9, ncol = 2) #error
matrix(1 : 6, ncol = 2)
matrix(1 : 10, nrow = 5, ncol =5)
cbind(1 : 3, 1 : 3)
rbind(1 : 5, 6 : 10, 11 : 15)
cbind(3 : 6, 7 : 10, byrow = TRUE)

m <- matrix(1 : 6, byrow = TRUE, nrow = 2)
rbind(m,7 : 9)
cbind(m,c(11, 12))

m <- matrix(1 : 9, byrow = TRUE, nrow = 3)
rownames(m) <- c("R1", "R2", "R3")
colnames(m) <- c("C1", "C2", "C3")
rbind(m)

song <- list(Title = "Suffer", Duration = 2, Track = 3)
str(song)

same_Artist <- list(Title = "LA Girls", Duration = 2)
song <- list(Title = "Suffer", Duration = 2, Track = 3, same = same_Artist)
str(song)

#data frame
name <- c("Asuna", "Ruka", "Yui", "Lisa")
age <- c(21, 22, 23, 24)
language <- c("C", "Java", "Python", "Dart")
df <- data.frame(name, age, language)
str(df)


arr <- array(c(1 : 9))
str(arr)
arr

arr <- array(c(1 : 9), dim = c(3, 3, 1))
arr

v1 <- c(1, 2, 3, 4, 5, 6)
v2 <- c(4, 4, 5, 9, 76, 43, 2, 2)
arr <- array(c(v1, v2), dim = c(3, 3, 1))
arr
arr <- array(c(v1, v2))
arr

blood <- c("B", "A", "AB", "O")
blood_factor <- factor(blood)
blood_factor
str(blood_factor)
