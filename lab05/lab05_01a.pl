﻿%% Τεχνικές Λογικού Προγραμματισμού – Η γλώσσα Prolog (Η. Σακελλαρίου, Ν. Βασιλειάδης, Π. Κεφαλάς, Δ. Σταμάτης) 
%% ΚΕΦΑΛΑΙΟ 12 

solve(X,Y,Z) :-
    member(X,[4,5,6,7,8]),
    member(Y,[1,2,3,4,5,6,7,8]),
    member(Z,[6,7,8,9,10]),
    X =:= Y +1,
    Z<X,
    write([X,Y,Z]),nl,fail.