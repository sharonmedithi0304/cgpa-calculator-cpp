A powerful terminal-based CGPA Calculator built in C++17 that helps students calculate Semester GPA (SGPA) and Cumulative GPA (CGPA) using course marks or grade points.

Designed with clean modular architecture, STL usage, file persistence, sorting/search utilities, and multi-semester support — making it a strong academic + resume-worthy project for learning DSA, OOP concepts, file handling, and STL in C++.

✨ Features
📚 Academic Calculations
Calculate Semester GPA (SGPA)
Calculate Cumulative GPA (CGPA)
Supports multiple semesters
Weighted GPA calculation using course credits
📝 Flexible Input
Enter:
Raw marks (0–100)
Direct grade points
Automatic conversion to:
Grade Points
Letter Grades
🔍 Search & Sorting
Search courses by name (case-insensitive)
Sort courses by:
Grade
Credits
Supports:
Ascending order
Descending order
💾 File Handling
Save student records to files
Load saved student data
Persistent storage using file I/O
🧠 Modern C++ Usage
STL containers (vector)
Algorithms (sort)
Lambda expressions
Streams (fstream, stringstream)
Modular project structure
📊 Grade Mapping System
Marks Range	Grade Point	Letter Grade	Performance
90 – 100	10	O	Outstanding
80 – 89	9	A+	Excellent
70 – 79	8	A	Very Good
60 – 69	7	B+	Good
50 – 59	6	B	Above Average
45 – 49	5	C	Average
40 – 44	4	P	Pass
Below 40	0	F	Fail
🧮 GPA Formula

The GPA is calculated using the weighted average formula:

GPA=
∑Credits
∑(GradePoint×Credits)
	​


This ensures higher-credit subjects contribute proportionally more to the final GPA.


⚙️ Technologies Used
Technology	Purpose
C++17	Core programming language
STL Vector	Dynamic course storage
STL Algorithm	Sorting operations
Lambda Functions	Custom comparators
fstream	File handling
stringstream	Parsing structured data
Linear Search	Case-insensitive course lookup
🚀 Build & Run
Using Makefile
make
./cgpa_calculator
Manual Compilation
g++ -std=c++17 -Iinclude src/main.cpp src/cgpa.cpp -o cgpa_calculator

./cgpa_calculator
🖥️ Sample Workflow
1. Add Semester
2. Enter Course Details
3. Calculate SGPA
4. View CGPA
5. Sort Courses
6. Search Course
7. Save Data
8. Load Data
9. Exit
📌 Key Concepts Demonstrated

This project showcases practical implementation of:

Data Structures using STL
Modular programming
File persistence
CLI application design
Weighted average computation
Searching and sorting algorithms
Clean code organization
User-driven menu systems
🎯 Why This Project Matters

Unlike basic GPA calculators, this project combines:

Academic utility
Persistent storage
Search/sort operations
Multi-semester handling
Real-world CLI interaction

It is an excellent project for:

College mini-projects
Resume building
Practicing modern C++
Understanding STL deeply
🔮 Possible Future Improvements
GUI version using Qt / GTK
Database integration
Export reports as PDF
Authentication system
GPA analytics dashboard
Graph visualization of semester performance
Cross-platform executable support
🤝 Contributing

Contributions, suggestions, and improvements are welcome.

Feel free to fork the repository and submit a pull request.

📄 License

This project is open-source and available under the MIT License.

👨‍💻 Author

Developed with C++17 and STL for academic performance management.
