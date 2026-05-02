CGPA Calculator — C++
Calculates Semester GPA and Cumulative CGPA from course data.
Features

Multi-semester support
Enter via marks or grade points
Sort courses by grade / credits (ascending or descending)
Search course by name (case-insensitive)
File I/O — save/load student data
Letter grade mapping (O / A+ / A / B+ / B / C / P / F)

Grade Scale
MarksGrade PointLetter90–10010O (Outstanding)80–899A+ (Excellent)70–798A (Very Good)60–697B+ (Good)50–596B (Above Avg)45–495C (Average)40–444P (Pass)< 400F (Fail)
Build & Run
bashmake
./cgpa_calculator
Or manually:
bashg++ -std=c++17 -Iinclude src/main.cpp src/cgpa.cpp -o cgpa_calculator
./cgpa_calculator
Project Structure
cgpa_calculator/
├── include/
│   └── cgpa.h          # Structs + declarations
├── src/
│   ├── cgpa.cpp        # Core logic (calc, sort, search, I/O)
│   └── main.cpp        # CLI menu
├── data/               # Saved student files go here
├── Makefile
└── README.md
Technologies

C++17
STL (vector, algorithm, fstream, sstream)
Sorting: std::sort with lambda comparators
Search: linear search (case-insensitive)
File Handling: ifstream / ofstream
Arithmetic: weighted average for GPA/CGPA