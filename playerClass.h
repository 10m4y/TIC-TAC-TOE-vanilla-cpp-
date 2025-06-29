#pragma once
#include<string>
using namespace std;


class player{
    public:
        string name;
        player(string name);
        void player_stats();
        void player_stats_changed(int result);
    private:
        int matches_played;    
        int wins;
        int lost;
        float win_percentage;
        string player_type;
        float calculation_of_percentage(int matches_played,int wins);
        string calculation_of_player_type(int matches_played,int won,int lost);

        
};