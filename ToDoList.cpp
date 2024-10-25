//
// Created by casti on 07/10/2024.
//

#include "ToDoList.h"
#include "algorithm"
#include "memory"


void TodoList::AddTask(const ToDo &TasktoAdd) {
    Tasks.push_back(std::make_unique<ToDo>(TasktoAdd));
    //std::cout << "ADD!" << std::endl;
}

int TodoList::getNumberOfTasks() const {
    return Tasks.size();
}

int TodoList::getNumberOfUnCompletedTasks() const {
    return Tasks.size() - Number_of_CompletedTasks;
}

void TodoList::RemoveTask(const std::string &TasktoRemove) {
    Tasks.remove_if([&](const std::unique_ptr<ToDo> &task) {
        return task->getTitle() == TasktoRemove || task->getDescription() == TasktoRemove;
    });

}


void TodoList::PrintAllTasks() {
    for (auto &it: Tasks) {
        (*it).Print_details();
    }
    std::cout << "Number of Uncompleted Task: " << getNumberOfUnCompletedTasks() << std::endl;
    std::cout << "Number of Completed Task: " << getNumberOfCompletedTasks() << std::endl;
    std::cout << "Number of Tasks: " << getNumberOfTasks() << std::endl;
}

const std::string &TodoList::getTitleTodoList() const {
    return title_todo_list;
}

int TodoList::getNumberOfCompletedTasks() const {
    return Number_of_CompletedTasks;
}

std::list<ToDo *> TodoList::FindTask(const std::string &TitleTasktoFind) {
    std::list<ToDo *> list;
    for (auto &task: Tasks) {
        if (task->getTitle() == TitleTasktoFind || task->getDescription() == TitleTasktoFind) {
            std::cout << "Task trovato: " << task->getTitle() << " - " << task->getDescription() << std::endl;
            list.push_back(task.get());
        }
    }
    int size = static_cast<int>(list.size());
    std::cout << "Number of Task Found: " << size << std::endl;
    return list;
}

std::list<ToDo *>::iterator TodoList::MarkAsCompleted(const std::string &title, int TaskIndex) {
    auto tasks = FindTask(title);
    int size = static_cast<int>(tasks.size());
    if (size == 0) {
        std::cout << "Error: Empty list" << std::endl;
        return tasks.end();
    }

    if (TaskIndex >= 0 && TaskIndex < size) {
        auto it = std::next(tasks.begin(), TaskIndex);
        (*it)->MarkAsFinished();
        Number_of_CompletedTasks++;
        std::cout << "Task Complete: " << (*it)->getTitle() << " _ " << (*it)->getDescription() << std::endl;
        return it;
    }
    throw std::out_of_range("Error: Unvalid Index");
}

std::list<ToDo *>::iterator TodoList::ModifyTask(const std::string &title, const std::string &newDescript, int newprio, int TaskIndex) {

    auto tasks = FindTask(title);
    int size = static_cast<int>(tasks.size());
    if (size == 0) {
        std::cout << "Error: Empty list" << std::endl;
        return tasks.end();
    }
    if (TaskIndex >= 0 && TaskIndex < size) {
        auto it = std::next(tasks.begin(), TaskIndex);
        (*it)->setPriority(newprio);
        (*it)->setDescription(newDescript);
        std::cout << "Task Modificato: " << (*it)->getTitle() << " - " << (*it)->getDescription() << " - "
                  << (*it)->getPriority() << std::endl;
        return it;
    }
    throw std::out_of_range("Error: Unvalid Index");
}






