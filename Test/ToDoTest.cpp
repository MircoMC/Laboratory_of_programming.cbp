//
// Created by casti on 04/10/2024.
//
#include <gtest/gtest.h>
#include "../ToDo.h"

TEST(ToDoTest,ConstructorTest){
ToDo task("Laboratorio di Programmazione","Concludere il programma",4,Date(12,10,2024));
    EXPECT_EQ(task.getTitle(), "Laboratorio di Programmazione");
    EXPECT_EQ(task.getDescription(), "Concludere il programma");
    EXPECT_EQ(task.getPriority(), 4);
    EXPECT_EQ(task.getData().PrintDate(),"Adding date->12/10/2024");
}

TEST(ToDoTest,SettersToDo){

    ToDo td("Task 1","Descrizione",2,Date(11,11,2000));
    td.setTitle("New title");
    EXPECT_EQ(td.getTitle(),"New title");
    td.SetNewDescription("new description");
    EXPECT_EQ(td.getDescription(),"new description");
    EXPECT_THROW(td.setPriority(9),std::out_of_range);
    td.setPriority(3);
    EXPECT_EQ(td.getPriority(),3);
    EXPECT_THROW(td.SetDate(Date(30,2,2010)),std::out_of_range);
}

TEST(ToDoTest,MarkAsFinished){
    ToDo td("Task 1","Descrizione",2,Date(11,11,2000));
    td.MarkAsFinished();
    EXPECT_TRUE(td.isFinished());
}

