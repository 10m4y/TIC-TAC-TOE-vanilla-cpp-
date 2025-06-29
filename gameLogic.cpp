#include "playerClass.h"
#include "winLogic.h"
#include<bits/stdc++.h>
using namespace std;

int main(){

    string player1,player2;
    cout<<"ENTER PLAYER 1 NAME"<<endl;
    cin>>player1;
    player p1(player1);
    cout<<"ENTER PLAYER 2 NAME"<<endl;
    cin>>player2;
    player p2(player2);

    while(true){
        vector<vector<int>>board(3,vector<int>(3,-1));
        string result="NO ONE";
        for(int i=0;i<10;i++){
            if(i==9)break;
            cout<<"x-coordinate for your chance(0-based indexing)";
            int x;
            cin>>x;
            cout<<"y-coordinate for your chance(0-based indexing)";
            int y;
            cin>>y;

            if(i%2==0){
                board[y][x]=1;
                if(checkWin(board)){
                    result=p1.name;
                    p1.player_stats_changed(1);
                    p2.player_stats_changed(0);
                    break;
                };
            }
            else{
                board[y][x]=0;
                if(checkWin(board)){
                    result=p2.name;
                    p1.player_stats_changed(0);
                    p2.player_stats_changed(1);
                    break;
                };

            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        int menu;
        cout<<"WINNER OF THIS GAME IS "<<result<<endl;
        cout<<"press 3 to restart match";
        cout<<"press 1 to see stats of "<<p1.name <<" and 2 to see stats of "<<p2.name;
        cout<<endl<<"AND press 0 if u are tired "<<endl;
        cin>>menu;
        if(menu==0)break;
        else if(menu==1){
            p1.player_stats();
        }
        else if(menu==2){
            p2.player_stats();
        }
        else{
            continue;
        }



    }





    return 0;
}