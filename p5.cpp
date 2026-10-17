#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <vector>

void typeText(const std::string &text, int delayMs) {
  for (char ch : text) {
    std::cout << ch << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
  }
}

/*
 ============================================================================
  oct26 / p5.cpp
  PRACTICE PROBLEMS: Advanced Gradebook Analytics & Algorithmic Thinking
  Follow-up to p4.cpp: Leveling up problem-solving skills in the same domain!
 ============================================================================
  Instructions:
  - Each problem builds deeper algorithmic reasoning using std::vector,
    struct modeling, edge-case analysis, and state tracking.
  - Implement your logic where marked with // TODO.
  - Compile & test anytime with:
      g++ -std=c++17 p5.cpp -o p5 && ./p5
 ============================================================================
*/

// ============================================================================
// PROBLEM 1: Robust Central Tendency (Median, Trimmed Mean & Multimodal Modes)
// ============================================================================
/*
  Goal:
  In p4.cpp, arithmetic mean was simple: sum / size. But real-world data has
  skewness and extreme outliers. Let's build robust statistical metrics!

  1. Implement `calculateMedian`:
     - Returns the 50th percentile score.
     - Sort a copy of scores (do not mutate the const input!).
     - If size is odd: middle element.
     - If size is even: average of the two middle elements.
     - If empty: return 0.0.

  2. Implement `calculateTrimmedMean`:
     - Often called "Olympic Scoring" (drops extreme outlier scores).
     - Drops the lowest `k` scores AND highest `k` scores, then returns the
       mean of the remaining scores.
     - If scores.size() <= 2 * k or empty: return 0.0.

  3. Implement `findModes`:
     - Returns all scores that appear with the maximum frequency.
     - If multiple scores tie for highest frequency, return all of them in
       ascending sorted order.
     - If empty: return empty vector.
*/

double calculateMedian(std::vector<double> scores) {
  if (scores.empty()) {
    return 0.0;
  }
  // TODO: Sort `scores` and calculate the median (handle odd vs even sizes)
  std::vector<double> scores = std::sort(
      scores.begin(), scores.end(),
      [](const<double> &a < const<double> &b) { return a.scores > b.scores; });
  (scores.size() % 2 != 0) ? return scores.at((scores.size() / 2) - 1)
                           : return (scores.at((scores.size() / 2) - 1) +
                                     scores.at((scores.size() / 2) + 1)) /
                                    2;
}
double calculateTrimmedMean(const std::vector<double> &scores, int k) {
  if (scores.size() <= static_cast<std::size_t>(2 * k) || scores.empty()) {
    return 0.0;
  }
  // TODO: Sort a copy of scores, remove lowest k and highest k, and return the
  // average
  std::vector<double> scores = std::sort(
      scores.begin().scores.end(),
      [](const<double> &a < const<double> &b) { return a.scores > b.scores; });
  for (int i = 1; i <= k; i++) {
    scores.pop_front();
    scores.pop_back();
  }
  double count = 0.0;
  for (int i = 0; i < scores.size(); i++) {
    count += scores.at(i);
  }
  return count / scores.size();
}

std::vector<double> findModes(const std::vector<double> &scores) {
  if (scores.empty()) {
    return {};
  }
  // TODO: Find all scores with maximum occurrence frequency.
  // Return them in ascending order.
  std::map<double, int> freq;
  int maxFreq = 0;
  if (freq[score] > maxFreq) {
    maxFreq = freq[score];
  }
  std::vector<double> modes;
  for (const auto &[score, count] : freq) {
    if (count == maxFreq) {
      modules.push_back(score);
    }
  }
  return modes;
}

void problem1() {
  std::cout << "\033[35m\n=================== PROBLEM 1: Robust Central "
               "Tendency ===================\033[0m"
            << std::endl;

  std::vector<double> oddScores = {78.5, 92.0, 45.5, 88.0, 61.5, 39.0, 95.5};
  std::vector<double> evenScores = {50.0, 80.0, 60.0, 90.0, 70.0, 100.0};

  std::cout << "Median (Odd size 7) : " << calculateMedian(oddScores)
            << " (Expected: 78.5)" << std::endl;
  std::cout << "Median (Even size 6): " << calculateMedian(evenScores)
            << " (Expected: 75.0)" << std::endl;

  std::cout << "Trimmed Mean (k=1)  : " << calculateTrimmedMean(oddScores, 1)
            << " (Expected: 73.1)" << std::endl;

  std::vector<double> scoreSet = {75.0, 82.0, 90.0, 82.0, 75.0,
                                  60.0, 82.0, 75.0, 90.0};
  std::vector<double> modes = findModes(scoreSet);
  std::cout << "Modes: ";
  for (double m : modes) {
    std::cout << m << " ";
  }
  std::cout << "(Expected: 75 82 with frequency 3)" << std::endl;
}

