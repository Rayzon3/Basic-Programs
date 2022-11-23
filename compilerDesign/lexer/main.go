package main

import (
	"fmt"
)

func main() {
	var operator string
	fmt.Printf("Enter any operator: \n")
	fmt.Scanln(&operator)

	switch {
	case operator == ">=":
		fmt.Printf("Greater than equal")

	case operator == "<=":
		fmt.Printf("Less than equal")

	case operator == ">":
		fmt.Printf("Greater")

	case operator == "<":
		fmt.Printf("Less \n")

	case operator == "=":
		fmt.Printf("Equal \n")

	case operator == "!=":
		fmt.Printf("Not Equal \n")

	case operator == "&&":
		fmt.Printf("Logical AND \n")

	case operator == "||":
		fmt.Printf("Logical OR \n")

	case operator == "&":
		fmt.Printf("Bitwise AND \n")

	case operator == "|":
		fmt.Printf("Bitwise OR \n")

	case operator == "+":
		fmt.Printf("Addition \n")

	case operator == "-":
		fmt.Printf("Substraction \n")

	case operator == "/":
		fmt.Printf("Division \n")

	case operator == "*":
		fmt.Printf("Multiplication \n")

	case operator == "%":
		fmt.Printf("Modulus \n")

	default:
		fmt.Printf("Not an operator! \n")
	}

}
