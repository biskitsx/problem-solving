#include<iostream>

using namespace std;

int n,m,i,j ;

char map[31][31] ; 
bool visited[31][31] ={{false}}; 

//input
void readInput() {
    cin >> n >> m ;
    for (i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> map[i][j] ;
            if (map[i][j] == '#') {
                visited[i][j] = true ; 
            }
        }
    }
}

int normalSpace = 0;
int highSpace = 0 ; 

int countEach = 0; 
int countGrade = 0; 
//move
void traversal(int row,int column) {
    if (row == -1 || row == n || column == -1 || column == m || visited[row][column] ) {
        // cout << map[row][column] << endl ; 
        return ;
    }

    visited[row][column] = true ; 
    countEach++ ;
 
    if (map[row][column] == '$') {
        countGrade++ ;
    }

    else if (map[row][column] == '*') {
        countGrade++ ; 
    }
        
    traversal(row-1,column) ;
    traversal(row+1,column) ;
    traversal(row,column-1) ;
    traversal(row,column+1) ;
}

//
void eachSpace() {
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (!visited[i][j]) {

                countGrade = 0 ;
                countEach = 0 ;
                traversal(i,j) ; 

                if (countGrade == 2) {
                    highSpace += countEach ;
                }
                else if (countGrade == 1) {
                    normalSpace += countEach ; 
                }
            }
        }
    }

}

int main() {
    readInput() ;
    eachSpace() ; 
    cout << highSpace << ' ' << normalSpace ;
}