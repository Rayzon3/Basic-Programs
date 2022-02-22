append([], List, List).
append([H|T], List, [H|Rest]) :- 
                        append(T, List, Rest).