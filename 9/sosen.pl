parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
sosen(X,Y) :- parent(X,Y). 	
sosen(X,Y) :- parent(Z,Y), sosen(X,Z).
sosen(X,Y) :- sosen(X,Z), parent(Z,Y).
