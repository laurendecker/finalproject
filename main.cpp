/*
 * CSCI 261: Final Project - Recruiting Profile Generator
 * Authors: Lauren Decker (Section C) and Renata Boyd (Section E)
 *
 */
#include <iostream>
#include "Player.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {

    // INITIALIZING PLAYER CLASS
    Player player;

    // USER INPUTS FILE NAME, CHECKS FOR ERRORS WHILE OPENING
    cout << "Hi! Welcome to the softball recruiting tool! This will help you filter through players by stats to find the type of player you're looking for." << endl;
    cout << "Enter the name of the file with the player information:";
    string file;
    cin >> file;
    ifstream dataFile(file);
    if (dataFile.fail()) {
        cerr << "Error opening input file";
        return -1;
    }

    // READS IN FILE INFO AND CREATES VECTOR OF PLAYERS
    vector<Player> playerVec;
    playerVec = player.readInFile(dataFile);

    // CLOSES FILE
    dataFile.close();

    // ASK HOW MANY REQUIREMENTS WANT TO SEARCH BY (1-3), CHECKS FOR VALID INPUT
    int requirements;
    requirements = player.numRequirements();

    //PRINT LIST OF REQUIREMENT OPTIONS
    player.printRequirementList();

    //ASKING WHAT REQUIREMENTS TO FILTER BY, CHECKS FOR VALID INPUT
    cout << "Enter the number of the requirements you would like to filter by:" << endl;
    int num1;
    int num2;
    int num3;
    // If the user chooses one requirement
    if (requirements == 1) {
        cout << "REQUIREMENT 1 >>";
        cin >> num1;
        num1 = player.checkChosenRequirements(num1);
    }
    // If the user chooses two requirements
    if (requirements == 2) {
        cout << "REQUIREMENT 1 >>";
        cin >> num1;
        num1 = player.checkChosenRequirements(num1);
        cout << "REQUIREMENT 2 >>";
        cin >> num2;
        num2 = player.checkChosenRequirementsTwo(num1, num2);
    }
    // If the user chooses three requirements
    if (requirements == 3) {
        cout << "REQUIREMENT 1 >>";
        cin >> num1;
        num1 = player.checkChosenRequirements(num1);
        cout << "REQUIREMENT 2 >>";
        cin >> num2;
        num2 = player.checkChosenRequirementsTwo(num1, num2);
        cout << "REQUIREMENT 3 >>";
        cin >> num3;
        num3 = player.checkChosenRequirementsThree(num1, num2, num3);
    }

    // DECLARING VECTORS FOR REQUIREMENT INPUT
    vector<Player> matches;
    vector<Player> matches2;
    vector<Player> matches3;

    //  ONE REQUIREMENT

    if (requirements == 1) {
        // If user chooses age
        if (num1 == 1) {
            player.func1(playerVec, matches);
        }
        // If user chooses batting average
        if (num1 == 2) {
            player.func2(playerVec, matches);
        }
        if (num1 == 3) {
            player.func3(playerVec, matches);
        }
        if (num1 == 4) {
            player.func4(playerVec, matches);
        }
        if (num1 == 5) {
            player.func5(playerVec, matches);
        }
        if (num1 == 6) {
            player.func6(playerVec, matches);
        }
        if (num1 == 7) {
            player.func7(playerVec, matches);
        }
        if (num1 == 8) {
            player.func8(playerVec, matches);
        }
    }

        // TWO REQUIREMENTS

    else if (requirements == 2) {
        // If user chooses age
        if (num1 == 1) {
            player.func1(playerVec, matches);
        }
        // If user chooses batting average
        if (num1 == 2) {
            player.func2(playerVec, matches);
        }
        if (num1 == 3) {
            player.func3(playerVec, matches);
        }
        if (num1 == 4) {
            player.func4(playerVec, matches);
        }
        if (num1 == 5) {
            player.func5(playerVec, matches);
        }
        if (num1 == 6) {
            player.func6(playerVec, matches);
        }
        if (num1 == 7) {
            player.func7(playerVec, matches);
        }
        if (num1 == 8) {
            player.func8(playerVec, matches);
        }

        //second requirement
        if (num2 == 1) {
            player.func1(playerVec, matches2);
        }
        if (num2 == 2) {
            player.func2(playerVec, matches2);
        }
        if (num2 == 3) {
            player.func3(playerVec, matches2);
        }
        if (num2 == 4) {
            player.func4(playerVec, matches2);
        }
        if (num2 == 5) {
            player.func5(playerVec, matches2);
        }
        if (num2 == 6) {
            player.func6(playerVec, matches2);
        }
        if (num2 == 7) {
            player.func7(playerVec, matches2);
        }
        if (num2 == 8) {
            player.func8(playerVec, matches2);
        }
    }

        // THREE REQUIREMENTS THREE REQUIREMENTS THREE REQUIREMENTS

    else if (requirements == 3) {
        if (num1 == 1) {
            player.func1(playerVec, matches);
        }
        if (num1 == 2) {
            player.func2(playerVec, matches);
        }
        if (num1 == 3) {
            player.func3(playerVec, matches);
        }
        if (num1 == 4) {
            player.func4(playerVec, matches);
        }
        if (num1 == 5) {
            player.func5(playerVec, matches);
        }
        if (num1 == 6) {
            player.func6(playerVec, matches);
        }
        if (num1 == 7) {
            player.func7(playerVec, matches);
        }
        if (num1 == 8) {
            player.func8(playerVec, matches);
        }

        //second requirement
        if (num2 == 1) {
            player.func1(playerVec, matches2);
        }
        if (num2 == 2) {
            player.func2(playerVec, matches2);
        }
        if (num2 == 3) {
            player.func3(playerVec, matches2);
        }
        if (num2 == 4) {
            player.func4(playerVec, matches2);
        }
        if (num2 == 5) {
            player.func5(playerVec, matches2);
        }
        if (num2 == 6) {
            player.func6(playerVec, matches2);
        }
        if (num2 == 7) {
            player.func7(playerVec, matches2);
        }
        if (num2 == 8) {
            player.func8(playerVec, matches2);
        }

        //third requirement
        if (num3 == 1) {
            player.func1(playerVec, matches3);
        }
        if (num3 == 2) {
            player.func2(playerVec, matches3);
        }
        if (num3 == 3) {
            player.func3(playerVec, matches3);
        }
        if (num3 == 4) {
            player.func4(playerVec, matches3);
        }
        if (num3 == 5) {
            player.func5(playerVec, matches3);
        }
        if (num3 == 6) {
            player.func6(playerVec, matches3);
        }
        if (num3 == 7) {
            player.func7(playerVec, matches3);
        }
        if (num3 == 8) {
            player.func8(playerVec, matches3);
        }}

        //FILTERING FOR THE MATCHES THAT MEET ALL REQUIREMENTS AND OUTPUT
        int count = 0;
        vector<Player> FinalMatches, FinalMatchesA;

        if (requirements == 1) {
            FinalMatches = matches;
        }else if (requirements == 2) {
            FinalMatches = player.realMatches(matches, matches2);
        }else {
            FinalMatchesA = player.realMatches(matches, matches2);
            FinalMatches = player.realMatches(matches3, FinalMatchesA);
        }
        for (int i = 0; i < FinalMatches.size(); i++) {
            count++;
        }

        ofstream myFile("playerMatches.txt");
        player.outputFile(FinalMatches, myFile);
        if (count == 0){
            cout << "We didn't find any players that matched the criteria of your search." << endl;
            cout << "Thank you for using our softball recruiting tool!";
        }
        else {
            cout << "You have " << count << " player(s) that match your search!" << endl;
            cout << "Profiles on these players have been output to the file named: 'playerMatches.txt'" << endl;
            cout << "Thank you for using our softball recruiting tool!";
        }
        return 0;
}
