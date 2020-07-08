//
// Created by tc on 08/07/2020.
//

#ifndef EMPLOYEE_PROJECT_H
#define EMPLOYEE_PROJECT_H

#include <string>

class Project
{
private:
    std::string name;
    double assets;
public:
    Project(std::string  name, double assets);
    [[nodiscard]] double get_assets() const;
};


#endif//EMPLOYEE_PROJECT_H
