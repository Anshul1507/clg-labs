on(monkey,floor).
on(chair,floor).
at(banana,ceiling).
in(monkey,room).
in(banana,room).
in(chair,room).

strong(monkey).
grasp(monkey).
climb(monkey,chair).

push(monkey,chair):-
    strong(monkey).
under(chair,banana):-
    push(monkey,chair).
canreach(monkey,banana):-
    at(banana,floor); 
    at(banana,ceiling), under(chair,banana), climb(monkey,chair).
canget(monkey,banana):- canreach(monkey,banana), grasp(monkey).




//Common query:- canget(monkey,banana).
