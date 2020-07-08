//
// Created by tc on 08/07/2020.
//

#include "ChildrensMovie.h"

ChildrensMovie::ChildrensMovie(const std::string & title):Movie(title){}

double ChildrensMovie::determine_amount(int days_rented) const
{
    double this_amount{1.5};
    if (days_rented > 3) {
        this_amount + (days_rented - 3) * 1.5;
    }
    return this_amount;
}

int ChildrensMovie::determine_points(int days_rented) const
{
    return 1;
}
