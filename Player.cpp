/*
 * CSCI 261: Final Project - Recruiting Profile Generator
 * Authors: Lauren Decker (Section C) and Renata Boyd (Section E)
 *
 */
#include "Player.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// GETTERS AND SETTERS
const string Player::getFirstName(){
    return _firstName;
}
void Player::setFirstName(string const newName){
    _firstName = newName;
}
const string Player::getLastName(){
    return _lastName;
}
void Player::setLastName(string const newName){
    _lastName = newName;
}
const int Player::getAge(){
    return _age;
}
void Player::setAge(const int newAge){
    _age = newAge;
}
const double Player::getBattingAverage(){
    return _battingAVG;
}
void Player::setBattingAverage(const double newBA){
    _battingAVG = newBA;
}
const int Player::getHomeRuns(){
    return _homeRuns;
}
void Player::setHomeRuns(const int newHR){
    _homeRuns = newHR;
}
const char Player::getRorL(){
    return _RorL;
}
void Player::setRorL(const char newRorL){
    _RorL = newRorL;
}
const string Player::getSwingOrSlap(){
    return _swingOrSlap;
}
void Player::setSwingOrSlap(const string newSorS){
    _swingOrSlap = newSorS;
}
const string Player::getMainPosition() {
    return _mainPosition;
}
void Player::setMainPosition(const string newMain) {
    _mainPosition = newMain;
}
const string Player::getSecondaryPosition() {
    return _secondaryPosition;
}
void Player::setSecondaryPosition(const string newSecondary) {
    _secondaryPosition = newSecondary;
}
const int Player::getFieldingOpportunities() {
    return _fieldingOpportunites;
}
void Player::setFieldingOpportunities(const int newFOpps) {
    _fieldingOpportunites = newFOpps;
}
const int Player::getSuccessfulFielding() {
    return _successfulFielding;
}
void Player::setSuccessfulFielding(const int newNoError) {
    _successfulFielding = newNoError;
}
const double Player::getPopTime() {
    return _popTime;
}
void Player::setPopTime(const double newPop) {
    _popTime = newPop;
}
const double Player::getERA(){
    return _ERA;
}
void Player::setERA(const double newERA){
    _ERA = newERA;
}
const double Player::getHomeToFirst() {
    return _homeToFirst;
}
void Player::setHomeToFirst(const double newHtoF) {
    _homeToFirst = newHtoF;
}
const int Player::getStolenBases() {
    return _stolenBases;
}
void Player::setStolenBases(const int newSB) {
    _stolenBases = newSB;
}

// READS IN DATA FROM INPUT FILE
vector<Player> Player::readInFile(ifstream &dataFile) {
    // Initializing vector and strings/ints/chars/doubles that need to be read in for each player
    vector<Player> playerVec;
    vector<Player> matches;
    string firstName, lastName, SorS, main, secondary;
    int numPlayers, age, HR, fOpps, noError, SB;
    char RorL;
    double battingAvg, popTime, ERA, HtoF;
    // Reads in the number of players in the file (will be the first number provided in the file)
    dataFile >> numPlayers;
    // Reads in all stats for each player and appends each player to the Player vector
    for (int i = 0; i < numPlayers; i++) {
        Player player1;
        dataFile >> firstName >> lastName >> age >> RorL >> SorS >> main >> secondary >> HR;
        dataFile >> fOpps >> noError >> battingAvg >> popTime >> ERA >> HtoF >> SB;
        player1.setFirstName(firstName);
        player1.setLastName(lastName);
        player1.setAge(age);
        player1.setRorL(RorL);
        player1.setSwingOrSlap(SorS);
        player1.setMainPosition(main);
        player1.setSecondaryPosition(secondary);
        player1.setHomeRuns(HR);
        player1.setFieldingOpportunities(fOpps);
        player1.setSuccessfulFielding(noError);
        player1.setBattingAverage(battingAvg);
        player1.setPopTime(popTime);
        player1.setERA(ERA);
        player1.setHomeToFirst(HtoF);
        player1.setStolenBases(SB);
        playerVec.push_back(player1);
    }
    return playerVec;
}

// FUNCTIONS THAT OBTAIN USER INPUT
// Gets number of requirements from user, checks if valid
int Player::numRequirements() {
    Player player;
    int requirements;
    cout << "How many requirements would you like to have for your search? (1-3):" ;
    cin >> requirements;
    requirements = player.checkNumRequirements(requirements);
    return requirements;
}

