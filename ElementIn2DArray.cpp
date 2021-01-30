// Q Search an Element in a sorted matrix 
// A sorted matrix is a matrix such that all the elements in a row are sorted and first element of second row is greater than last element of first row and so on..

// 1.       5.       9
// 14     20.     34
// 34.   34.     43

// x=34
int n,m;
int searchrow(int mat[m][], int x, int l, int h)
{
    int mid = l/2 + (h-l)/2;
    if(x>mat[mid][n-1] && x<=mat[mid+1][n-1] ) return mid+1;
    else if(x<=mat[mid][n-1] && x>mat[mid-1][n-1]) return mid-1;
    else if(x>mat[mid][n-1]) return searchrow(mat, x, mid+1, h);
    else return searchrow(mat,x,l,mid);
}

int searchinrow(int mat[m][], int x, int row, int l, int h)
{
    int mid = l/2 + (h-l)/2;
    if(x == mat[row][mid])
    {
        cout<<row<<" , "<<mid<<endl;
        return 1;
    }
    else if(x > mat[row][mid]) searchinrow(mat,x,row,mid+1,h)
    else if(x < mat[row][mid]) searchinrow(mat, x, row, l, mid-1);
    return 0;
}

void searchelem(int mat[m][], int x)
{
    if(x < mat[0][0] || x > mat[m-1][n-1]) cout<<"-1 -1"<<endl;
    int row = searchrow(mat,x,0,m-1);
    
    int flag = searchinrow(mat,x,row,0,n-1);
    if(!flag) cout<<"-1 -1"<<endl;
}


