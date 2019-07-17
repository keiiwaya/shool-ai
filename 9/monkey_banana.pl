move( state( P1, onfloor, P1, H ),
      push( P1, P2 ),write('push to '),write(P2),nl,
      state( P2, onfloor, P2, H ) ).

move( state( P, onfloor, P, H ),
      climb,write('climb at '),write(P),nl,
      state( P, onbox, P, H ) ).

move( state( P1, onfloor, B, H ),
      walk( P1, P2 ),write('walk to '),write(P2),nl,
      state( P2, onfloor, B, H ) ).

move( state( middle, onbox, middle, hasnot ),
      grasp,write('grasp '),write(banana),nl,
      state( middle, onbox, middle, has ) ).





canget( state( _, _, _, has ) ).
canget( State1 ) :-
	move( State1, Move, write(X),write(Y),nl, State2 ),write(X),write(Y),nl,
	canget( State2 ).
