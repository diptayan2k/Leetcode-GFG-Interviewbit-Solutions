class Solution {
public:
    
    void Nqueen(int i, int j, int count, int n,
                 vector<vector<string> >& ans,
                 vector<vector<bool> >& board, 
                 vector<bool>& row, 
                 vector<bool>& col,
                 vector<bool>& diar,
                 vector<bool>& dial,
                 vector<string>& v
               )
    {
        if(count!=i) return;
        if(i==n)
        {
            if(count==n)
            {
                ans.push_back(v);
                
                
            }
            return;
            
            
        }
        
    
        
        if(!row[i] and !col[j] and !diar[i+j] and !dial[n+(i-j)])
        {
            board[i][j] = 1;
            v[i][j]='Q';
            row[i]=1;
            col[j]=1;
            diar[i+j]=1;
            dial[n+(i-j)] = 1;
            
            Nqueen(i+1,0,count+1,n,ans,board,row,col,diar,dial,v);
            
            board[i][j] = 0;
            v[i][j] = '.';
            row[i]=0;
            col[j]=0;
            diar[i+j]=0;
            dial[n+(i-j)] = 0;
                
        }
        
            
        if(j<n-1)
            Nqueen(i,j+1,count,n,ans,board,row,col,diar,dial,v);
        else 
            Nqueen(i+1,0, count,n,ans,board,row,col,diar,dial,v);
            
            
        
        
        
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<bool> > board(n,vector<bool>(n,0));
        vector<bool> row(n,0);
        vector<bool> col(n,0);
        vector<bool> diar(2*n,0);
        vector<bool> dial(2*n,0);
        string s;
        for(int i =0; i<n; i++) s+=".";
        vector<string> v(n,s);
        vector<vector<string> > ans;
        
        Nqueen(0,0,0,n,ans,board,row,col,diar,dial,v);
        
        return ans;
    }
};