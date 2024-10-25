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

    const std::string &getTitleTodoList() const;

    void RemoveTask(const std::string &TasktoRemove);

    std::list<ToDo*>::iterator ModifyTask(const std::string &title, const std::string &newDescript, int newprio,int TaskIndex);

    std::list<ToDo*>::iterator MarkAsCompleted(const std::string &title,int TaskIndex);

    void PrintAllTasks();

    void ClearTasks(){
        Tasks.clear();
    }

    std::list<ToDo*> FindTask(const std::string& TitleTasktoFind); //

    int getNumberOfTasks() const;

    int getNumberOfUnCompletedTasks() const;

    int getNumberOfCompletedTasks() const;



private:
    std::list<std::unique_ptr<ToDo>> Tasks;
    std::string title_todo_list;
    int Number_of_CompletedTasks{0};



};

#endif //LABORATORY_OF_PROGRAMMING_TODOLIST_H
