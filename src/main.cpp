#include "../include/cgpa.h"

void printBanner() {
    std::cout << R"(
  ╔═══════════════════════════════════════════════════╗
  ║          C G P A   C A L C U L A T O R           ║
  ║           Built with C++ | DSA Edition           ║
  ╚═══════════════════════════════════════════════════╝
)";
}

void printMenu() {
    std::cout << "\n  ┌─────────────────────────────┐\n";
    std::cout << "  │         MAIN MENU           │\n";
    std::cout << "  ├─────────────────────────────┤\n";
    std::cout << "  │  1. New Student Entry        │\n";
    std::cout << "  │  2. Load from File           │\n";
    std::cout << "  │  3. Save to File             │\n";
    std::cout << "  │  4. View CGPA Report         │\n";
    std::cout << "  │  5. Sort Courses (by grade)  │\n";
    std::cout << "  │  6. Sort Courses (by credit) │\n";
    std::cout << "  │  7. Search Course            │\n";
    std::cout << "  │  8. Add Semester             │\n";
    std::cout << "  │  9. Exit                     │\n";
    std::cout << "  └─────────────────────────────┘\n";
    std::cout << "  Choice: ";
}

int main() {
    printBanner();

    Student student;
    bool hasData = false;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice; std::cin.ignore();

        switch (choice) {
            case 1:
                student = inputStudentData();
                hasData = true;
                std::cout << "\n  [✓] Data entered. CGPA = "
                          << std::fixed << std::setprecision(4) << student.cgpa << "\n";
                break;

            case 2: {
                std::string fname;
                std::cout << "  Filename: "; std::getline(std::cin, fname);
                if (loadFromFile(student, fname)) {
                    calcCGPA(student);
                    hasData = true;
                    std::cout << "  [✓] Loaded: " << fname << "\n";
                } else {
                    std::cout << "  [✗] Cannot open file.\n";
                }
                break;
            }

            case 3: {
                if (!hasData) { std::cout << "  No data yet.\n"; break; }
                std::string fname;
                std::cout << "  Filename (e.g. student.txt): "; std::getline(std::cin, fname);
                if (saveToFile(student, "data/" + fname))
                    std::cout << "  [✓] Saved to data/" << fname << "\n";
                else
                    std::cout << "  [✗] Save failed.\n";
                break;
            }

            case 4:
                if (!hasData) { std::cout << "  No data yet.\n"; break; }
                displayCGPAReport(student);
                break;

            case 5: {
                if (!hasData) { std::cout << "  No data yet.\n"; break; }
                int sn;
                std::cout << "  Semester number (1-" << student.semesters.size() << "): ";
                std::cin >> sn; std::cin.ignore();
                sn--;
                if (sn >= 0 && sn < (int)student.semesters.size()) {
                    char ord;
                    std::cout << "  (a)scending or (d)escending? "; std::cin >> ord; std::cin.ignore();
                    sortCoursesByGrade(student.semesters[sn].courses, ord == 'a');
                    std::cout << "  Sorted. Viewing semester:\n";
                    displaySemester(student.semesters[sn]);
                } else std::cout << "  Invalid semester.\n";
                break;
            }

            case 6: {
                if (!hasData) { std::cout << "  No data yet.\n"; break; }
                int sn;
                std::cout << "  Semester number (1-" << student.semesters.size() << "): ";
                std::cin >> sn; std::cin.ignore(); sn--;
                if (sn >= 0 && sn < (int)student.semesters.size()) {
                    char ord;
                    std::cout << "  (a)scending or (d)escending? "; std::cin >> ord; std::cin.ignore();
                    sortCoursesByCredits(student.semesters[sn].courses, ord == 'a');
                    displaySemester(student.semesters[sn]);
                } else std::cout << "  Invalid semester.\n";
                break;
            }

            case 7: {
                if (!hasData) { std::cout << "  No data yet.\n"; break; }
                int sn;
                std::cout << "  Semester to search (1-" << student.semesters.size() << "): ";
                std::cin >> sn; std::cin.ignore(); sn--;
                if (sn >= 0 && sn < (int)student.semesters.size()) {
                    std::string query;
                    std::cout << "  Course name keyword: "; std::getline(std::cin, query);
                    int idx = searchCourseByName(student.semesters[sn].courses, query);
                    if (idx == -1) std::cout << "  Not found.\n";
                    else { std::cout << "  Found at index " << idx << ":\n"; displayCourse(student.semesters[sn].courses[idx]); }
                } else std::cout << "  Invalid semester.\n";
                break;
            }

            case 8: {
                if (!hasData) { std::cout << "  Create student first (option 1).\n"; break; }
                int nextSem = student.semesters.size() + 1;
                student.semesters.push_back(inputSemesterData(nextSem));
                calcCGPA(student);
                std::cout << "  [✓] Semester " << nextSem << " added. New CGPA = "
                          << std::fixed << std::setprecision(4) << student.cgpa << "\n";
                break;
            }

            case 9:
                std::cout << "\n  Bye!\n";
                return 0;

            default:
                std::cout << "  Invalid choice.\n";
        }
    }
}