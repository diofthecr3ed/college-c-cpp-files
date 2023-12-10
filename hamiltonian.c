#include <stdio.h>
#define N 10 // define max vertex count
int visited[N] = {0};

int n = 4;
int adj[N][N] ={{0,1,1,0},{1,0,0,1},{1,0,0,1},{0,1,1,0}};

// function to check if all elements are distinct in the path found. This solves part of the hamiltonian problem. 
int distinctElems(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 0; 
            }
        }
    }
    return 1;
}

// function to check if after all elements being distinct if the fist element connects to the last element in the path.  
int isHam(int * path){
    if (distinctElems(path, n)) {
        if (adj[path[n - 1]][path[0]] == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

// recursive backtracking fucntion. 
int backtracking(int pointer, int * path) {
    
    if (pointer == n) {
        if (isHam(path)) { // end function if hamilton path found.
            return 1;
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && adj[path[pointer - 1]][i] == 1) {

            visited[i] = 1;
            path[pointer] = i;
            if (backtracking(pointer + 1, path) == 1) {
                return 1;
            }
            visited[i] = 0;
        }
    } 
    return 0;
}

int main(void) {
    int path[N];
    path[0] = 0;
    visited[0] = 1;
    if (backtracking(1, path) == 0) {
        printf("Not Hamiltonian\n");
    } else {
        printf("Hamiltonian\n");
    }

    return 0;
}
