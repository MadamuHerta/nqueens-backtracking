# building pathfinder

a recursive backtracking algorithm to find a key in a building with corridor movement restrictions.

## how the program works

the program solves a pathfinding problem in a building where:

- you start at a given position
- you need to find a key marked with `*`
- corridors restrict your movement:
  - `H` corridors allow only horizontal movement (left/right)
  - `V` corridors allow only vertical movement (up/down)

the algorithm uses recursive backtracking to explore all possible paths. it marks positions as visited to avoid cycles, tries all valid directions, and backtracks when stuck.

## compilation

compile with gcc:

```
gcc -o main.exe *.c
```

## running the program

### method 1 - automatic testing (recommended)

run the batch script to compile and test all input files:

```
run_tests.bat
```

the script will:
- compile the program
- run all test files in the directory
- display results for each test

### method 2 - manual execution

run with a specific input file:

```
main.exe <filename>
```

example:

```
main.exe entrada_teste1.txt
```

## input file format

input files must follow this structure:

- first line: number of rows in the map
- next lines: the building map using H, V, and *
- last line: starting position (row column)

example:

```
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 0
```

## test cases

### basic tests

**entrada_teste1.txt** - basic pathfinding test
- 5x6 map with key at row 3, column 0
- starts at position (0, 0)
- tests basic backtracking with mixed corridors
- expected: key found

**entrada_teste2.txt** - different starting position
- same 5x6 map as test 1
- starts at position (0, 4)
- tests pathfinding from different start
- expected: key found

**entrada_teste3.txt** - larger complex map
- 7x9 map with key at row 4, column 8
- starts at position (0, 4)
- tests more complex pathfinding with longer paths
- expected: key found

### edge cases

**edge_case1_start_is_key.txt** - immediate success
- 1x1 map where starting position is the key
- tests base case where no movement needed
- expected: key found

**edge_case2_no_key.txt** - missing key
- 3x3 map without the `*` symbol
- tests error handling when key doesn't exist
- expected: error message

**edge_case3_isolated_key.txt** - unreachable key
- 3x3 map with key surrounded by horizontal corridors
- key at (1, 1) is isolated by H corridors
- starting position only has H corridors, cannot reach V corridor
- expected: key not found

**edge_case4_single_row.txt** - horizontal only map
- single row (1x5) with key at position 3
- tests pathfinding with only horizontal movement
- expected: key found

**edge_case5_single_col.txt** - vertical only map
- single column with vertical corridors
- tests pathfinding with only vertical movement
- expected: key found

**edge_case6_all_horizontal.txt** - horizontal corridors
- map with only H corridors
- tests movement restricted to horizontal plane
- expected: depends on key placement

**edge_case6.5_horizontal+v.txt** - mixed transition
- map with horizontal corridors and some vertical
- tests transitioning between corridor types
- expected: depends on connectivity

**edge_case7_unreachable.txt** - blocked path
- 3x3 map where corridors prevent reaching the key
- key at (2, 1), but corridor pattern blocks access
- tests backtracking when all paths fail
- expected: key not found

**edge_case8_key_at_start.txt** - start equals key
- similar to edge_case1, tests immediate success scenario
- expected: key found

## output

the program prints one of:

- "Key found in building!" - if path to key exists
- "Could not find the key in building." - if no valid path exists
- "Error: Key '*' not found in map" - if input file has no key marker

## algorithm details

the backtracking algorithm:

- marks current position as visited
- tries moving in all four directions (up, down, left, right)
- validates each move:
  - position is within map boundaries
  - position hasn't been visited
  - current corridor type allows that direction
- recursively explores valid moves
- unmarks position if all paths fail (backtracking)
- returns success if key is found, failure otherwise
