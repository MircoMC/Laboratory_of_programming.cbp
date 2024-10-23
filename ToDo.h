//
// Created by casti on 20/09/2024.
//

#ifndef LABORATORY_OF_PROGRAMMING_TODO_H
#define LABORATORY_OF_PROGRAMMING_TODO_H

#include "Date.h"
#include "sstream"

class ToDo {
public:
    ToDo(const std::string &title, const std::string &description, int priority, const Date &date)
            : Title(title), Description(description), Priority(priority), Finished(false), data(date) {}

    void setDate(const Date& date);

    const Date &getData() const;

    int getPriority() const;

    const  std::string &getDescription() const;

    const std::string &getTitle() const;

    void setDescription(const std::string &description);

    void setTitle(const std::string &title);

    void setPriority(int priority);

    bool isFinished() const;

    void MarkAsFinished();

    void Print_details() const;



private:
    std::string Title;
    std::string Description;
    int Priority;
    bool Finished;
    Date data;


};

#endif //LABORATORY_OF_PROGRAMMING_TODO_H
