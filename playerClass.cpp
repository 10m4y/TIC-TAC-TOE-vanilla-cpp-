#include "playerClass.h"
#include <iostream>
using namespace std;

player::player(string name) {
    this->name = name;
    matches_played = 0;
    wins = 0;
    lost = 0;
    win_percentage = 0;
    player_type = "NO GAME PLAYED";
}

void player::player_stats() {
    cout << "Name : " << name << endl;
    cout << "Player Type : " << player_type << endl;
    cout << "Total Matches Played : " << matches_played << endl;
    cout << "Won : " << wins << endl;
    cout << "Lost : " << lost << endl;
    cout << "Win % : " << win_percentage << endl;
}

void player::player_stats_changed(int result) {
    matches_played++;
    if(result == 0){
        lost++;
    } else if(result == 1){
        wins++;
    }
    win_percentage = calculation_of_percentage(matches_played, wins);
    player_type = calculation_of_player_type(matches_played, wins, lost);
}

float player::calculation_of_percentage(int matches_played, int wins) {
    return (100.0f * wins) / matches_played;
}

string player::calculation_of_player_type(int matches_played, int wins, int lost) {
    int temp = calculation_of_percentage(matches_played, wins);
    if (temp >= 40 && (matches_played - wins - lost) > wins)
        return "ATTACKING";
    else
        return "DEFENSIVE";
}
