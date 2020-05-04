/*
 * CSCI 261: Final Project - Recruiting Profile Generator
 * Authors: Lauren Decker (Section C) and Renata Boyd (Section E)
 *
 */
using namespace std;
#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H
#include <string>
#include <vector>

class Player {
public:
    // GETTERS AND SETTERS
    const string getFirstName();
    void setFirstName(const string newName);
    const string getLastName();
    void setLastName(const string newName);
    const int getAge();
    void setAge(const int newAge);
    const double getBattingAverage();
    void setBattingAverage(const double newBA);
    const int getHomeRuns();
    void setHomeRuns(const int newHR);
    const char getRorL();
    void setRorL(const char newRorL);
    const string getSwingOrSlap();
    void setSwingOrSlap(const string newSorS);
    const string getMainPosition();
    void setMainPosition(const string newMain);
    const string getSecondaryPosition();
    void setSecondaryPosition(const string newSecondary);
    const int getFieldingOpportunities();
    void setFieldingOpportunities(const int newFOpps);
    const int getSuccessfulFielding();
    void setSuccessfulFielding(const int newNoError);
    const double getPopTime();
    void setPopTime(const double newPop);
    const double getERA();
    void setERA(const double newERA);
    const double getHomeToFirst();
    void setHomeToFirst(const double newHtoF);
    const int getStolenBases();
    void setStolenBases(const int newSB);

    // READS IN DATA FROM INPUT FILE
    vector<Player> readInFile(ifstream &dataFile);
    // FUNCTIONS THAT OBTAIN USER INPUT
    int numRequirements();
    // FUNCTIONS THAT CHECK IF USER INPUT IS VALID
    int checkNumRequirements(int numRequire);
    int checkChosenRequirements(int chosenRequire);
    int checkChosenRequirementsTwo(const int chosenRequire1, int chosenRequire2);
    int checkChosenRequirementsThree(const int chosenRequire1, const int chosenRequire2, int chosenRequire3);
    int checkNegativeInt(int &stat);
    double checkNegativeDouble(double &stat);
    char checkYorN(char &answer);
    string checkPosition(string &pos);
    // FUNCTIONS THAT ADD PLAYER MATCHES TO A VECTOR BASED ON REQUIREMENTS
    void addAgeMatch(vector<Player> &playerVec, vector<Player> &matches, const int minAge, const int maxAge);
    void addBAMatch(vector<Player> &playerVec, vector<Player> &matches, const double minBA);
    void addHRMatch(vector<Player> &playerVec, vector<Player> &matches, const int homeRuns);
    void addFPMatch(vector<Player> &playerVec, vector<Player> &matches, const int minFP);
    void addRMatch(vector<Player> &playerVec, vector<Player> &matches);
    void addSlapMatch(vector<Player> &playerVec, vector<Player> &matches, const char slap);
    void addHFMatch(vector<Player> &playerVec, vector<Player> &matches, const double timeHF);
    void addSBMatch(vector<Player> &playerVec, vector<Player> &matches, const int stolenBases);
    void addPositionMatch(vector<Player> &playerVec, vector<Player> &matches, const string pos);
    void addPopMatch(vector<Player> &playerVec, vector<Player> &matches, const double pop);
    void addERAMatch(vector<Player> &playerVec, vector<Player> &matches, const double era);
    // FILTERS MATCHES WHEN MORE THAN ONE REQUIREMENT IS SELECTED
    vector<Player> realMatches(vector<Player> &matches, vector<Player> &matches2);
    //FUNCTIONS THAT GET REQUIREMENT INPUT
    void func1(vector<Player> &playerVec, vector<Player> &matches);
    void func2(vector<Player> &playerVec, vector<Player> &matches);
    void func3(vector<Player> &playerVec, vector<Player> &matches);
    void func4(vector<Player> &playerVec, vector<Player> &matches);
    void func5(vector<Player> &playerVec, vector<Player> &matches);
    void func6(vector<Player> &playerVec, vector<Player> &matches);
    void func7(vector<Player> &playerVec, vector<Player> &matches);
    void func8(vector<Player> &playerVec, vector<Player> &matches);
    //PRINTING FUNCTION
    void printRequirementList() const ;
    //OUTPUT FUNCTION
    void outputFile(vector<Player> &finalMatches, ofstream &myFile);
private:
    string _firstName;
    string _lastName;
    char _RorL;
    string _swingOrSlap;
    string _mainPosition;
    string _secondaryPosition;
    int _age;

    int _fieldingOpportunites;
    int _successfulFielding;
    double _battingAVG;
    double _popTime;
    double _ERA;
    double _homeToFirst;
    int _stolenBases;
    int _homeRuns;
};

#endif