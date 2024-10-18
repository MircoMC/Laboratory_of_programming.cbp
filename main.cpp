#include <iostream>
#include "TodoList.h"
#include "TodoList.cpp"
#include "ToDo.h"
#include "ToDo.cpp"
#include "Date.h"
#include "Date.cpp"
int main() {
    // Crea un oggetto TodoList
    TodoList myTodoList;

    // Crea alcune date
    Date date1(12, 2, 2024);
    Date date2(14, 10, 2024);

    // Crea alcuni task e aggiungili alla lista
    myTodoList.AddTask(ToDo("Task 1", "Descrizione del task 1", 1, date1));
    myTodoList.AddTask(ToDo("Task 2", "Descrizione del task 2", 2, date2));
    myTodoList.MarkAsCompleted("Task 1");

}
//