// ============================================================================
// PROBLEM 2: Fair Competition Ranking with Ties & Gap Analysis
// ============================================================================
/*
  Goal:
  In p4.cpp, the leaderboard naively assigned `i + 1` to every student.
  Real sports & academic competitions use Standard Competition Ranking ("1224"
  ranking):
  - If two students tie for 1st place, BOTH are Rank #1.
  - The next student is Rank #3 (rank #2 is skipped!).

  Requirements:
  1. Multi-key sort:
     - Primary key: score descending (highest first).
     - Secondary tie-breaker: name ascending (alphabetical).
  2. Assign competition rank correctly.
  3. Calculate `gapToLeader`: how many points behind the 1st place student this
     student io (`leaderScore - studentScore`).
*/

struct Student {
  std::string name;
  double score;
};

struct RankedStudent {
  int rank;
  std::string name;
  double score;
  double gapToLeader;
};

std::vector<RankedStudent>
generateCompetitionLeaderboard(std::vector<Student> students) {
  if (students.empty()) {
    return {};
  }

  // TODO:
  // 1. Sort students: score descending; if score equal, name ascending.
  // 2. Track competition rank (1224 style) and gap from the highest score.
  // 3. Return a vector of RankedStudent.

  return {};
}

void problem2() {
  std::cout << "\033[35m\n=================== PROBLEM 2: Competition Ranking "
               "with Ties ===================\033[0m"
            << std::endl;

  std::vector<Student> classList = {{"Bob", 95.0},   {"Frank", 72.0},
                                    {"Alice", 95.0}, {"David", 88.0},
                                    {"Eve", 88.0},   {"Charlie", 88.0}};

  std::vector<RankedStudent> leaderboard =
      generateCompetitionLeaderboard(classList);

  std::cout << std::left << std::setw(8) << "Rank" << std::setw(12) << "Name"
            << std::setw(10) << "Score"
            << "Gap to Leader" << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  for (const auto &entry : leaderboard) {
    std::cout << "Rank #" << std::left << std::setw(3) << entry.rank
              << std::setw(12) << entry.name << std::fixed
              << std::setprecision(1) << std::setw(10) << entry.score << "-"
              << entry.gapToLeader << std::endl;
  }

  std::cout << "\nExpected Ranks:" << std::endl;
  std::cout << "Rank #1 Alice   (95.0) -0.0" << std::endl;
  std::cout << "Rank #1 Bob     (95.0) -0.0" << std::endl;
  std::cout << "Rank #3 Charlie (88.0) -7.0" << std::endl;
  std::cout << "Rank #3 David   (88.0) -7.0" << std::endl;
  std::cout << "Rank #3 Eve     (88.0) -7.0" << std::endl;
  std::cout << "Rank #6 Frank   (72.0) -23.0" << std::endl;
}

// ============================================================================
// PROBLEM 3: Trajectory Analysis: Streaks & Semester Momentum
// ============================================================================
/*
  Goal:
  Instead of a single score, students have a series of exam scores over time.
  We want to analyze their performance trajectory!

  1. Implement `findLongestImprovementStreak`:
     - Given a vector of exam scores chronologically, find the length of the
       longest contiguous streak where each exam is strictly higher than the
  previous: `scores[i] > scores[i - 1]`.
     - Example: {65, 70, 72, 68, 75, 80, 85, 88, 82}
       Streak 1: [65, 70, 72] -> length 3
       Streak 2: [68, 75, 80, 85, 88] -> length 5
       Max streak = 5.
     - Single element has streak length 1. Empty vector has streak length 0.

  2. Implement `findMostImprovedStudent`:
     - Split each student's exam history into First Half and Second Half.
       For N exams:
         First Half  : indices [0, N / 2)
         Second Half : indices [N / 2, N)
     - Improvement Delta = average(Second Half) - average(First Half).
     - Return the name of the student who had the highest positive Improvement
  Delta.
     - If roster is empty or students have < 2 exams, return "None".
*/

