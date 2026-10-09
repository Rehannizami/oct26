# include <iostream>
# include <string>
# include <vector>
# include <random>
# include <stdexcept>
# include <algorithm>
struct data {
    std:: vector <std::string> identifier;
    std:: vector <double> scores;
};
class database {
    protected:
        data& students;
        data& grades;
        database(data& s,data& g): students(s), grades(g) {
            students.identifier.insert(students.identifier.end(),{"Ethan Parker", "Olivia Mitchell",
            "Mason Brooks", "Sophia Anderson","Liam Carter", "Emma Collins", "Noah Thompson",
            "Ava Richardson","Lucas Bennett","Madison Reed","Alexander Hayes","Emily Foster",
            "Jackson Murphy", "Mia Rodriguez", "Benjamin Ward","Chloe Bennett","Daniel Foster",
            "Aisha Rahman","Tyler Morgan","Isabella Rivera","Jacob Sullivan","Maya Patel",
        "Nathan Cooper","Zoe Williams","Ryan Mitchell","Grace Kim","Caleb Turner","Hannah Brooks",
            "Dylan Scott","Natalie Chen"});
        
    grades.scores.resize(students.identifier.size());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(40.0,98.0);
    for (std::size_t i=0 ; i < grades.scores.size() ; ++i) {
        grades.scores.at(i) = dist(gen);
        }
    }
};

class result : protected database {
    public:
        int pass{0},fail{0};
        result() {
        for (int i = 0 ; i < grades.scores.size() ; ++i) {
            if(grades.scores.at(i) >= 50 ) {
                pass++; } 
            else if(grades.scores.at(i) < 50 ) {
                fail++; } 
            else { 
                throw std:: runtime_error("ERROR mt19937 gen(rd())"); }
             }
        }
};

class average : protected database {
    public:
        double avg (data& g) : grades(g) {
    return std::accumulate(grades.score.begin(), grades.score.end(), 0.0) / grades.score.size();
        }
};

int main () {
    database callINPUT;
    result r;
    average a;
    std:: cout << "--- Class Summery ---" << std::endl;
    std:: cout << "Total Students" << callINPUT.students.identifer.size() << std::endl;
    std:: cout << "Average Score" << a.avg() << std::endl;
    std:: cout << "Highest Score" << std::max_element(callINPUT.grades.score.begin(), callINPUT.grades.score.end()) << std::endl;
     std:: cout << "Lowest Score" << std::min_element(callINPUT.grades.score.begin(), callINPUT.grades.score.end()) << std::endl;
    std:: cout << "Passed: " << r.pass << std::endl;
    std:: cout << "Failed " << r.fail << std::endl;
}
