#include<bits/stdc++.h>
using namespace std;
char mp[8][8]{
    '.','.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.','.',
    '.','.','.','O','X','.','.','.',
    '.','.','.','X','O','.','.','.',
    '.','.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.','.'
};
bool goN(int i,int j,char x){
    if(i<0){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goN(i-1,j,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goNE(int i,int j,char x){
    if(i<0||j==8){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goNE(i-1,j+1,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goE(int i,int j,char x){
    if(j==8){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goE(i,j+1,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goSE(int i,int j,char x){
    if(i==8||j==8){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goSE(i+1,j+1,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goS(int i,int j,char x){
    if(i==8){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goS(i+1,j,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goSW(int i,int j,char x){
    if(i==8||j<0){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goSW(i+1,j-1,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goW(int i,int j,char x){
    if(j<0){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goW(i,j-1,x)){mp[i][j]=x; return true;}
    return false;
}
 
bool goNW(int i,int j,char x){
    if(i<0||j<0){return false;}
    if(mp[i][j]=='.'){return false;}
    if(mp[i][j]==x){return true;}
    
    if(goNW(i-1,j-1,x)){mp[i][j]=x; return true;}
    return false;
}
 
int main(){
    int n;scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        int a,b; char s;
        scanf(" %c %d",&s,&a);
        a=a-1; b=s-'a';
        
        if(i%2!=0){
            bool b1=goN(a-1,b,'X');
            bool b2=goNE(a-1,b+1,'X');
            bool b3=goE(a,b+1,'X');
            bool b4=goSE(a+1,b+1,'X');
            bool b5=goS(a+1,b,'X');
            bool b6=goSW(a+1,b-1,'X');
            bool b7=goW(a,b-1,'X');
            bool b8=goNW(a-1,b-1,'X');
            if(b1||b2||b3||b4||b5||b6||b7||b8)
            {mp[a][b]='X';}
        }
        else{
            bool b1=goN(a-1,b,'O');
            bool b2=goNE(a-1,b+1,'O');
            bool b3=goE(a,b+1,'O');
            bool b4=goSE(a+1,b+1,'O');
            bool b5=goS(a+1,b,'O');
            bool b6=goSW(a+1,b-1,'O');
            bool b7=goW(a,b-1,'O');
            bool b8=goNW(a-1,b-1,'O');
            if(b1||b2||b3||b4||b5||b6||b7||b8)
            {mp[a][b]='O';}
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c",mp[i][j]);
        }printf("\n");
    }
    
    return 0;
}
