#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

/*
 ============================================================================
  oct26 / p4.cpp
  PRACTICE PROBLEMS: std::vector Operations & Gradebook OOP Architecture
  Inspired by your exploration in p3.cpp!
 ============================================================================
  Instructions:
  - Each problem focuses on practical std::vector skills and class modeling.
  - Implement your logic where marked with // TODO.
  - Test each function by running `main()` (you can compile with:
    g++ -std=c++17 p4.cpp -o p4 && ./p4
 ============================================================================
*/

// ============================================================================
// PROBLEM 1: Vector Statistics (Average, Min, Max)
// ============================================================================
/*
  Goal:
  1. Implement `calculateAverage`: returns the arithmetic mean of all elements.
     (Hint: you can use a loop or std::accumulate from <numeric>).
  2. Implement `getHighestScore`: returns the maximum score.
     (Hint: std::max_element from <algorithm> or a manual loop).
  3. Implement `getLowestScore`: returns the minimum score.
*/

double calculateAverage(const std::vector<double> &scores) {
  if (scores.empty())
    return 0.0;
  // TODO: Calculate and return the average of scores
  double total{0};
  for (int i = 0; i < scores.size(); i++) {
    total += scores.at(i);
  }
  return total / scores.size();
}

double getHighestScore(const std::vector<double> &scores) {
  if (scores.empty())
    return 0.0;
  // std::max_element returns an iterator, dereference with * to get the double value
  return *std::max_element(scores.begin(), scores.end());
}

double getLowestScore(const std::vector<double> &scores) {
  if (scores.empty())
    return 0.0;
  // std::min_element returns an iterator, dereference with * to get the double value
  return *std::min_element(scores.begin(), scores.end());
}

void problem1() {
  std::cout << "\n=================== PROBLEM 1: Vector Statistics "
               "==================="
            << std::endl;
  std::vector<double> scores = {78.5, 92.0, 45.5, 88.0, 61.5, 39.0, 95.5};

  std::cout << "Scores count: " << scores.size() << std::endl;
  std::cout << "Average: " << calculateAverage(scores) << " (Expected: ~71.43)"
            << std::endl;
  std::cout << "Highest: " << getHighestScore(scores) << " (Expected: 95.5)"
            << std::endl;
  std::cout << "Lowest:  " << getLowestScore(scores) << " (Expected: 39.0)"
            << std::endl;
}

// ============================================================================
// PROBLEM 2: Filtering & Counting (Pass vs. Fail)
// ============================================================================
/*
  Goal:
  1. Implement `countPassed`: returns how many scores are >= threshold
  (default 50.0).
  2. Implement `countFailed`: returns how many scores are < threshold.
  3. Implement `getFailingScores`: returns a new std::vector<double> containing
     only the failing scores (< threshold).
*/

int countPassed(const std::vector<double> &scores, double threshold = 50.0) {
  // TODO: Count and return how many scores are >= threshold
  int cP{0};
  for (int i = 0; i < scores.size(); ++i) {
    if (scores.at(i) >= threshold) {
      cP++;
    }
  }
  return cP;
}

int countFailed(const std::vector<double> &scores, double threshold = 50.0) {
  // TODO: Count and return how many scores are < threshold
  int cF{0};
  for (int i = 0; i < scores.size(); ++i) {
    if (scores.at(i) < threshold) {
      cF++;
    }
  }
  return cF;
}

std::vector<double> getFailingScores(const std::vector<double> &scores,
                                     double threshold = 50.0) {
  std::vector<double> failing;
  // TODO: Push each score < threshold into `failing` and return it
  for (int i = 0; i < scores.size(); i++) {
    if (scores.at(i) < threshold) {
      failing.push_back(scores.at(i));
    }
  }
  return failing;
}

void problem2() {
  std::cout << "\n=================== PROBLEM 2: Filtering & Counting "
               "==================="
            << std::endl;
  std::vector<double> scores = {45.0, 82.5, 33.0, 91.0, 49.5, 76.0, 50.0};

  std::cout << "Passed count: " << countPassed(scores, 50.0) << " (Expected: 4)"
            << std::endl;
  std::cout << "Failed count: " << countFailed(scores, 50.0) << " (Expected: 3)"
            << std::endl;

  std::vector<double> failing = getFailingScores(scores, 50.0);
  std::cout << "Failing scores list: ";
  for (double s : failing) {
    std::cout << s << " ";
  }
  std::cout << "\n(Expected: 45 33 49.5)" << std::endl;
}

// ============================================================================
// PROBLEM 3: Parallel Vectors & Index Matching
// ============================================================================
/*
  Goal:
  In p3.cpp you had a list of student names and their grades.
  Here you have two vectors of the same size:
    names[i] corresponds to scores[i].

  1. Implement `findTopStudent`:
     - Finds the index of the highest score.
     - Returns the name of the student who achieved that highest score.
  2. Implement `printClassRoster`:
     - Prints each student in the format:
       "[Index] [Name]: [Score] - [PASS/FAIL]"
*/

std::string findTopStudent(const std::vector<std::string> &names,
                           const std::vector<double> &scores) {
  if (names.empty() || names.size() != scores.size())
    return "Unknown";
  // Dereference iterator from std::max_element
  double highestscore = *std::max_element(scores.begin(), scores.end());
  for (int i = 0; i < names.size(); ++i) {
    if (highestscore == scores.at(i)) {
      return names.at(i);
    }
  }
  return "Unknown";
}