// FUNCTIONS THAT CHECK IF USER INPUT IS VALID
// Checks if user input for number of requirements is between 1 and 3
int Player::checkNumRequirements(int numRequire) {
    while ((numRequire > 3) || (numRequire < 1)) {
        cout << "Please enter 1, 2, or 3." << endl;
        cout << ">>";
        cin >> numRequire;
    }
    return numRequire;
}
// Checks if user input for chosen requirements is between 1 and 8 (1 requirement)
int Player::checkChosenRequirements(int chosenRequire) {
    while ((chosenRequire > 8) || (chosenRequire < 1)) {
        cout << "Please enter a number from 1 to 8." << endl;
        cout << ">>";
        cin >> chosenRequire;
    }
    return chosenRequire;
}
// Checks if user input for chosen requirements is a duplicate input (2 requirements)
int Player::checkChosenRequirementsTwo(const int chosenRequire1, int chosenRequire2) {
    Player player;
    while ((chosenRequire1 == chosenRequire2) || (chosenRequire2 < 1) || (chosenRequire2 > 8)) {
        cout << "Please enter a requirement that you haven't already chosen and is between 1 and 8." << endl;
        cout << ">>";
        cin >> chosenRequire2;
    }
    return chosenRequire2;
}
// Checks if user input for chosen requirements is a duplicate input (3 requirements)
int Player::checkChosenRequirementsThree(const int chosenRequire1, const int chosenRequire2, int chosenRequire3) {
    Player player;
    while ((chosenRequire3 == chosenRequire2) || (chosenRequire3 == chosenRequire1) || (chosenRequire3 < 1) || (chosenRequire3 > 8)) {
        cout << "Please enter a requirement that you haven't already chosen and is between 1 and 8." << endl;
        cout << ">>";
        cin >> chosenRequire3;
    }
    return chosenRequire3;
}
// Checks if any int stats are negative
int Player::checkNegativeInt(int &stat) {
    while (stat < 0) {
        cout << "Please enter a positive number." << endl;
        cout << ">>";
        cin >> stat;
    }
    return stat;
}
// Checks if any double stats are negative
double Player::checkNegativeDouble(double &stat) {
    while (stat < 0) {
        cout << "Please enter a positive number." << endl;
        cout << ">>";
        cin >> stat;
    }
    return stat;
}
// Checks if the user inputs a different character for yes or no (Y or N) questions
char Player::checkYorN(char &answer) {
    while (answer != 'Y' && answer != 'N') {
        cout << "Please enter Y or N." << endl;
        cout << ">>";
        cin >> answer;
    }
    return answer;
}
// Checks if the user inputs an invalid position
string Player::checkPosition(string &pos) {
    while (pos != "P" && pos != "C" && pos != "IN" && pos != "OF") {
        cout << "Please enter P, C, IN, or OF." << endl;
        cout << ">>";
        cin >> pos;
    }
    return pos;
}

