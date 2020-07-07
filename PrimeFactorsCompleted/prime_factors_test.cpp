#include <vector>

#include "prime_factors.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(test_compute_prime_factors, given_2_returns_2)
{
    std::vector<long> expected { 2L };

    ASSERT_THAT(compute_prime_factors(2L), Eq(expected));
}

TEST(test_compute_prime_factors, given_3_returns_3)
{
    std::vector<long> expected { 3L };

    ASSERT_THAT(compute_prime_factors(3L), Eq(expected));
}

TEST(test_compute_prime_factors, given_4_returns_2_2)
{
    std::vector<long> expected { 2L, 2L };

    ASSERT_THAT(compute_prime_factors(4L), Eq(expected));
}

TEST(test_compute_prime_factors, given_5_returns_5)
{
    std::vector<long> expected { 5L };

    ASSERT_THAT(compute_prime_factors(5L), Eq(expected));
}

bool is_prime(long n)
{
    for (long factor = 2; factor < n; ++factor) {
        if (n % factor == 0) {
            return false;
        }
    }
    return true;
}

class is_prime_parametric_test : public TestWithParam<std::pair<long, bool>> {
};

TEST_P(is_prime_parametric_test, test_number)
{
    auto [value, expect_prime] { GetParam() };
    ASSERT_THAT(is_prime(value), Eq(expect_prime));
}

INSTANTIATE_TEST_SUITE_P(is_prime_number,
    is_prime_parametric_test,
    Values(
        std::pair { 2L, true },
        std::pair { 3L, true },
        std::pair { 4L, false },
        std::pair { 5L, true },
        std::pair { 6L, false },
        std::pair { 256L, false }));

class compute_prime_factors_parametric_test : public TestWithParam<long> {
};

TEST_P(compute_prime_factors_parametric_test, property_test_example)
{
    long number = GetParam();
    std::vector factors { compute_prime_factors(number) };

    // Check that the product of the factors results in the original
    // number, and that each factor is a prime number.
    long result { 1L };
    for (long factor : factors) {
        ASSERT_TRUE(is_prime(factor));
        result *= factor;
    }
    ASSERT_THAT(result, Eq(number));
}

INSTANTIATE_TEST_SUITE_P(check_factor_properties,
    compute_prime_factors_parametric_test,
    Range(2L, 5L));