void printClassRoster(const std::vector<std::string> &names,
                      const std::vector<double> &scores) {
  std::cout << "\n--- Class Roster ---" << std::endl;
  for (int i = 0; i < names.size(); i++) {
    std::string status = (scores.at(i) >= 50.0) ? "[PASS]" : "[FAIL]";
    std::cout << i + 1 << ". " << names.at(i) << ": " << scores.at(i) << " " << status << std::endl;
  }
}

  void problem3() {
    std::cout << "\n=================== PROBLEM 3: Parallel Vectors "
                 "==================="
              << std::endl;
    std::vector<std::string> names = {"Ethan Parker", "Olivia Mitchell",
                                      "Mason Brooks", "Sophia Anderson",
                                      "Liam Carter"};
    std::vector<double> scores = {84.5, 96.0, 48.0, 72.5, 91.0};

    std::string topStudent = findTopStudent(names, scores);
    std::cout << "Top Student: " << topStudent << " (Expected: Olivia Mitchell)"
              << std::endl;

    printClassRoster(names, scores);
  }

  // ============================================================================
  // PROBLEM 4: OOP Student Gradebook Class (Refactoring p3.cpp)
  // ============================================================================
  /*
    Goal:
    Instead of fragile parallel vectors, model real data using an OOP approach:
    1. A `Student` struct representing one student (name and score).
    2. A `Gradebook` class encapsulating a `std::vector<Student>` and providing
       safe, clean member methods.
  */

  struct Student {
    std::string name;
    double score;
  };

  class Gradebook {
  private:
    std::vector<Student> roster;

  public:
    // Add a student to the gradebook
    void addStudent(const std::string &name, double score) {
      // TODO: Push a new Student into `roster`
        roster.push_back({name,score});
    }

    // Return total students registered
    std::size_t size() const {
      // TODO: Return roster size
      return roster.size();
    }

    // Return average score across all students
    double calculateAverage() const {
      if (roster.empty())
        return 0.0;
      // TODO: Sum up all scores in roster and return the average
      double sum= 0.0;
      for(const Student& s : roster) {
        sum+= s.score;
      }
      return sum/roster.size();
    }

    // Return the Student with the highest score
    Student getTopStudent() const {
      if (roster.empty())
        return {"Nobody", 0.0};
      // TODO: Find and return the student with the maximum score
      int top = 0;
      for(int i = 0 ; i < roster.size() ; i++) {
        if(roster.at(i).score > roster.at(top).score) {
            top = i;
        }
      }
        return roster.at(top);
    }
    // Return count of students who passed (>= passThreshold)
    int countPassed(double passThreshold = 50.0) const {
      // TODO: Count and return how many students passed
      int count = 0;
      for (int i = 0 ; i < roster.size() ; i++) {
        if(roster.at(i).score>= passThreshold) {
            count++;
        }
      }
        return count;
    }

    // Display formatted summary card
    void displaySummary() const {
      std::cout << "\n================ GRADEBOOK SUMMARY ================"
                << std::endl;
      std::cout << "Total Students : " << size() << std::endl;
      std::cout << "Average Score  : " << std::fixed << std::setprecision(2)
                << calculateAverage() << std::endl;
      Student top = getTopStudent();
      std::cout << "Top Performer  : " << top.name << " (" << top.score << ")"
                << std::endl;
      std::cout << "Passed Students: " << countPassed(50.0) << std::endl;
      std::cout << "Failed Students: " << size() - countPassed(50.0)
                << std::endl;
      std::cout << "==================================================="
                << std::endl;
    }
  };

  void problem4() {
    std::cout
        << "\n=================== PROBLEM 4: OOP Gradebook ==================="
        << std::endl;
    Gradebook gb;
    gb.addStudent("Ethan Parker", 84.5);
    gb.addStudent("Olivia Mitchell", 96.0);
    gb.addStudent("Mason Brooks", 48.0);
    gb.addStudent("Sophia Anderson", 72.5);
    gb.addStudent("Liam Carter", 91.0);
    gb.addStudent("Aisha Rahman", 42.0);

    gb.displaySummary();
  }

  // ============================================================================
  // PROBLEM 5: Sorting & Ranking Students
  // ============================================================================
  /*
    Goal:
    Using std::sort from <algorithm>, rank students from highest score to
    lowest.

    Hint:
    std::sort(vec.begin(), vec.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // Descending order
    });
  */

  void displayRankedLeaderboard(std::vector<Student> students) {
    // TODO: Sort `students` by score descending (highest to lowest)
    // TODO: Print the ranked leaderboard (Rank #1, Rank #2, etc.)
  }

  void problem5() {
    std::cout << "\n=================== PROBLEM 5: Leaderboard Ranking "
                 "==================="
              << std::endl;
    std::vector<Student> students = {{"Ethan Parker", 84.5},
                                     {"Olivia Mitchell", 96.0},
                                     {"Mason Brooks", 48.0},
                                     {"Sophia Anderson", 72.5},
                                     {"Liam Carter", 91.0}};

    displayRankedLeaderboard(students);
  }

  // ============================================================================
  // MAIN ENTRY POINT
  // ============================================================================
  int main() {
    std::cout << "================================================="
              << std::endl;
    std::cout << "  oct26/p4.cpp: Vector & Gradebook Masterclass   "
              << std::endl;
    std::cout << "================================================="
              << std::endl;

    problem1();
    problem2();
    problem3();
    problem4();
    problem5();

    return 0;
  }
