HOMEWORK 6: STAR BATTLE


NAME:  Arnav Pawar


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Colin, Steven H, Jai, Theodore, Flyn, GeeksForGeeks

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  16


ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:

(running time order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of zones (z)? 
The average number of squares in a zone (t) 
The number of stars per zone(s)? 
etc.

BIG O of reccursive function: O( (t^s)^z )

This big o represents that the recursive function starts with branching off one for every spot on the board. Based on the number of stars per zone this will then cause the depth to increase. Causing the big o for one zone to be (t^s). Then each branch will then branch off into more depths in recursion based on the number of zones. This causes the function to take O( (t^s) ^z) amount of time. 

My recursive function starts by placing a star down. If that zone is full it will carry on to the next zone. If not it will place the second star then keep placing until the zone gets full. Then based on that placement the call will move to the next zone. This cycle will continue fining every orientation saving the given solutions. 


DESCRIPTION OF YOUR ADDTIONAL PUZZLES:
Briefly explain the design of the puzzles or dictionaries and what
makes them "interesting" test cases (or why they aren't interesting).

TEST1.txt -> 19 possible solutions for S=1 and 0 for S=2
	  -> made this test case to test a smaller grid with more than 2 zones
	  -> each corner had its own Zone
	  -> grid was 1 4x4 grid with 3 different zones 2 with size 5 and one with size 6

TEST2.txt -> 16 possible solutions for S=1, 78 for S=2, and 140 for S=3
	  -> i used this test case to check if my stars were going to go in every orientation in every position in the grid
	  -> grid was 1 4x4 grid with 1 zone that stored all 16 spots

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES AND 
ON YOUR ADDITIONAL PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles / stars per zone for a single solution or all solutions. Be
specific about which puzzle/parameters you were timing.

*if time not given code took 1-2 seconds to run*

custom1.txt
	-S=1 -> solutions:17
	-S=2 -> solutions:3
	-S=3 -> solutions:0
custom2.txt
	-S=1 -> solutions:50
	-S=2 -> solutions:142
	-S=3 -> solutions:16
custom3.txt
	-S=1 -> solutions:0
	-S=2 -> solutions:0
	-S=3 -> solutions:0
	-S=4 -> solutions:0
	-S=5 -> solutions:0
sporcle.txt
	-S=1 -> solutions:1
twonot1.txt
	-S=1 -> solutions:1193 (2 secs)
	-S=2 -> solutions:1 
	-S=3 -> solutions:0
twonot2.txt
	-S=1 -> solutions:2372207 (ran for 8 mins)
	     -> one solution: ran for 4 secs
	-S=4 -> solutions:0

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


