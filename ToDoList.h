//
// Created by casti on 07/10/2024.
//

#ifndef LABORATORY_OF_PROGRAMMING_TODOLIST_H
#define LABORATORY_OF_PROGRAMMING_TODOLIST_H


#include <list>
#include <memory>
#include "ToDo.h"

class TodoList {
public:
    explicit TodoList(const std::string &title = "ToDoList.txt") : title_todo_list(title) {}

    void AddTask(const ToDo &TasktoAdd);

    void RemoveTask(const std::string &TasktoRemove);

    void ModifyTask(const std::string &title, const std::string &newDescript, int newprio);

    void MarkAsCompleted(const std::string &title);

    void PrintAllTasks();

    void ClearTasks(){
        Tasks.clear();
    }

    int getNumberOfTasks() const;

    int getNumberOfUnCompletedTasks() const;

    int getNumberOfCompletedTasks() const;

    std::list<std::unique_ptr<ToDo>>::iterator FindTask(const std::string& TitleTasktoFind);

private:
    std::list<std::unique_ptr<ToDo>> Tasks;
    std::string title_todo_list;
    int Number_of_CompletedTasks{0};


};

#endif //LABORATORY_OF_PROGRAMMING_TODOLIST_H