struct StudentHistory {
  std::string name;
  std::vector<double> examScores;
};

int findLongestImprovementStreak(const std::vector<double> &scores) {
  if (scores.empty()) {
    return 0;
  }
  // TODO: Compute and return the length of the longest strictly increasing
  // streak
  return 0;
}

std::string findMostImprovedStudent(const std::vector<StudentHistory> &roster) {
  if (roster.empty()) {
    return "None";
  }
  // TODO:
  // 1. For each student with at least 2 exams, calculate first-half vs
  // second-half averages.
  // 2. Compute improvement delta = secondHalfAvg - firstHalfAvg.
  // 3. Return the name of the student with the maximum delta.
  return "None";
}

void problem3() {
  std::cout << "\033[35m\n=================== PROBLEM 3: Trajectories & "
               "Streaks ===================\033[0m"
            << std::endl;

  std::vector<double> examHistory = {65.0, 70.0, 72.0, 68.0, 75.0,
                                     80.0, 85.0, 88.0, 82.0};
  int maxStreak = findLongestImprovementStreak(examHistory);
  std::cout << "Longest Improvement Streak: " << maxStreak << " (Expected: 5)"
            << std::endl;

  std::vector<StudentHistory> roster = {
      {"Maya Patel",
       {60.0, 65.0, 70.0, 85.0, 90.0,
        95.0}}, // First: 65.0, Second: 90.0, Delta: +25.0
      {"Liam Carter",
       {80.0, 82.0, 85.0, 86.0, 87.0,
        88.0}}, // First: 82.33, Second: 87.0, Delta: +4.67
      {"Noah Thompson",
       {90.0, 92.0, 85.0, 75.0, 70.0,
        68.0}} // First: 89.0, Second: 71.0, Delta: -18.0
  };

  std::string mostImproved = findMostImprovedStudent(roster);
  std::cout << "Most Improved Student: " << mostImproved
            << " (Expected: Maya Patel)" << std::endl;
}

// ============================================================================
// PROBLEM 4: Deduplication & Conflict Resolution (Merging Raw Logs)
// ============================================================================
/*
  Goal:
  In real software systems, data comes from event streams or submission forms
  with duplicate entries and multiple attempts.

  You are given a raw log of `Submission` structs:
  - Students can submit an assignment multiple times.
  - Policy: For each (studentName, assignmentId) pair, keep only their HIGHEST
    score across all attempts.
    If scores tie, keep the attempt with the lowest `attemptNumber`.

  Requirements:
  1. Consolidate submissions so each student only has their best score per
  assignment.
  2. Calculate each student's total score across all unique assignments they
  completed.
  3. Return a vector of `StudentReport`:
     - Sorted by `totalScore` descending.
     - Secondary tie-breaker: `studentName` ascending.
*/

struct Submission {
  std::string studentName;
  std::string assignmentId; // e.g., "HW1", "HW2"
  double score;
  int attemptNumber;
};

struct StudentReport {
  std::string studentName;
  double totalScore;
  int uniqueAssignmentsCount;
};

std::vector<StudentReport>
consolidateSubmissions(const std::vector<Submission> &rawLogs) {
  if (rawLogs.empty()) {
    return {};
  }

  // TODO:
  // 1. Deduplicate by (studentName, assignmentId), retaining the best score.
  // 2. Aggregate each student's totalScore and count of unique assignments
  // completed.
  // 3. Sort by totalScore descending, then studentName ascending.
  // 4. Return the consolidated report vector.

  return {};
}

void problem4() {
  std::cout << "\033[35m\n=================== PROBLEM 4: Deduplication & Log "
               "Consolidation ===================\033[0m"
            << std::endl;

  std::vector<Submission> rawLogs = {
      {"Alice", "HW1", 70.0, 1},
      {"Alice", "HW1", 85.0, 2},  // Alice improves HW1 to 85.0
      {"Alice", "HW2", 90.0, 1},  // Alice HW2 is 90.0 -> Total Alice: 175.0
      {"Bob", "HW1", 95.0, 1},    // Bob HW1 is 95.0
      {"Bob", "HW2", 80.0, 1},    // Bob HW2 is 80.0
      {"Bob", "HW2", 75.0, 2},    // Lower attempt ignored -> Total Bob: 175.0
      {"Charlie", "HW1", 60.0, 1} // Charlie HW1 is 60.0 -> Total Charlie: 60.0
  };

  std::vector<StudentReport> reports = consolidateSubmissions(rawLogs);

  std::cout << std::left << std::setw(12) << "Student" << std::setw(14)
            << "Total Score"
            << "Assignments Done" << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  for (const auto &r : reports) {
    std::cout << std::left << std::setw(12) << r.studentName << std::fixed
              << std::setprecision(1) << std::setw(14) << r.totalScore
              << r.uniqueAssignmentsCount << std::endl;
  }

  std::cout << "\nExpected Output:" << std::endl;
  std::cout << "Alice       175.0         2 (Alice tied with Bob, sorted "
               "alphabetically)"
            << std::endl;
  std::cout << "Bob         175.0         2" << std::endl;
  std::cout << "Charlie     60.0          1" << std::endl;
}

