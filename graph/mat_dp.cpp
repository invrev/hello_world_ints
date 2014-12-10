#include<iostream>
#include<limits.h>
using namespace std;


int compute_mat_mult (int mat[],int i,int j) {
    int min_cost=INT_MAX;
    if (i == j) {
        return 0;
    } else {
        for (int k=i;k<j;k++) {
           min_cost = min (min_cost, ( compute_mat_mult(mat,i,k) 
                                     + compute_mat_mult(mat,k+1,j)
                                     + mat[i-1] * mat[k] * mat[j]) ) ;
        }
    }
   return min_cost;
}


// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
 
    /* For simplicity of the program, one extra row and one extra column are
       allocated in m[][].  0th row and 0th column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    /* m[i,j] = Minimum number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is
       p[i-1] x p[i] */
 
    // cost is zero when multiplying one matrix.
    //All diagonal elements = 0
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.  
    //From recurrence relation : T(n) =  m=1 to n-1 (T(m) + T(n-m)) + dn here L=m
    for (L=2; L<n; L++)   
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1; //end parenthesis / length of parenthesis
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                // q = cost/scalar multiplications
                //q = min ( m[i][j],m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
                m[i][j] = min ( m[i][j],m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
                //if (q < m[i][j])
                //    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}



int main () {
    int mat[] = {1,2,3,4,3};
    int n = sizeof(mat)/sizeof(mat[0]);
    int min_cost = compute_mat_mult (mat,1,n-1); // Reason mat[i-1]
    cout << "the result of computation " << min_cost << endl;

    min_cost = MatrixChainOrder (mat,n);
    cout << "the result of computation " << min_cost << endl;
}
