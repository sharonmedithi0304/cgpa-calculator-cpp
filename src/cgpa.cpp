#include "../include/cgpa.h"

// ─── Grade Utilities ────────────────────────────────────────────────

std::string getLetterGrade(float gp) {
    if (gp >= 10.0f) return "O  (Outstanding)";
    if (gp >= 9.0f)  return "A+ (Excellent)";
    if (gp >= 8.0f)  return "A  (Very Good)";
    if (gp >= 7.0f)  return "B+ (Good)";
    if (gp >= 6.0f)  return "B  (Above Average)";
    if (gp >= 5.0f)  return "C  (Average)";
    if (gp >= 4.0f)  return "P  (Pass)";
    return "F  (Fail)";
}

float getGradePoint(float marks) {
    if (marks >= 90) return 10.0f;
    if (marks >= 80) return 9.0f;
    if (marks >= 70) return 8.0f;
    if (marks >= 60) return 7.0f;
    if (marks >= 50) return 6.0f;
    if (marks >= 45) return 5.0f;
    if (marks >= 40) return 4.0f;
    return 0.0f;
}

// ─── GPA / CGPA Calculation ─────────────────────────────────────────

float calcGPA(Semester& sem) {
    float totalPoints = 0.0f;
    int totalCreds = 0;
    for (auto& c : sem.courses) {
        c.letterGrade = getLetterGrade(c.grade);
        totalPoints += c.grade * c.credits;
        totalCreds  += c.credits;
    }
    sem.totalCredits     = totalCreds;
    sem.totalGradePoints = totalPoints;
    sem.gpa = (totalCreds > 0) ? totalPoints / totalCreds : 0.0f;
    return sem.gpa;
}

float calcCGPA(Student& student) {
    float totalPoints = 0.0f;
    int totalCreds = 0;
    for (auto& sem : student.semesters) {
        calcGPA(sem);
        totalPoints += sem.totalGradePoints;
        totalCreds  += sem.totalCredits;
    }
    student.cgpa = (totalCreds > 0) ? totalPoints / totalCreds : 0.0f;
    return student.cgpa;
}

// ─── Sorting ────────────────────────────────────────────────────────

void sortCoursesByGrade(std::vector<Course>& courses, bool ascending) {
    std::sort(courses.begin(), courses.end(), [ascending](const Course& a, const Course& b) {
        return ascending ? a.grade < b.grade : a.grade > b.grade;
    });
}

void sortCoursesByCredits(std::vector<Course>& courses, bool ascending) {
    std::sort(courses.begin(), courses.end(), [ascending](const Course& a, const Course& b) {
        return ascending ? a.credits < b.credits : a.credits > b.credits;
    });
}

// ─── Search ─────────────────────────────────────────────────────────

int searchCourseByName(const std::vector<Course>& courses, const std::string& target) {
    // Linear search (case-insensitive)
    std::string t = target;
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    for (int i = 0; i < (int)courses.size(); i++) {
        std::string cn = courses[i].name;
        std::transform(cn.begin(), cn.end(), cn.begin(), ::tolower);
        if (cn.find(t) != std::string::npos) return i;
    }
    return -1;
}

// ─── Display ────────────────────────────────────────────────────────

void displayCourse(const Course& c) {
    std::cout << std::left
              << std::setw(30) << c.name
              << std::setw(10) << c.credits
              << std::setw(8)  << std::fixed << std::setprecision(1) << c.grade
              << c.letterGrade << "\n";
}

void displaySemester(const Semester& sem) {
    std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
    std::cout << "  Semester " << sem.semNumber << "\n";
    std::cout << "╚══════════════════════════════════════════════════════╝\n";
    std::cout << std::left
              << std::setw(30) << "Course"
              << std::setw(10) << "Credits"
              << std::setw(8)  << "GP"
              << "Grade\n";
    std::cout << std::string(65, '-') << "\n";
    for (const auto& c : sem.courses)
        displayCourse(c);
    std::cout << std::string(65, '-') << "\n";
    std::cout << "Total Credits : " << sem.totalCredits << "\n";
    std::cout << "Total GP      : " << std::fixed << std::setprecision(2) << sem.totalGradePoints << "\n";
    std::cout << "Semester GPA  : " << std::fixed << std::setprecision(4) << sem.gpa << "\n";
}

