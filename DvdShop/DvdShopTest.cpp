//
// Created by tc on 07/07/2020.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Customer.h"
#include "doctest.h"

TEST_CASE("video store")
{
    Customer customer{"Fred"};

    SUBCASE("test single new release statement")
    {
        customer.add_rental({Movie{"The Cell", Movie::NEW_RELEASE}, 3});
        CHECK(customer.statement() ==
              "Rental Record for Fred\n\tThe Cell\t9.00\nYou owed 9.00\nYou earned 2 frequent renter points\n");
    }

    SUBCASE("test dual new release statement")
    {
        customer.add_rental({Movie{"The Cell", Movie::NEW_RELEASE}, 3});
        customer.add_rental({Movie{"The Tiger Movie", Movie::NEW_RELEASE}, 3});
        CHECK(customer.statement() == "Rental Record for Fred\n\tThe Cell\t9.00\n\tThe Tiger Movie\t9.00\nYou owed "
                                      "18.00\nYou earned 4 frequent renter points\n");
    }

    SUBCASE("test single children's statement")
    {
        customer.add_rental({Movie{"The Tiger Movie", Movie::CHILDRENS}, 3});
        CHECK(customer.statement() ==
              "Rental Record for Fred\n\tThe Tiger Movie\t1.50\nYou owed 1.50\nYou earned 1 frequent renter points\n");
    }

    SUBCASE("test multiple regular release statement")
    {
        customer.add_rental({Movie{"Plan 9 from Outer Space", Movie::REGULAR}, 1});
        customer.add_rental({Movie{"8 1/2", Movie::REGULAR}, 2});
        customer.add_rental({Movie{"Eraserhead", Movie::REGULAR}, 3});
        CHECK(customer.statement() ==
              "Rental Record for Fred\n\tPlan 9 from Outer Space\t2.00\n\t8 1/2\t2.00\n\tEraserhead\t3.50\nYou owed "
              "7.50\nYou earned 3 frequent renter points\n");
    }
}
