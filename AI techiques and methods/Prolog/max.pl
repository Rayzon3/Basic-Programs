find_max(X,Y,"The first number is greater than the second one") :- X > Y, !.
find_max(X,Y,"Both are equal!") :- X =:= Y, !.
find_max(X,Y,"The second number is greater the first number") :- X < Y, !. 
