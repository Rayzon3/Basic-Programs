library(datasets)
head(iris)

plot(iris$Species) #Bar Plot

#Box Plot
boxplot(iris$Species, iris$Petal.Width)
plot(iris$Species, iris$Petal.Width) 

#Scatter Plot
plot(iris$Petal.Length, iris$Petal.Width,
     col = "#cc0000",
     pch = 19,
     main = "iris: Petal Length vs Petal Width",
     xlab = "Petal Lenght",
     ylab = "Petal Width"
)

#Line Chart
library(ggplot2)
Sepal_Length <- iris$Sepal.Length
Sepal_Width <- iris$Sepal.Width
data <- data.frame(xVal, yVal)
ggplot(data, aes(x = Sepal_Length, y = Sepal_Width)) + geom_line(color = "dark green") + ggtitle("Sepal_Length Vs Sepal_Width")

