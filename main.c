#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct student {
    int id;
    char name[20];
    float grade;
} Student;

typedef struct course {
    char name[20];
    float avgGrade;
    int studentsCount;
    Student *enrolledStudents;
} Course;

typedef struct school {
    char name[20];
    int coursesCount;
    Course *courses;
} School;

Student *createStudent() {
    Student *student = malloc(sizeof(Student));
    printf("Enter student's id: ");
    scanf("%d", &student->id);

    printf("Enter student's name: ");
    scanf("%s", student->name);

    printf("Enter student's grade: ");
    scanf("%f", &student->grade);

    return student;
}

void updateAvgGrade(Course *course) {
    float totalGrades = 0;
    for (int i = 0; i < course->studentsCount; i++) {
        totalGrades += course->enrolledStudents[i].grade;
    }
    course->avgGrade = totalGrades / (float)course->studentsCount;
}

Course *createCourse() {
    Course *course = malloc(sizeof(Course));

    printf("Enter course's name: ");
    scanf("%s", course->name);

    int studentsCount;
    printf("Enter number of students in the course: ");
    scanf("%d", &studentsCount);

    course->studentsCount = studentsCount;
    course->enrolledStudents = malloc(sizeof(Student) * studentsCount);
    for (int i = 0; i < studentsCount; i++) {
        Student *student = createStudent();
        course->enrolledStudents[i] = *student;
        free(student);
    }

    updateAvgGrade(course);

    return course;
}

School *createSchool() {
    School *school = malloc(sizeof(School));
    int coursesCount;
    printf("Enter school's name: ");
    scanf("%s", school->name);

    printf("Enter number of courses: ");
    scanf("%d", &coursesCount);

    school->coursesCount = coursesCount;
    school->courses = malloc(sizeof(Course) * coursesCount);
    for (int i = 0; i < coursesCount; i++) {
        Course *course = createCourse();
        school->courses[i] = *course;
        free(course);
    }
    return school;
}

void printStudentDetails(Student *student) {
    printf("Student #%d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("\n");
}

void printCourseDetails(Course *course) {
    printf("Course \"%s\"\n", course->name);
    printf("Average grade: %f\n", course->avgGrade);
    for (int i = 0; i < course->studentsCount; i++) {
        printStudentDetails(&(*course).enrolledStudents[i]);
    }
    printf("\n");
}

void printSchoolDetails(School *school) {
    printf("School \"%s\"\n", school->name);
    for (int i = 0; i < school->coursesCount; i++) {
        printCourseDetails(&(*school).courses[i]);
    }
    printf("\n");
}

bool studentInCourse(int studentId, Course *course) {
    for (int i = 0; i < course->studentsCount; i++) {
        if (course->enrolledStudents[i].id == studentId) return true;
    }
    return false;
}

bool studentInSchool(int studentId, School *school) {
    for (int i = 0; i < school->coursesCount; i++) {
        if (studentInCourse(studentId, &(school->courses[i]))) return true;
    }
    return false;
}

void printAllStudentCourses(int studentId, School *school) {
    printf("Student #%d's courses:\n", studentId);
    for (int i = 0; i < school->coursesCount; i++) {
        if (studentInCourse(studentId, &(school->courses[i]))) printCourseDetails(&(school->courses[i]));
    }
}

void printStudentsWhoFailedACourse(Course *course, float passingGrade) {
    printf("Students who failed in %s\n", course->name);
    for (int i = 0; i < course->studentsCount; i++) {
        if (course->enrolledStudents[i].grade < passingGrade) printStudentDetails(&(course->enrolledStudents[i]));
    }
}

void printStudentsWhoPassedACourse(Course *course, float passingGrade) {
    printf("Students who passed in %s\n", course->name);
    for (int i = 0; i < course->studentsCount; i++) {
        if (course->enrolledStudents[i].grade >= passingGrade) printStudentDetails(&(course->enrolledStudents[i]));
    }
}

void printCoursesWithAPassedAvgGrade(School *school, float passingGrade) {
    printf("Courses with passed average grade:\n");
    for (int i = 0; i < school->coursesCount; i++) {
        if (school->courses[i].avgGrade >= passingGrade) printCourseDetails(&(school->courses[i]));
    }
}

void printCoursesWithAFailedAvgGrade(School *school, float passingGrade) {
    printf("Courses with failed average grade:\n");
    for (int i = 0; i < school->coursesCount; i++) {
        if (school->courses[i].avgGrade < passingGrade) printCourseDetails(&(school->courses[i]));
    }
}

void printAverageGradeBetweenCourses(School *school) {
    float gradesSum = 0;
    for (int i = 0; i < school->coursesCount; i++) {
        printf("Course \"%s\"'s average grade = %f", school->courses[i].name, school->courses[i].avgGrade);
        gradesSum += school->courses[i].avgGrade;
    }

    printf("Overall average = %f\n", gradesSum / (float)school->coursesCount);
}

void printCourseWithHighestAvgGrade(School *school) {
    Course highestAvgCourse = school->courses[0];
    for (int i = 1; i < school->coursesCount; i++) {
        if (highestAvgCourse.avgGrade < school->courses[i].avgGrade) highestAvgCourse = school->courses[i];
    }
    printf("Course with highest average grade:\n");
    printCourseDetails(&highestAvgCourse);
}

int main() {

    return 0;
}
