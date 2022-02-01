Kiki Ogino
Lab 3

Test Cases I ran:
1. Valid arguments ("quit" and all coordinates from 1,1 to 3,3)
2. Invalid arguments:
	- 12
	- 11,11
	- 4,4
	- 1.2
	- 1 2
	- hi 
	- , 
	- various strings 
	- 1,23
3. Full games:
	- Someone should win vertically
	- Someone should win horizontally
	- Someone should win diagonally (both diagonals)
	- Tie game 

Issues I ran into:
- I really struggled with having the pieces show up in the right spots on the gameboard. I used an indeixing method 
that used a square with indices assigned:
 _______________
| 16 | 17 | 18 |
|____|____|____|
| 11 | 12 | 13 |
|____|____|____|
| 6  |  7 |  8 |
|____|____|____|
I debugged this by printing out the indices I was calculating in my code as I calculated them, as well as using 
the debugger to see what the index values at several steps. I also created an index() function to easily calculate
the index and avoid errors in areas when I needed to do the arithmetic. 

- I also spent a lot of time on the done() method, because the if(p1==p2==p3) would never enter even if I had 3 in a row.
I initially thought the issue was with the stored pieceTypes, but after using the debugger I saw that while p1,p2,p3
were equal, they were not entering the if statement. I resolved this when realizing the syntax of (p1==p2==p3) had to 
be changed to (p1==p2 && p2==p3).

 