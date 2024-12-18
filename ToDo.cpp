//
// Created by casti on 07/10/2024.
//

#include "ToDo.h"
#include "iostream"

const std::string &ToDo::getDescription() const {
    return Description;
}
void ToDo::setDate(const Date& date){
    ToDo::data=date;
}
int ToDo::getPriority() const {
    return Priority;
}

void ToDo::setPriority(int priority) {
    if(priority < 0 || priority > 5)
        throw std::out_of_range("Unvalid Priority!");
    Priority = priority;
}

const std::string& ToDo::getTitle() const{
    return Title;
}

void ToDo::setTitle(const std::string &title) {
    Title = title;
}

bool ToDo::isFinished() const {
    return Finished;
}

void ToDo::MarkAsFinished() {
    this->Finished = true;
}

void ToDo::setDescription(const std::string &description)  {
    Description = description;
}

void ToDo::Print_details() const {
    std::cout << "Task title: " << getTitle() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Priority level: " << getPriority() << std::endl;
   std::cout << data.PrintDate() << std::endl;// Utilizza il metodo PrintDate della classe Date
    // Stampa lo stato della task (completato o da fare)
    std::cout << "Status: " << (isFinished() ? "Completed" : "To Do") << std::endl;
}

const Date &ToDo::getData() const {
    return data;
}


