//
// Created by casti on 04/10/2024
#include <gtest/gtest.h>
#include "../ToDoList.h"

TEST(ToDolistTest, Constructor) {
    TodoList mytodolist;
    EXPECT_EQ(mytodolist.getNumberOfTasks(), 0);
    EXPECT_EQ(mytodolist.getNumberOfUnCompletedTasks(), 0);
    EXPECT_EQ(mytodolist.getNumberOfCompletedTasks(), 0);
}


TEST(ToDolistTest, AddTest) {
    TodoList mytodolist;
    ToDo td1("Task 1", "Descrizione del task 1", 1, Date(12, 12, 2029));
    mytodolist.AddTask(td1);
    EXPECT_EQ(mytodolist.getNumberOfTasks(), 1);
}

TEST(ToDolistTest, FindTest) {
    TodoList mytodolist;
    ToDo td1("task 2", "descrizione", 4, Date(2, 2, 2023));
    ToDo td2("task 2", "io", 2, Date(3, 3, 2003));
    mytodolist.AddTask(td1);
    mytodolist.AddTask(td2);
    int size = static_cast<int>(mytodolist.FindTask("task 2").size());
    EXPECT_EQ(size, mytodolist.getNumberOfTasks());
    EXPECT_EQ(mytodolist.FindTask("task 3").size(), 0);
}

TEST(ToDolistTest, RemoveTest) {
    TodoList mytodolist;
    ToDo td1("task 1", "Continuare il programma di ASD", 1, Date(2, 2, 2023));
    ToDo td2("task 2", "descrizione", 4, Date(2, 2, 2023));
    mytodolist.AddTask(td1);
    mytodolist.AddTask(td2);
    mytodolist.RemoveTask("task 2");
    EXPECT_EQ(mytodolist.getNumberOfTasks(), 1);
}

TEST(ToDolistTest, MarkasCompletedTest) {

    TodoList mytodolist;
    ToDo todo1("task 1", "finire il progetto", 1, Date(2, 2, 2023));
    ToDo todo2("task 1", "andare ad allenarsi", 4, Date(2, 2, 2023));
    mytodolist.AddTask(todo1);
    mytodolist.AddTask(todo2);
    EXPECT_TRUE((*mytodolist.MarkAsCompleted("task 1", 1))->isFinished());

    //Unvalid index for "TaskIndex"
    EXPECT_THROW(mytodolist.MarkAsCompleted("task 1", 4), std::out_of_range);
    EXPECT_THROW(mytodolist.MarkAsCompleted("task 1", -2), std::out_of_range);

    //update status's task in the list
    EXPECT_EQ(mytodolist.getNumberOfCompletedTasks(), 1);
    EXPECT_EQ(mytodolist.getNumberOfUnCompletedTasks(), 1);

}

TEST(ToDolistTest, ModifyTask) {
    TodoList todoList;
    // Aggiungi alcune task di esempio
    todoList.AddTask(ToDo{"Task 2", "Descrizione 1", 1, Date(22, 2, 2022)});
    todoList.AddTask(ToDo{"Task 2", "Descrizione 2", 2, Date(12, 10, 2024)});
    todoList.AddTask(ToDo{"Task 3", "Descrizione 3", 3, Date(21, 11, 2023)});

    EXPECT_EQ((*todoList.ModifyTask("Task 3", "Nuova Descrizione", 5, 0))->getDescription(), "Nuova Descrizione");
    EXPECT_EQ((*todoList.ModifyTask("Task 2", "Nuova Descrizione", 5, 0))->getPriority(), 5);

    // try to enter a priority that is too high/low
    EXPECT_THROW(todoList.ModifyTask("Task 2", "Nuova Descrizione", 7, 0),std::out_of_range);
    EXPECT_THROW(todoList.ModifyTask("Task 2", "Nuova Descrizione", -1, 0),std::out_of_range);

    //Unvalid index for "TaskIndex"
    EXPECT_THROW(todoList.ModifyTask("Task 2", "Nuova Descrizione", 5, -2),std::out_of_range);
    EXPECT_THROW(todoList.ModifyTask("Task 2", "Nuova Descrizione", 5, 4),std::out_of_range);

}