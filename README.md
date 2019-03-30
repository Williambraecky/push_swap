# push_swap

Sorting algorithm in C.

Sort stack A using a limited set of instructions by using stack B.

# Rules

- One instruction per line
- Stack A must be sorted at the end of the run
- User must provide a checker to check if the stack is indeed sorted

# Instructions

- sa: swap a: Swaps the first 2 elements of stack A.
- sb: swap b: Swaps the first 2 elements of stack B.
- ss: sa and sb combined. (Counts as one instruction)
- pa: push a: Takes the first element at the top of stack b and put it at the top of stack a.
- pb: push b: Takes the first element at the top of stack a and put it at the top of stack b.
- ra: rotate a: Shifts every element of stack a up by 1, the first element becomes the last.
- rb: rotate b: Shifts every element of stack b up by 1, the first element becomes the last.
- rr: ra and rb combined. (Counts as one instruction)
- rra: reverse rotate a: Shifts every element of stack a down by 1, the last element becomes the first.
- rrb: reverse rotate b: Shifts every element of stack b down by 1, the last element becomes the first.
- rrr: rra and rrb combined. (Counts as one instruction)

# How did I do it?

I wasn't feeling like quicksort was a good algorithm (turns out it was false) for this project with all these restrictions so I went with an algorithm I thought of myself (probably already exists however I don't know the name of it).

My goal is to sort everything in stack B in reverse and then push everything back to a. For this I process which element will take the less amount of operation to move at the right spot in stack B and then of course move it.

Once everything is in B (or the current state of A is sorted or there is 5 or less elements in stack A) I push everything back into stack A carefully to have it all sorted.

I try to use rr and rrr the maximum however I think I might have failed the math on this project a little bit.

I am not very proud of this algorithm as it is very slow with a lot of elements however it's very efficient with 100~ elements compared to quicksort.

# Usage

- First of all use the make command to compile everything (may only work on linux)

All three executable use the same function to parse arguments so you can either use:

- ./exec "1 2 3 ..."
OR
- ./exec 1 2 3 4 . . .
But not a combination of both

### Checker
 [./push_swap X Y Z ... |] ./checker X Y Z . . .
 - Options:
  - [-v]: Verbose mode (prints the pile in the terminal for every move NOT RECOMMENDED)
  - [-i file]: Instead of reading the piped input (or the terminal), reads through a file
  
 You can also type every instruction by hand to test the checker.
 
 The checker will print either OK or KO depending if the stack a is sorted or not.
### Push_swap
 ./push_swap X Y Z . . .
 - Options:
  - [-o file]: Defines an output file instead of writing the instructions to the terminal.
  
  The push_swap will execute the actual algorithm and print every instruction it uses.
  
### Visualizer
 [./push_swap X Y Z ... |] ./visualizer X Y Z . . .
 - Options:
  - [-i file]: Instead of reading the piped input (or the terminal), reads through a file
  
  The visualizer is a graphical representation of what the push_swap executable does using our school's graphical library (minilibX)
