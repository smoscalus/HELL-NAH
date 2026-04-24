#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/hellnah/Engine/Database.h"

struct student
{
    char Value[32];
    int Age;
};

TEST_CASE("Insert works") {

    auto db = Engine::Database("test_students.hellnot");
    auto students = db.open_table<student>("students");

    students.clear_database();
    
    auto id = students.insert({"Alex", 20});
    auto student = students.get(id);

    REQUIRE(students.quantity == 1);
    REQUIRE(strcmp(student.Value, "Alex") == 0);
    REQUIRE(student.Age == 20);
}

TEST_CASE("Double insert works") {

    auto db = Engine::Database("test_students.hellnot");
    auto students = db.open_table<student>("students");

    students.clear_database();
    
    auto id_1 = students.insert({"Alex", 20});
    auto id_2 = students.insert({"Bob", 21});

    auto student_1 = students.get(id_1);
    auto student_2 = students.get(id_2);

    REQUIRE(students.quantity == 2);
    REQUIRE(strcmp(student_1.Value, "Alex") == 0);
    REQUIRE(student_1.Age == 20);
    REQUIRE(strcmp(student_2.Value, "Bob") == 0);
    REQUIRE(student_2.Age == 21);
}

TEST_CASE("Remove works") {

    auto db = Engine::Database("test_students.hellnot");
    auto students = db.open_table<student>("students");

    students.clear_database();

    auto id = students.insert({"Alex", 20});

    students.remove(id);
    REQUIRE_THROWS_WITH(students.get(id), "Record is deleted");
}
