#include <iostream>
#include "../include/hellnah/Engine/Database.h"

using namespace std;

struct student
{
    char Value[32] = "vasya";
    int age = 10;
};

int main()
{
    student s;
    auto db = Engine::Database("students.hellnot");

    auto students = db.open_table<student>("students");

    auto id = students.insert(s);
    auto student = students.get(id);

    int i;
    while (student.Value[i] != '\0')
    {
        cout << student.Value[i];
        i++;
    }
    cout << student.age;

    students.remove(1);
}
