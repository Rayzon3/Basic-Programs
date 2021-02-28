print("Enter a number :")
num <- readline()
num <- as.numeric(num)

fact <- function(num){
  if(num >= 1){
    return(num*fact(num - 1))
  }else{
    return(1)
  }
}

print(fact(num))