sum(0, 0).
sum(N, S) :- N > 0, N1 is N - 1, sum(N1, S1), S is S1 + N.
