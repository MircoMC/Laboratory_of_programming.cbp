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

    // Stampa tutte le task
    std::cout << "Tutte le task:" << std::endl;
    myTodoList.PrintAllTasks();
    // Stampa tutte le task dopo la modifica
    std::cout << "\nDopo modifica:" << std::endl;
    // Modifica una task
    try {
        myTodoList.ModifyTask("Task 1", "Nuova descrizione del task 1", 3);
        myTodoList.PrintAllTasks();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Marca una task come completata
    try {
        myTodoList.MarkAsCompleted("Task 2");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Stampa tutte le task dopo aver segnato una task come completata
    std::cout << "\nDopo aver completato una task:" << std::endl;
    myTodoList.PrintAllTasks();

    // Rimuovi una task
    try {
        myTodoList.RemoveTask("Task 1");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        myTodoList.ModifyTask("Task 1", "Nuova descrizione del task 1", 3);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Stampa tutte le task dopo la rimozione
    std::cout << "\nDopo la rimozione:" << std::endl;
    myTodoList.PrintAllTasks();

    return 0;
}
