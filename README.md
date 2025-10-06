# pathfinding with backtracking

A backtracking algorithm to find a key in a building with restricted corridors.

## the problem

You start at a position in a building and need to find a key marked with `*`. The building has corridors that restrict your movement:

- `H` corridors allow only horizontal movement (left/right)
- `V` corridors allow only vertical movement (up/down)
- `*` marks the key location

The program uses recursive backtracking to explore all possible paths until it finds the key or exhausts all options.

## how it works

The algorithm starts at the given position and tries to move in all valid directions. For each position:

- If it's the key location, success
- Mark the current position as visited
- Try moving up (if current corridor is `V`)
- Try moving down (if current corridor is `V`)
- Try moving left (if current corridor is `H`)
- Try moving right (if current corridor is `H`)
- If no path works, backtrack by unmarking the position

Each movement checks:
- Position is within map boundaries
- Position hasn't been visited yet
- Current corridor type allows that direction

## input format

Input files should contain:

- First line: number of floors
- Next lines: map of the building using H, V, and *
- Last line: starting position (row column)

Example:

```
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 0
```

## compilation and running

Compile the program:

```
gcc -o main.exe *.c
```

Run with an input file from the Tests directory:

```
main.exe Tests\entrada_teste1.txt
```

Or use the provided batch script to automatically test all files in the Tests directory:

```
run_tests.bat
```

## output

The program prints whether the key was found:

- "Key found in building!" if successful
- "Could not find the key in building." if no path exists
- "Error: Key '*' not found in map" if the input file has no key marker

## test files

The project includes several test cases in the Tests directory:

- `entrada_teste1.txt`, `entrada_teste2.txt`, `entrada_teste3.txt` - basic test cases
- `edge_case*.txt` - edge cases and special situations

See `instructions.md` for detailed descriptions of each test case.
