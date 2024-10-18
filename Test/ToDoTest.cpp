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