// ============================================================================
// PROBLEM 5: Curving Curves & Cluster Gap Analysis
// ============================================================================
/*
  Goal:
  1. Implement `countGradeTierUpgrades`:
     - Standard university grading scale:
       A: [90.0, 100.0]
       B: [80.0, 90.0)
       C: [70.0, 80.0)
       D: [60.0, 70.0)
       F: [0.0, 60.0)
     - Apply a Square Root Curve to every score:
       curvedScore = std::min(100.0, 10.0 * std::sqrt(rawScore))
     - Count how many students move to a strictly higher letter tier
       (e.g., F -> D, or B -> A).

  2. Implement `findLargestGradeGap`:
     - Educators analyze gaps between consecutive scores in a sorted class
       to determine where to place grade boundaries.
     - Sort scores ascending, and find the maximum gap between any two adjacent
  scores: `gap = scores[i] - scores[i - 1]`.
     - Return a `GradeGap` struct containing the lower score, upper score, and
  gap size.
     - If scores has < 2 elements, return {0.0, 0.0, 0.0}.
*/

struct GradeGap {
  double lowerScore;
  double upperScore;
  double gapSize;
};

int countGradeTierUpgrades(const std::vector<double> &rawScores) {
  if (rawScores.empty()) {
    return 0;
  }
  // TODO:
  // 1. Determine original letter tier for each score.
  // 2. Calculate curved score = std::min(100.0, 10.0 * std::sqrt(score)).
  // 3. Determine new letter tier and count how many students upgraded.
  return 0;
}

GradeGap findLargestGradeGap(std::vector<double> scores) {
  if (scores.size() < 2) {
    return {0.0, 0.0, 0.0};
  }
  // TODO:
  // 1. Sort scores ascending.
  // 2. Scan adjacent differences: scores[i] - scores[i - 1].
  // 3. Track and return the pair with the largest gap.
  return {0.0, 0.0, 0.0};
}

void problem5() {
  std::cout << "\033[35m\n=================== PROBLEM 5: Curving & Gap "
               "Detection ===================\033[0m"
            << std::endl;

  std::vector<double> rawScores = {42.0, 48.0, 52.0, 78.0, 82.0, 84.0, 96.0};

  int upgradedCount = countGradeTierUpgrades(rawScores);
  std::cout << "Students Upgraded after Curve: " << upgradedCount
            << " (Expected: 6)" << std::endl;

  GradeGap gap = findLargestGradeGap(rawScores);
  std::cout << "Largest Score Gap: " << std::fixed << std::setprecision(1)
            << gap.gapSize << " points (between " << gap.lowerScore << " and "
            << gap.upperScore << ")"
            << " (Expected: 26.0 between 52.0 and 78.0)" << std::endl;
}

// ============================================================================
// MAIN ENTRY POINT
// ============================================================================
int main() {
  typeText("\033[36m Initializing advanced analytics engine...\n\033[0m", 50);
  typeText("\033[32m Access granted to oct26 / p5.cpp.\n\033[0m", 60);

  const char frames[] = {'|', '/', '-', '\\'};
  for (int i = 0; i < 20; ++i) {
    std::cout << "\rLoading " << frames[i % 4] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }

  std::cout << "\033[35m\r Welcome to p5!   \n\033[0m";
  std::cout << "=================================================" << std::endl;
  std::cout << "  oct26/p5.cpp: Algorithmic Thinking & Analytics " << std::endl;
  std::cout << "=================================================" << std::endl;

  problem1();
  problem2();
  problem3();
  problem4();
  problem5();

  return 0;
}
