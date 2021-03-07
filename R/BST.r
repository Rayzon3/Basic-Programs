#data to be inserted
#x <- c(12, 3, 1, 4, 2)

#init BST
node.new <- function(data){
  node <- list(data = data, right = NULL, left = NULL)
  class(node) <- "newNode"
  return(node)
}

#insert node 
node.put <- function(node, data){
  if(data < node$data){
    if(is.null(node$left)){
      #creating new node
      node$left <- node.new(data)
    }else{
      #recursive call
      node$left <- node.put(node$left, data)
    }
  }else{
    if(is.null(node$right)){
      #creating new node
      node$right <- node.new(data) 
    }else{
      #recursive call
      node$right <- node.put(node$right, data)
    }
  }
  return(node)
}

#inorder traversal 
node.inorder <- function(node){
  if(!is.null(node$left)){
    node.inorder(node$left)
  }
  print(node$data)
  if(!is.null(node$right)){
    node.inorder(node$right)
  }
}

#postorder traversal
node.postorder <- function(node){
  if(!is.null(node$left)){
    node.postorder(node$left)
  }
  if(!is.null(node$right)){
    node.postorder(node$right)
  }
  print(node$data)
}

#preorder traversal
node.preorder <- function(node){
  print(node$data)
  if(!is.null(node$left)){
    node.preorder(node$left)
  }
  if(is.null(node$right)){
    node.preorder(node$right)
  }
}

x <- node.new(1)
x <- node.put(x, 15)
x <- node.put(x, 2)
x <- node.put(x, 21)
x <- node.put(x, 1)
x <- node.put(x, -23)
x <- node.put(x, 0)

print("Data inserted !!")

print("In-order Traversal : ")
node.inorder(x)

print("Post-order Traversal : ")
node.postorder(x)

print("Pre-order Traversal : ")
node.preorder(x)
