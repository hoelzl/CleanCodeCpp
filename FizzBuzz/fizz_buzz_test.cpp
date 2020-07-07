#include "gmock/gmock.h"
#include <iostream>
#include <sstream>

#include "fizz_buzz.h"

using namespace testing;
using namespace std::literals::string_literals;

class test_say_number : public TestWithParam<std::pair<int, std::string>> {
};

TEST_P(test_say_number, say_number_1_returns_1)
{
    auto [number, result] { GetParam() };
    ASSERT_THAT(say_number(number), Eq(result));
}

INSTANTIATE_TEST_SUITE_P(fizz_buzz,
    test_say_number,
    Values(
        std::make_pair(1, "1"s),
        std::make_pair(3, "Fizz"s),
        std::make_pair(5, "Buzz"s),
        std::make_pair(15, "FizzBuzz"s)));

TEST(test_fizz_buzz, prints_correct_numbers)
{
    std::stringstream output;
    std::string result { "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\n"
                         "Buzz\n11\nFizz\n13\n14\nFizzBuzz\n16\n" };

    fizz_buzz(output, 16);

    ASSERT_THAT(output.str(), Eq(result));
}