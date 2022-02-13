member(X,[X|_]).
member(X,[_|X]) :- member(X,T).
