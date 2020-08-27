weather(delhi,summer,hot).
weather(shimla,summer,warm).
weather(delhi,winter,warm).
warmer_than(C1,C2):-
    weather(C1,summer,hot),
    weather(C2,summer,warm),
    write(C1),write('is warmer than'),write(C2).





//Common query :- warmer_than(delhi,shimla).
