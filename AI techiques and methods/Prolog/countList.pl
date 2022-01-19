count([],0).
count([_|Tail], N) :- count(Tail, N1), N is N1 + 1.

/* _ -> first element in the list 
   Tail -> all the rest of the elements in list 
   Using Recursion here 
 */
