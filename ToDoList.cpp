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

void TodoList::ModifyTask(const std::string &title, const std::string &newDescript, int newprio) {
    auto it = FindTask(title);
    {
        auto tasks = FindTask(title);
        if (!tasks.empty()) {
            auto &task = tasks.front();
            task->setPriority(newprio);
            task->setDescription(newDescript);
            std::cout << "Task modificato: " << task->getTitle() << " - " << task->getDescription() << " - Priorità: "
                      << task->getPriority() << std::endl;
        } else {
            std::cerr << "Errore: Task non trovato" << std::endl;
        }

    }
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

void TodoList::MarkAsCompleted(const std::string &title) {
    auto tasks = FindTask(title);
    for(auto it = tasks.begin();it != tasks.end();it++) {
        if (!tasks.empty()) {
            it->get()->MarkAsFinished();
            std::cout << "Task completato: " << it->get()->getTitle() << " - " << it->get()->getDescription() << std::endl;
        }
        else{
            std::cerr << "Errore: Task/s non trovato/e" << std::endl;
        }
    }

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

std::list<std::unique_ptr<ToDo>> TodoList::FindTask(const std::string &TitleTasktoFind) {
    std::list<std::unique_ptr<ToDo>> result;
    for (auto it = Tasks.begin(); it != Tasks.end();it++) {
        if ((*it)->getTitle() == TitleTasktoFind || (*it)->getDescription() == TitleTasktoFind) {
            std::cout << "Task trovato: " << (*it)->getTitle() << " - " << (*it)->getDescription() << std::endl;
            result.push_back(std::move(*it));
        }
    }
    return result;
}
