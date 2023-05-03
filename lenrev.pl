
lenrev([], [], 0).

lenrev([X|Xs], Ys, N) :-
    lenrev(Xs, Zs, M),
    N is M + 1,
    append(Zs, [X], Ys).
