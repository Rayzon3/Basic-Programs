show_records([]).
show_records([A|B]) :-
  format('ID = ~w\tName = ~w\tGrade = ~w~n',A),
  show_records(B).