arr = c(2, 4, 1, 5, 3, 9)

quickSort <- function(arr){
  len = length(arr)
  if(len <= 1){
    return(arr)
  }
  else{
    # pivot will be the last element
    pivot = arr[len]
  }
  #Making partition arrays
  elements_greater <- c()
  elements_lesser <- c()
  
  #Sorting the elements according to pivot
  lapply(arr[arr != pivot], function(element){
    if(element > pivot){
      elements_greater <<- c(elements_greater, element)
    }
    else{
      elements_lesser <<- c(elements_lesser, element)
    }
  })
  
  #Making recursive calls to sort the partitions created
  if(length(elements_greater) > 1){
    elements_greater <- quickSort(elements_greater)
  }
  if(length(elements_lesser) > 1){
    elements_lesser <- quickSort(elements_lesser)
  }
  
  return(c(elements_lesser, pivot, elements_greater))
}

print(quickSort(arr))




