//
// Created by casti on 07/10/2024.
//

#include "ToDoList.h"
#include "algorithm"
#include "memory"


void TodoList::AddTask(const ToDo &TasktoAdd) {
    Tasks.push_back(std::make_unique<ToDo>(TasktoAdd));
    std::cout <<"ADD!" << std::endl;
}

void TodoList::ModifyTask(const std::string &title, const std::string &newDescript, int newprio) {
    auto it = FindTask(title);
    // Verifica che il task sia stato trovato
    (*it)->SetNewDescription(newDescript); // Dereferenzia l'iteratore
    (*it)->setPriority(newprio);

}

int TodoList::getNumberOfTasks() const {
    return Tasks.size();
}

int TodoList::getNumberOfUnCompletedTasks() const {
    return Tasks.size() - Number_of_CompletedTasks;
}

void TodoList::RemoveTask(const std::string &TasktoRemove) {
    try {
        auto it = FindTask(TasktoRemove);
        Tasks.erase(it);  // Elimina il task usando l'iteratore
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void TodoList::MarkAsCompleted(const std::string &title) {
    auto it = FindTask(title);
    (*it)->MarkAsFinished();
    Number_of_CompletedTasks++;
}

void TodoList::PrintAllTasks()  {
    for(auto &it : Tasks) {
        (*it).Print_details();
    }
    std::cout << "Number of Uncompleted Task: " << getNumberOfUnCompletedTasks() << std::endl;
    std::cout << "Number of Tasks: " << getNumberOfTasks() << std::endl;

}

std::list<std::unique_ptr<ToDo>>::iterator TodoList::FindTask(const std::string &TitleTasktoFind) {
    auto it = std::find_if(Tasks.begin(), Tasks.end(), [&TitleTasktoFind](const std::unique_ptr<ToDo>& task) {
        return task->getTitle() == TitleTasktoFind || task->getDescription() == TitleTasktoFind;
    });

    if (it != Tasks.end()) {
        return it;
    } else {
        throw std::runtime_error("Error: Task Not Found");
    }
}

int TodoList::getNumberOfCompletedTasks() const {
    return Number_of_CompletedTasks;
}
