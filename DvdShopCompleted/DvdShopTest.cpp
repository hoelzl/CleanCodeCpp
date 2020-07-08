//
// Created by tc on 07/07/2020.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "ChildrensMovie.h"
#include "NewReleaseMovie.h"
#include "RegularMovie.h"
#include "RentalStatement.h"
#include "doctest.h"
#include <string>

using doctest::Approx;
using namespace std::literals::string_literals;

TEST_CASE("video store")
{
    RentalStatement statement{"Customer Name"};
    NewReleaseMovie new_release_1{"New Release 1"};
    NewReleaseMovie new_release_2{"New Release 2"};
    ChildrensMovie childrens_movie{"Children's"};
    RegularMovie regular_movie_1{"Regular 1"};
    RegularMovie regular_movie_2{"Regular 2"};
    RegularMovie regular_movie_3{"Regular 3"};

    SUBCASE("single new release statement")
    {
        statement.add_rental({new_release_1, 3});
        statement.make_rental_statement();

        CHECK(statement.get_owned() == Approx(9.0));
        CHECK(statement.get_points() == 2);
    }

    SUBCASE("two new release statements")
    {
        statement.add_rental({new_release_1, 3});
        statement.add_rental({new_release_2, 3});
        statement.make_rental_statement();

        CHECK(statement.get_owned() == Approx(18.0));
        CHECK(statement.get_points() == 4);
    }


    SUBCASE("single new children statement")
    {
        statement.add_rental({childrens_movie, 3});
        statement.make_rental_statement();

        CHECK(statement.get_owned() == Approx(1.5));
        CHECK(statement.get_points() == 1);
    }

    SUBCASE("multiple regular statements")
    {
        statement.add_rental({regular_movie_1, 1});
        statement.add_rental({regular_movie_2, 2});
        statement.add_rental({regular_movie_3, 3});
        statement.make_rental_statement();

        CHECK(statement.get_owned() == Approx(7.5));
        CHECK(statement.get_points() == 3);
    }

    SUBCASE("multiple regular statements format")
    {
        statement.add_rental({regular_movie_1, 1});
        statement.add_rental({regular_movie_2, 2});
        statement.add_rental({regular_movie_3, 3});
        statement.make_rental_statement();

        CHECK(statement.make_rental_statement() == "Rental Record for Customer Name\n"
                                                   "\tRegular 1\t2.00\n"
                                                   "\tRegular 2\t2.00\n"
                                                   "\tRegular 3\t3.50\n"
                                                   "You owed 0.00\n"
                                                   "You earned 0 frequent renter points\n"s);
    }
}
