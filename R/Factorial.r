print("Enter the number: ")
num <- readline()
num <- as.numeric(num)
factorial <- 1

fact <- function(num){
  if(num < 0){
    print("Factorial of a negative number doesn't exist")
  }else{
    for(i in 1:num){
      factorial <- factorial * i
    }
  }
  print(factorial)
}

fact(num)