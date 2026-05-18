#include <iostream>
#include <string>
using namespace std;

// Function to calculate total score
float calculateScore(float attendance,
                     float productivity,
                     float teamwork,
                     float punctuality,
                     float communication,
                     float innovation) {

    return (attendance / 10.0) +
           productivity +
           teamwork +
           punctuality +
           communication +
           innovation;
}

// Function to determine performance
string getPerformance(float totalScore) {

    if (totalScore >= 50)
        return "EXCELLENT";

    else if (totalScore >= 40)
        return "GOOD";

    else if (totalScore >= 30)
        return "AVERAGE";

    else
        return "POOR";
}

// Function to determine risk level
string getRisk(string performance) {

    if (performance == "EXCELLENT" || performance == "GOOD")
        return "LOW";

    else if (performance == "AVERAGE")
        return "MEDIUM";

    else
        return "HIGH";
}

// Function to give recommendation
string getRecommendation(string performance) {

    if (performance == "EXCELLENT")
        return "Eligible for promotion, leadership role, and bonus";

    else if (performance == "GOOD")
        return "Consistent employee with growth potential";

    else if (performance == "AVERAGE")
        return "Needs training and performance monitoring";

    else
        return "Immediate improvement plan required";
}

// Function for expert alerts
void showAlerts(float attendance,
                float productivity,
                float teamwork,
                float communication,
                float innovation) {

    if (attendance < 60) {
        cout << "\n[ALERT] Low attendance detected.";
    }

    if (productivity < 5) {
        cout << "\n[ALERT] Productivity improvement required.";
    }

    if (teamwork < 5) {
        cout << "\n[ALERT] Employee struggles in team collaboration.";
    }

    if (communication < 5) {
        cout << "\n[ALERT] Communication training recommended.";
    }

    if (innovation >= 9) {
        cout << "\n[SPECIAL NOTE] Highly innovative employee.";
    }
}

// Function to display report
void displayReport(float attendance,
                   float productivity,
                   float teamwork,
                   float punctuality,
                   float communication,
                   float innovation,
                   float totalScore,
                   string performance,
                   string risk,
                   string recommendation) {

    cout << "\n\n========== PERFORMANCE REPORT ==========\n";

    cout << "Attendance     : " << attendance << "%" << endl;
    cout << "Productivity   : " << productivity << "/10" << endl;
    cout << "Teamwork       : " << teamwork << "/10" << endl;
    cout << "Punctuality    : " << punctuality << "/10" << endl;
    cout << "Communication  : " << communication << "/10" << endl;
    cout << "Innovation     : " << innovation << "/10" << endl;

    cout << "\nTotal Score    : " << totalScore << "/60" << endl;

    cout << "Performance    : " << performance << endl;
    cout << "Risk Level     : " << risk << endl;

    cout << "Recommendation : " << recommendation << endl;
}

int main() {

    while (true) {

        float attendance, productivity, teamwork;
        float punctuality, communication, innovation;

        cout << "\n========== EMPLOYEE PERFORMANCE EXPERT SYSTEM ==========\n";

        // Input
        cout << "Attendance Percentage (0-100): ";
        cin >> attendance;

        cout << "Productivity Score (0-10): ";
        cin >> productivity;

        cout << "Teamwork Score (0-10): ";
        cin >> teamwork;

        cout << "Punctuality Score (0-10): ";
        cin >> punctuality;

        cout << "Communication Skill Score (0-10): ";
        cin >> communication;

        cout << "Innovation Score (0-10): ";
        cin >> innovation;

        // Processing
        float totalScore = calculateScore(attendance,
                                          productivity,
                                          teamwork,
                                          punctuality,
                                          communication,
                                          innovation);

        string performance = getPerformance(totalScore);

        string risk = getRisk(performance);
        string recommendation = getRecommendation(performance);

        // Alerts
        showAlerts(attendance,
                   productivity,
                   teamwork,
                   communication,
                   innovation);

        // Output Report
        displayReport(attendance,
                      productivity,
                      teamwork,
                      punctuality,
                      communication,
                      innovation,
                      totalScore,
                      performance,
                      risk,
                      recommendation);

        // Continue option
        char again;

        cout << "\nEvaluate another employee? (y/n): ";
        cin >> again;

        again = tolower(again);

        if (again != 'y') {

            cout << "\nExpert System Closed.\n";
            break;
        }
    }

    return 0;
}