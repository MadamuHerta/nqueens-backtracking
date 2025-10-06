/*
 * Pathfinding with Backtracking
 * Building key finder using recursive backtracking algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables
char map[100][100];
int visited[100][100];
int n_rows, n_cols;
int start_row, start_col;
int key_row, key_col;

// recursive backtracking function to find the key
// movement rules:
// - 'H' corridors: allow only horizontal movement (left/right)
// - 'V' corridors: allow only vertical movement (up/down)
// - '*' marks the key position (goal)
int find_key(int row, int col) {
    // base case: check if we reached the key position
    // if yes, return 1 (success) and stop recursion
    if (row == key_row && col == key_col) {
        return 1;
    }

    // mark as visited to prevent infinite loops
    // mark current position so we don't come back here
    visited[row][col] = 1;
    
    // try moving up (row - 1)
    if (row - 1 >= 0 &&                      // check: don't go out of map bounds
        !visited[row - 1][col] &&            // check: position not already visited
        map[row][col] == 'V') {              // check: current corridor must be 'V' for vertical movement

        if (find_key(row - 1, col)) {        // recursion: try path from new position
            return 1;                        // if found key through this path, return success
        }
    }
    
    // try moving down (row + 1)
    if (row + 1 < n_rows &&                  // check: don't exceed number of rows
        !visited[row + 1][col] &&            // check: position not already visited
        map[row][col] == 'V') {              // check: current corridor must be 'V' for vertical movement

        if (find_key(row + 1, col)) {
            return 1;
        }
    }
    
    // try moving left (col - 1)
    if (col - 1 >= 0 &&                      // check: don't go out left side of map
        !visited[row][col - 1] &&            // check: position not already visited
        map[row][col] == 'H') {              // check: current corridor must be 'H' for horizontal movement

        if (find_key(row, col - 1)) {
            return 1;
        }
    }
    
    // try moving right (col + 1)
    if (col + 1 < n_cols &&                  // check: don't exceed map width
        !visited[row][col + 1] &&            // check: position not already visited
        map[row][col] == 'H') {              // check: current corridor must be 'H' for horizontal movement

        if (find_key(row, col + 1)) {
            return 1;
        }
    }
    
    // backtrack: no path worked from this position
    // unmark as visited to allow other paths to pass through here
    // failure can happen because:
    // 1. no more valid movements (ex: all H without V to change row)
    // 2. key is isolated by wrong type of corridors
    // 3. all possible routes already visited
    visited[row][col] = 0;
    return 0;  // return failure - no path found from this position
}

// function to read the input file
// usage: ./program your_file_name.txt
// assuming correct file format, no inconsistencies or need for verification
// assuming the file exists and is in the same directory as executable
int read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    // read number of rows
    fscanf(file, "%d", &n_rows);

    // read the map
    for (int i = 0; i < n_rows; i++) {
        fscanf(file, "%s", map[i]);
    }

    // read starting position
    fscanf(file, "%d %d", &start_row, &start_col);

    fclose(file);

    // calculate number of columns and find the key position
    n_cols = strlen(map[0]);
    key_row = -1;
    key_col = -1;
    
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (map[i][j] == '*') {
                key_row = i;
                key_col = j;
                break;
            }
        }
        if (key_row != -1) break;
    }

    // check if the key was found
    if (key_row == -1 || key_col == -1) {
        printf("Error: Key '*' not found in map\n");
        return 0;
    }

    return 1;
}

// function to initialize the visited matrix
void initialize_visited() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = 0;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // file read and initialization handling
    if (!read_file(argv[1])) {
        return 1;
    }

    initialize_visited();

    // call the backtracking function
    int result = find_key(start_row, start_col);

    // print the result
    if (result) {
        printf("Key found in building!\n");
    } else {
        printf("Could not find the key in building.\n");
    }

    return 0;
}