void displayCGPAReport(const Student& student) {
    std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
    std::cout << "           CGPA REPORT CARD\n";
    std::cout << "╚══════════════════════════════════════════════════════╝\n";
    std::cout << "Name    : " << student.name    << "\n";
    std::cout << "Roll No : " << student.rollNo  << "\n";
    std::cout << std::string(55, '=') << "\n";

    for (const auto& sem : student.semesters)
        displaySemester(sem);

    std::cout << "\n" << std::string(55, '=') << "\n";
    std::cout << "  ★  CGPA : " << std::fixed << std::setprecision(4) << student.cgpa
              << "  (" << getLetterGrade(student.cgpa) << ")\n";
    std::cout << std::string(55, '=') << "\n";
}

// ─── File I/O ───────────────────────────────────────────────────────

bool saveToFile(const Student& student, const std::string& filename) {
    std::ofstream f(filename);
    if (!f.is_open()) return false;

    f << student.name << "\n" << student.rollNo << "\n";
    f << student.semesters.size() << "\n";
    for (const auto& sem : student.semesters) {
        f << sem.semNumber << " " << sem.courses.size() << "\n";
        for (const auto& c : sem.courses)
            f << c.name << "|" << c.credits << "|" << c.grade << "\n";
    }
    f.close();
    return true;
}

bool loadFromFile(Student& student, const std::string& filename) {
    std::ifstream f(filename);
    if (!f.is_open()) return false;

    std::getline(f, student.name);
    std::getline(f, student.rollNo);
    int numSems; f >> numSems; f.ignore();

    for (int i = 0; i < numSems; i++) {
        Semester sem;
        int numCourses;
        f >> sem.semNumber >> numCourses; f.ignore();
        for (int j = 0; j < numCourses; j++) {
            std::string line; std::getline(f, line);
            std::stringstream ss(line);
            Course c;
            std::getline(ss, c.name, '|');
            ss >> c.credits; ss.ignore();
            ss >> c.grade;
            c.letterGrade = getLetterGrade(c.grade);
            sem.courses.push_back(c);
        }
        student.semesters.push_back(sem);
    }
    f.close();
    return true;
}

// ─── Input ──────────────────────────────────────────────────────────

Semester inputSemesterData(int semNum) {
    Semester sem;
    sem.semNumber = semNum;
    int n;
    std::cout << "  Number of courses in Semester " << semNum << ": ";
    std::cin >> n; std::cin.ignore();

    for (int i = 0; i < n; i++) {
        Course c;
        std::cout << "\n  Course " << i+1 << ":\n";
        std::cout << "    Name    : "; std::getline(std::cin, c.name);
        std::cout << "    Credits : "; std::cin >> c.credits;
        std::cin.ignore();
        char mode;
        std::cout << "    Enter via (m)arks or (g)rade point? [m/g]: ";
        std::cin >> mode; std::cin.ignore();

        if (mode == 'm' || mode == 'M') {
            float marks;
            std::cout << "    Marks (0-100): "; std::cin >> marks;
            c.grade = getGradePoint(marks);
        } else {
            std::cout << "    Grade Point (0-10): "; std::cin >> c.grade;
        }
        c.letterGrade = getLetterGrade(c.grade);
        std::cin.ignore();
        sem.courses.push_back(c);
    }
    calcGPA(sem);
    return sem;
}

Student inputStudentData() {
    Student s;
    std::cout << "\n  Student Name   : "; std::getline(std::cin, s.name);
    std::cout << "  Roll Number    : "; std::getline(std::cin, s.rollNo);
    int numSems;
    std::cout << "  No. of Semesters: "; std::cin >> numSems; std::cin.ignore();

    for (int i = 1; i <= numSems; i++)
        s.semesters.push_back(inputSemesterData(i));

    calcCGPA(s);
    return s;
}