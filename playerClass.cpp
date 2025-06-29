#include <bits/stdc++.h>
using namespace std;

class player{
    public:
        string name;
    private:
        int matches_played;    
        int wins;
        int lost;
        float win_percentage;
        string player_type;

    public:
        
        void player(string name){
            name;
            matches_played=0;
            wins=0;
            lost=0;
            win_percentage=0;
            player_type="NO GAME PLAYED";
        }

        void player_stats_changed(int result){
            matches_played++;
            if(result==0){
                lost++;
            }
            else if(result==1){
                wins++;
            }
            win_percentage=calculation_of_percentage(matches_played,wins);
            player_type=calculation_of_player_type(matches_played,won,lost);
        }
    private:
        float calculation_of_percentage(int matches_played,int wins){
            return (wins/matches_played)*100;
        }
        string calculation_of_player_type(int matches_played,int won,int lost){
            int temp=calculation_of_percentage(matches_played,wins);
            if(temp>=40 && matches_played-won-lost>won)return "ATTACKING";
            else return "DEFFENSIVE";

        }




}