#Converting temperature in F to C using Linear Regression

temperature.data <- data.frame(
  celsius = c(-200, -90, -40,  14, 32, 46, 59, 72, 100),
  fahrenheit = c(-328, -130, -40, 57.2,  89.6,  114.8, 138.2, 161.6, 212))

temperature.data
plot(temperature.data$celsius, temperature.data$fahrenheit)
#setting up linear regression
## here lm -> linear models
temperature.regression <- lm(celsius ~ fahrenheit, data = temperature.data)
## size are y values and weight are x values

summary(temperature.regression)
## the min and max values should be approx same distance from 0
## the 1Q and 3Q should be equidistant from 0
## median also should be close to zero
temperature.regression

abline(mouse.regression, col="blue")

#for F=99
predicted_C =  0.5556*99 + -17.7778  
predicted_C
