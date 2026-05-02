#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>

struct Course {
    std::string name;
    int credits;
    float grade;      // grade points (e.g. 10, 9, 8...)
    std::string letterGrade;
};

struct Semester {
    int semNumber;
    std::vector<Course> courses;
    float gpa;
    int totalCredits;
    float totalGradePoints;
};

struct Student {
    std::string name;
    std::string rollNo;
    std::vector<Semester> semesters;
    float cgpa;
};

// Grade utils
std::string getLetterGrade(float gradePoint);
float getGradePoint(float marks);

// Core calc
float calcGPA(Semester& sem);
float calcCGPA(Student& student);

// Sort
void sortCoursesByGrade(std::vector<Course>& courses, bool ascending = false);
void sortCoursesByCredits(std::vector<Course>& courses, bool ascending = false);

// Search
int searchCourseByName(const std::vector<Course>& courses, const std::string& name);

// Display
void displayCourse(const Course& c);
void displaySemester(const Semester& sem);
void displayStudent(const Student& student);
void displayCGPAReport(const Student& student);

// File I/O
bool saveToFile(const Student& student, const std::string& filename);
bool loadFromFile(Student& student, const std::string& filename);

// Input
Student inputStudentData();
Semester inputSemesterData(int semNum);