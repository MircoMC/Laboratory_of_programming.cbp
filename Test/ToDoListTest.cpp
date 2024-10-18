//
// Created by casti on 04/10/2024
#include <gtest/gtest.h>
#include "../ToDoList.h"

TEST(TodolistTest,Constructor){
    TodoList mytodolist;
    EXPECT_EQ(mytodolist.getNumberOfTasks(),0);
    EXPECT_EQ(mytodolist.getNumberOfUnCompletedTasks(),0);
    EXPECT_EQ(mytodolist.getNumberOfCompletedTasks(),0);
}

TEST(ToDoListTest, MarkAsComplete) {
    TodoList mytodolist;
    mytodolist.AddTask(ToDo("Task 1", "Descrizione del task 1", 1,Date(12,12,2029)));
    mytodolist.FindTask("Task 1")->MarkAsFinished();
    EXPECT_TRUE(mytodolist.FindTask("Task 1")->isFinished());

}