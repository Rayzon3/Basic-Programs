%show_records([]).
%show_records([A|B]) :-
%format('ID = ~w\tName = ~w\tGrade = ~w~n',A),
%show_records(B).

writeList([]):-nl.
writeList([H|T]):-write(H),nl,writeList(T).