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
    auto tasks = FindTask(title);
    for ( auto it = tasks.begin();it != tasks.end(); it++){
        (*it)->setPriority(newprio);
        (*it)->setDescription(newDescript);
        std::cout << "Task Modificato: " << (*it)->getTitle() << " - " << (*it)->getDescription() << " - " << (*it)->getPriority() << std::endl;
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
    for(auto it = tasks.begin();it != tasks.end();it++){
        (*it)->MarkAsFinished();
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
std::list<ToDo*> TodoList::FindTask(const std::string &TitleTasktoFind) {
    std::list<ToDo*> result;
    for (auto &task : Tasks) {
        if (task->getTitle() == TitleTasktoFind || task->getDescription() == TitleTasktoFind) {
            std::cout << "Task trovato: " << task->getTitle() << " - " << task->getDescription() << std::endl;
            result.push_back(task.get());
        }
    }
    int size = static_cast<int>(result.size());
    std::cout << "Number of Task Found: " << size << std::endl;
    return result;
}


const std::list<std::unique_ptr<ToDo>> &TodoList::getTasks() const {
    return Tasks;
}


