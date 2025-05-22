class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        //Approach 1 - SC - O(m+n);
        // vector<bool> row(m,false);
        // vector<bool> col(n,false);

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=true;
        //             col[j]=true;
        //         }
        //     }
        // }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(row[i]==true || col[j]==true){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        //Approach 2 - O(1) SC

        bool firstrowimpacted= false, firstcolimpacted = false;

        //check first row ya first col impacted he ya nahi
        //this is a corner case, because first row/col fails our intution

        for(int i=0;i<n;i++){
            if(matrix[0][i] == 0) firstrowimpacted =true;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0 ) firstcolimpacted = true;
        }

        //set markers in first row/col
        //as we have handled first row/col seperately, we will iterate from 1st row and col.

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        } 

        //now iterate to make whole row/col zero as asked in question

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        //now check if first row or col is impacted or not

        if(firstrowimpacted){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcolimpacted){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }

    }
};