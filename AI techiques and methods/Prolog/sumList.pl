/* add all elements in a list */

sumList([], 0).
sumList([H|T, N]) :- sumList(T,N1),N is N1+H.
