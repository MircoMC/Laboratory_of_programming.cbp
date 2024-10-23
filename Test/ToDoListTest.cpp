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



TEST(TodoListTest,AddTest){
    TodoList mytodolist;
    ToDo td1("Task 1", "Descrizione del task 1", 1,Date(12,12,2029));
    mytodolist.AddTask(td1);
    EXPECT_EQ(mytodolist.getNumberOfTasks(),1);
}

TEST(ToDoListTest,FindTest) {
    TodoList mytodolist;
    ToDo td1("task 2","descrizione",4,Date(2,2,2023));
    ToDo td2 ("task 2","io",2,Date(3,3,2003));
    mytodolist.AddTask(td1);
    mytodolist.AddTask(td2);
    int size = static_cast<int>(mytodolist.FindTask("task 2").size());
    EXPECT_EQ(size,mytodolist.getNumberOfTasks());
    EXPECT_EQ(mytodolist.FindTask("task 3").size(),0);
}

TEST(TodoListTest,RemoveTest){
    TodoList mytodolist;
    ToDo td("task 1","des",1,Date(2,2,2023));
    ToDo td1("task 2","descrizione",4,Date(2,2,2023));
    mytodolist.AddTask(td1);
    mytodolist.AddTask(td);
    mytodolist.RemoveTask("task 2");
    EXPECT_EQ(mytodolist.getNumberOfTasks(),1);
}

TEST(TodoListTest, MarkasCompletedTest) {
    TodoList mytodolist;
    ToDo td("task 1", "des", 1, Date(2, 2, 2023));
    ToDo td1("task 2", "descrizione", 4, Date(2, 2, 2023));
    mytodolist.AddTask(td1);
    mytodolist.AddTask(td);
    mytodolist.MarkAsCompleted("task 1");
    auto tasks = mytodolist.FindTask("task 1");
    ASSERT_FALSE(tasks.empty());
    EXPECT_TRUE(tasks.front()->isFinished());
    EXPECT_EQ(mytodolist.getNumberOfCompletedTasks(),1);
    EXPECT_EQ(mytodolist.getNumberOfUnCompletedTasks(),1);
}