library(datasets)
head(iris) #show first 6 lines
summary(iris) #summary stats
plot(iris)

detach("pakage:datasets", unload = TRUE) #clear packages
dev.off() #clear plots

install.packages("pacman")
library(pacman)

library(datasets) #loading
head(iris)
?plot #help for plot
plot(iris$Species) #categorical variable
plot(iris$Petal.Length) #quantitative variable
plot(iris$Species, iris$Petal.Width) # cat x quant 
plot(iris$Petal.Length, iris$Petal.Width) #quant pair
plot(iris) #plot entire data frame

x <- seq(10, 100)
y <- x ** 2

plot(x, y)

#Plot options
plot(iris$Petal.Length, iris$Petal.Width,
     col = "#cc0000",
     pch = 19,
     main = "iris: Petal Length vs Petal Width",
     xlab = "Petal Lenght",
     ylab = "Petal Width"
     )

#Plot with formulas
plot(cos, 0, 2*pi)
plot(exp, 1, 5)
plot(dnorm, -3, 3)

#Formula plot with options

