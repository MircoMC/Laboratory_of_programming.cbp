//
// Created by casti on 07/10/2024.
//

#include "ToDoList.h"
#include "algorithm"
#include "memory"


ToDo * TodoList::FindTask(const std::string &TitleTasktoFind) {
    auto it = std::find_if(Tasks.begin(), Tasks.end(), [&TitleTasktoFind](const std::unique_ptr<ToDo> &task) {
        return task->getTitle() == TitleTasktoFind || task->getDescription() == TitleTasktoFind;
    });

    if (it != Tasks.end()) {
        std::cout << "Task trovato: " << it->get()->getTitle() << " - " << it->get()->getDescription() << std::endl;
        return it->get();
    }
        throw std::runtime_error("Error: Task Not Found");

    }


void TodoList::AddTask(const ToDo &TasktoAdd) {
    Tasks.push_back(std::make_unique<ToDo>(TasktoAdd));
    //std::cout << "ADD!" << std::endl;
}

void TodoList::ModifyTask(const std::string &title, const std::string &newDescript, int newprio) {
    auto it = FindTask(title);
    (*it).SetNewDescription(newDescript);
    (*it).setPriority(newprio);

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
    try {
        auto it = FindTask(title);
        (*it).MarkAsFinished();
        Number_of_CompletedTasks++;
    }

    catch(std::runtime_error &c){
        std::cout << c.what() << std::endl;
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




