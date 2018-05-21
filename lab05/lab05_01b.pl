﻿%% Τεχνικές Λογικού Προγραμματισμού – Η γλώσσα Prolog (Η. Σακελλαρίου, Ν. Βασιλειάδης, Π. Κεφαλάς, Δ. Σταμάτης) 
%% ΚΕΦΑΛΑΙΟ 12 

:- use_module(library(clpfd)).

solve(X,Y,Z):-
    X in 4..8,
    Y in 1..8,
    Z in 6..10,
    X #= Y+1,
    Z #< X,
    %label([X,Y,Z]),
    write([X,Y,Z]),nl,fail.