// FUNCTIONS THAT ADD PLAYER MATCHES TO A VECTOR BASED ON REQUIREMENTS
void Player::addAgeMatch(vector<Player> &playerVec, vector<Player> &matches, const int minAge, const int maxAge){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getAge() >= minAge && playerVec.at(i).getAge() <= maxAge){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addBAMatch(vector<Player> &playerVec, vector<Player> &matches, const double minBA){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getBattingAverage() >= minBA){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addHRMatch(vector<Player> &playerVec, vector<Player> &matches, const int homeRuns){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getHomeRuns() >= homeRuns){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addFPMatch(vector<Player> &playerVec, vector<Player> &matches, const int minFP){
    double percent;
    for ( int i = 0; i < playerVec.size(); i++){
        percent = playerVec.at(i).getSuccessfulFielding() / (double) playerVec.at(i).getFieldingOpportunities();
        if (percent >= minFP){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addRMatch(vector<Player> &playerVec, vector<Player> &matches){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getRorL() == 'R'){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addSlapMatch(vector<Player> &playerVec, vector<Player> &matches, const char slapx){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getSwingOrSlap() == "slap" && slapx == 'Y' ){
            matches.push_back(playerVec.at(i));
        }
        if (playerVec.at(i).getSwingOrSlap() != "slap" && slapx == 'N' ){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addHFMatch(vector<Player> &playerVec, vector<Player> &matches, const double timeHF){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getHomeToFirst() <= timeHF){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addSBMatch(vector<Player> &playerVec, vector<Player> &matches, const int stolenBases){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getStolenBases() >= stolenBases){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addPositionMatch(vector<Player> &playerVec, vector<Player> &matches, const string pos){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getMainPosition() == pos){
            matches.push_back(playerVec.at(i));
        }
        if (playerVec.at(i).getSecondaryPosition() == pos){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addPopMatch(vector<Player> &playerVec, vector<Player> &matches, const double pop){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getPopTime() <= pop && playerVec.at(i).getPopTime() != 0){
            matches.push_back(playerVec.at(i));
        }
    }
}
void Player::addERAMatch(vector<Player> &playerVec, vector<Player> &matches, const double era){
    for ( int i = 0; i < playerVec.size(); i++){
        if (playerVec.at(i).getERA() <= era && playerVec.at(i).getERA() != -1){
            matches.push_back(playerVec.at(i));
        }
    }
}

// FILTERS MATCHES IF MORE THAN ONE REQUIREMENT IS SELECTED
vector<Player> Player::realMatches(vector<Player> &matches,vector<Player> &matches2 ){
    vector<Player> realMatches;
    if (matches.size() < matches2.size()){
        for (int i = 0; i <matches.size(); i++){
            for (int j =0; j < matches2.size(); j++){
                if (matches.at(i).getFirstName() == matches2.at(j).getFirstName() && matches.at(i).getLastName() == matches2.at(j).getLastName()){
                    realMatches.push_back(matches.at(i));
                }
            }
        }

    }
    if (matches2.size() < matches.size()){
        for (int i = 0; i <matches2.size(); i++){
            for (int j =0; j < matches.size(); j++){
                if (matches2.at(i).getFirstName() == matches.at(j).getFirstName() && matches2.at(i).getLastName() == matches.at(j).getLastName()){
                    realMatches.push_back(matches2.at(i));
                }
            }
        }

    }
    return realMatches;
}
void Player::func1(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    int maxAge, minAge;
    cout << "What age range of players are you looking for? (Enter a min and max age)" << endl;
    cout << "MIN AGE>> ";
    cin >> minAge;
    minAge = player.checkNegativeInt(minAge);
    cout << "MAX AGE>> ";
    cin >> maxAge;
    maxAge = player.checkNegativeInt(maxAge);
    cout << endl;
    player1.addAgeMatch(playerVec, matches, minAge, maxAge);
}
void Player::func2(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    double minBA;
    cout << "What's the minimum batting average you are looking for?" << endl;
    cout << "MIN AVG>> ";
    cin >> minBA;
    minBA = player.checkNegativeDouble(minBA);
    cout << endl;
    player1.addBAMatch(playerVec, matches, minBA);
}
void Player::func3(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    double minFP;
    cout << "What's the minimum fielding percentage you are looking for?" << endl;
    cout << "MIN PERCENTAGE>> ";
    cin >> minFP;
    minFP = player.checkNegativeDouble(minFP);
    cout << endl;
    player1.addFPMatch(playerVec, matches, minFP);
}
void Player::func4(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    int homeRuns;
    cout << "What's the minimum number of home runs you want your player to have?" << endl;
    cout << "MIN HOME RUNS>> ";
    cin >> homeRuns;
    homeRuns = player.checkNegativeInt(homeRuns);
    cout << endl;
    player1.addHRMatch(playerVec, matches, homeRuns);
}
void Player::func5(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    char rightLeft, slapx;
    cout << "Enter 'R' if you want a right handed batter and 'L' if you want a left handed batter: " << endl;
    cout << ">>";
    cin >> rightLeft;
    cout << endl;
    if (rightLeft == 'R') {
        player1.addRMatch(playerVec, matches);
    }
    if (rightLeft == 'L') {
        cout << "Do you want a slapper? (Enter 'Y' or 'N')" << endl;
        cout << ">> ";
        cin >> slapx;
        slapx = player.checkYorN(slapx);
        player1.addSlapMatch(playerVec, matches, slapx);
    }
}
void Player::func6(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    double timeHF;
    cout << "What's the maximum home to first time you want your player to have?" << endl;
    cout << "MAX HOME TO FIRST>> ";
    cin >> timeHF;
    timeHF = player.checkNegativeDouble(timeHF);
    cout << endl;
    player1.addHFMatch(playerVec, matches, timeHF);
}
void Player::func7(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    int stolenBases;
    cout << "What's the minimum number of stolen bases you want your player to have?" << endl;
    cout << "MIN STOLEN BASES>> ";
    cin >> stolenBases;
    stolenBases = player.checkNegativeInt(stolenBases);
    cout << endl;
    player1.addSBMatch(playerVec, matches, stolenBases);
}
void Player::func8(vector<Player> &playerVec, vector<Player> &matches){
    Player player, player1;
    double pop, era;
    char popYorN, eraYorN;
    string pos;
    cout << "What position would you like the player to play? (Enter 'P', 'C', 'IN', or 'OF')" << endl;
    cout << "POSITION>> ";
    cin >> pos;
    pos = player.checkPosition(pos);
    cout << endl;
    if (pos == "C") {
        cout << "Would you also like to filter by pop time? (Enter 'Y' or 'N')" << endl;
        cout << ">> ";
        cin >> popYorN;
        popYorN = player.checkYorN(popYorN);
        if (popYorN == 'Y') {
            cout << "What's the maximum pop time you want the catcher to have?" << endl;
            cout << "MAX POP TIME>> ";
            cin >> pop;
            pop = player.checkNegativeDouble(pop);
            cout << endl;
            player1.addPopMatch(playerVec, matches, pop);
        } else {
            player1.addPositionMatch(playerVec, matches, pos);
        }
    } else if (pos == "P") {
        cout << "Would you also like to filter by ERA? (Enter 'Y' or 'N')" << endl;
        cout << ">> ";
        cin >> eraYorN;
        eraYorN = player.checkYorN(eraYorN);
        if (eraYorN == 'Y') {
            cout << "What's the maximum ERA you want the pitcher to have?" << endl;
            cout << "MAX ERA>> ";
            cin >> era;
            era = player.checkNegativeDouble(era);
            cout << endl;
            player1.addERAMatch(playerVec, matches, era);
        } else {
            player1.addPositionMatch(playerVec, matches, pos);
        }
    } else {
        player1.addPositionMatch(playerVec, matches, pos);
    }
}
void Player::printRequirementList() const {
    cout << "Here is the list of requirements to choose from: " << endl;
    cout << "1) AGE" << endl;
    cout << "2) BATTING AVERAGE" << endl;
    cout << "3) FIELDING PERCENTAGE" << endl;
    cout << "4) HOME RUNS" << endl;
    cout << "5) RIGHT OR LEFT HANDED BATTER" << endl;
    cout << "6) HOME TO FIRST TIME" << endl;
    cout << "7) STOLEN BASES" << endl;
    cout << "8) POSITION" << endl;
    cout << endl;
}
void Player::outputFile(vector<Player> &finalMatches, ofstream &myFile){
    for (int i=0; i < finalMatches.size(); i++ ){
        myFile << finalMatches.at(i).getFirstName() << " " << finalMatches.at(i).getLastName() << " (Age: " << finalMatches.at(i).getAge() << ")" << endl;
        myFile << "\n";
        myFile << "DEFENSIVE DETAILS AND STATS:" << endl;
        myFile << "Primary Position: " << finalMatches.at(i).getMainPosition() << endl;
        myFile << "Secondary Position: " << finalMatches.at(i).getSecondaryPosition() << endl;
        myFile << "Fielding Percentage: " << ((double)finalMatches.at(i).getSuccessfulFielding()/finalMatches.at(i).getFieldingOpportunities()) << endl;
        if (finalMatches.at(i).getMainPosition() == "C" ||finalMatches.at(i).getSecondaryPosition() == "C"){
            myFile << "Pop Time: " << finalMatches.at(i).getPopTime() << endl;
        }
        if (finalMatches.at(i).getMainPosition() == "P" ||finalMatches.at(i).getSecondaryPosition() == "P"){
            myFile << "ERA: " << finalMatches.at(i).getERA() << endl;
        }
        myFile << "OFFENSIVE DETAILS AND STATS:" << endl;
        myFile << "Bats: " << finalMatches.at(i).getRorL() << " (" << finalMatches.at(i).getSwingOrSlap() << ")" << endl;
        myFile << "Batting Average: " << finalMatches.at(i).getBattingAverage() << endl;
        myFile << "Home Runs: " << finalMatches.at(i).getHomeRuns() << endl;
        myFile << "Stolen Bases: " << finalMatches.at(i).getStolenBases() << endl;
        myFile << "Home to First: " << finalMatches.at(i).getHomeToFirst() << endl;
        myFile << "\n";
        myFile << "----------------------------------";
        myFile << "\n";
    }
}

