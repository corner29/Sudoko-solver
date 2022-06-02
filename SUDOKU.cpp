#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define ll long long
#define ld long double
#define f(i,a,b) for(auto i=a;i<b;i++) 
#define mb make_pair
#define mk make_tuple
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vii vector<int,int>
#define vll vector<ll,ll>
#define mpi map<int,int>
#define mpl map<ll,ll>

void findthelocation(vector<vector<ll>>&graph,ll &row,ll &col,bool &condition){
    f(p,0,9){
        f(q,0,9){
            if(graph[p][q]==0){
                condition=false;row=p;col=q;return;
            }
        }
    }
}

bool checkforrow(vector<vector<ll>>&graph,ll row,ll col,ll target){
    f(i,0,9){
        if(graph[i][col]==target){
            return false;
        }
    }
    return true;
}

bool checkforcol(vector<vector<ll>>&graph,ll row,ll col,ll target){
    f(i,0,9){
        if(graph[row][i]==target){
            return false;
        }
    }
    return true;
}

bool condition(vector<vector<ll>>graph,ll row,ll col,ll target){
    f(i,row,row+3){
        f(j,col,col+3){
            if(graph[i][j]==target){
                return false;
            }
        }
    }
    return true;
}

bool checkforsquare(vector<vector<ll>>&graph,ll row,ll col,ll target){
    return condition(graph,row-row%3,col-col%3,target);
}

bool check(vector<vector<ll>>&graph,ll row,ll col,ll k){
    return checkforrow(graph,row,col,k) and checkforcol(graph,row,col,k) and checkforsquare(graph,row,col,k) and graph[row][col]==0;
}

bool solve(vector<vector<ll>>&graph){
    ll row,col;
    bool condition=true;
    findthelocation(graph,row,col,condition);
    if(condition){
        return true;
    }
    f(k,1,10){
        if(check(graph,row,col,k)){
            graph[row][col]=k;
            if(solve(graph)){
                return true;
            }
            graph[row][col]=0;
        }
    }
    return false;
}

void print(vector<vector<ll>>&graph){
    for(auto x:graph){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return;
}

void just_do_it(){
    vector<vector<ll>>graph={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    // Above is a test case,to use this code, delete the above defined graph and de-comment the below written code
    // after that you can enter your sudoku puzzle and get a correct answer every time.
    // You need to enter how many time you want to play then enter the 
    // numerical value given in your puzzle and enter 0 at location which are to be filled
    // IN case the input would be false the output NOT_POSSIBLE would be shown 
    // THANK YOU AND HAPPY SUDOKU solving
    //vector<vector<ll>>graph(9,vector<ll>(9,0));
    /*f(i,0,9){
        f(j,0,9){
            cin>>graph[i][j];
        }
    }*/
    if(solve(graph)){
        print(graph);
    }
    else{
        cout<<"NOT_POSSIBLE"<<endl;
    }
    return;
}

int main()
{
    io;
    ll n;
    cin>>n;
    while(n--){
        just_do_it();
    }
    return 0;
}
