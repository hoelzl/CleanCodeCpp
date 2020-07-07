#include <vector>

#include "prime_factors.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(test_compute_prime_factors, given_1_returns_empty_vector)
{
    std::vector<long> expected {};
    ASSERT_THAT(compute_prime_factors(1L), Eq(expected));
}

TEST(test_compute_prime_factors, given_2_returns_2)
{
    // Arrange
    std::vector<long> expected { 2L };

    // Act
    std::vector<long> result { compute_prime_factors(2L) };

    // Assert
    ASSERT_THAT(result, Eq(expected));
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

class is_prime_parametric_test
    : public TestWithParam<std::pair<long, bool>> {
};

TEST_P(is_prime_parametric_test, test_number) {
    auto [value, expect_prime] { GetParam() };
    ASSERT_THAT(is_prime(value), Eq(expect_prime));
}

INSTANTIATE_TEST_SUITE_P(is_prime_number,
    is_prime_parametric_test,
    Values(
        std::pair { 2L, true },
        std::pair { 3L, true },
        std::pair { 4L, false }));

class compute_prime_factors_parametric_test
    : public TestWithParam<long> {
};

TEST_P(compute_prime_factors_parametric_test, property_test_example)
{
    long number { GetParam() };
    std::vector<long> factors { compute_prime_factors(number) };

    long multiplication_result { 1L };
    for (long factor : factors) {
        ASSERT_THAT(is_prime(factor), Eq(true));
        multiplication_result *= factor;
    }
    ASSERT_THAT(multiplication_result, Eq(number));
}

INSTANTIATE_TEST_SUITE_P(check_factor_properties,
    compute_prime_factors_parametric_test,
    Range(2L, 50L));