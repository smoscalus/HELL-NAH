#include <iostream>
#include "../include/hellnah/Engine/Database.h"
#include "../include/hellnah/Engine/Table.h"

using namespace std;

struct student
{
    char Value[32];
    int age;
};

void test_insert(Engine::Table<student> students, int test_data)
{
    for (int i = 0; i <= test_data; i++)
    {
        student s;
        s.age = i;
        strcpy(s.Value, "pidr");
        cout << "Alo";
        students.insert(s);
    }
}

void test_get(Engine::Table<student>& students, int test_data)
{
    for (int j = 1; j <= test_data; j++)
    {
        student student = students.get(j);

        int i = 0;
        while (student.Value[i] != '\0')
        {
            cout << student.Value[i];
            i++;
        }
        cout << ' ';
        cout << student.age << '\n';
    }
}

int main()
{
    auto db = Engine::Database("students.hellnot");

    auto students = db.open_table<student>("students");

    test_get(students, 20);
    // students.remove(1);
    return 1;
}
