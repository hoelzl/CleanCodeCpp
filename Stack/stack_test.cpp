#include "stack.h"
#include "gmock/gmock.h"

using namespace testing;

struct StackFixture : public Test {
  Stack unit{};
  int a_random_number{17};
  int another_random_number{34};
  int a_third_random_number{49};
};

TEST_F(StackFixture, newly_constructed_stack_is_empty) {
  ASSERT_TRUE(unit.is_empty());
}

TEST_F(StackFixture, size_of_an_empty_stack_is_zero) {
  ASSERT_THAT(unit.size(), Eq(0));
}

TEST_F(StackFixture, stack_is_not_empty_after_pushing_an_element) {
  unit.push(a_random_number);

  ASSERT_FALSE(unit.is_empty());
}

TEST_F(StackFixture, stack_has_size_one_after_pushing_an_element) {
  unit.push(a_random_number);

  ASSERT_THAT(unit.size(), Eq(1));
}

TEST_F(StackFixture, stack_has_size_three_after_pushing_three_elements) {
  unit.push(a_random_number);
  unit.push(another_random_number);
  unit.push(a_third_random_number);

  ASSERT_THAT(unit.size(), Eq(3));
}

TEST_F(StackFixture, push_places_element_on_stack) {
  unit.push(a_random_number);

  ASSERT_THAT(unit.pop(), Eq(a_random_number));
}

TEST_F(StackFixture, pop_takes_the_element_from_a_stack_of_size_one) {
  unit.push(a_random_number);

  int result{unit.pop()};
  ASSERT_THAT(result, Eq(a_random_number));
  ASSERT_TRUE(unit.is_empty());
}

TEST_F(StackFixture, pop_takes_the_topmost_element_from_a_stack_of_size_three) {
  unit.push(a_random_number);
  unit.push(another_random_number);
  unit.push(a_third_random_number);

  int result{unit.pop()};

  ASSERT_THAT(result, Eq(a_third_random_number));
  ASSERT_THAT(unit.size(), Eq(2));
}

TEST_F(StackFixture, pop_throws_an_exception_when_called_on_empty_stack) {
  ASSERT_THROW(unit.pop(), std::out_of_range);
}

TEST_F(StackFixture, count_returns_zero_for_empty_stack) {
  ASSERT_THAT(unit.count(a_random_number), Eq(0));
}

TEST_F(StackFixture, count_counts_number_of_occurrences_on_stack) {
  unit.push(a_random_number);
  unit.push(another_random_number);
  unit.push(a_random_number);
  unit.push(a_third_random_number);

  ASSERT_THAT(unit.count(a_random_number), Eq(2));
}

TEST_F(StackFixture, count_does_not_count_elements_not_on_the_stack) {
  unit.push(a_random_number);
  unit.push(a_random_number);
  unit.pop();
  ASSERT_THAT(unit.count(a_random_number), Eq(1));
}

TEST_F(StackFixture, pop_default_takes_the_element_from_a_stack_of_size_one) {
  unit.push(a_random_number);

  int result{unit.pop_default(another_random_number)};
  ASSERT_THAT(result, Eq(a_random_number));
  ASSERT_TRUE(unit.is_empty());
}

TEST_F(StackFixture,
       pop_default_takes_the_topmost_element_from_a_stack_of_size_three) {
  unit.push(a_random_number);
  unit.push(another_random_number);
  unit.push(a_third_random_number);

  int result{unit.pop_default(another_random_number)};

  ASSERT_THAT(result, Eq(a_third_random_number));
  ASSERT_THAT(unit.size(), Eq(2));
}

TEST_F(StackFixture, pop_default_returns_default_value_when_stack_is_empty) {
  int result{unit.pop_default(a_random_number)};

  ASSERT_THAT(result, Eq(a_random_number));
  ASSERT_TRUE(unit.is_empty());
}

TEST_F(StackFixture, pop_on_empty_stack_returns_default_value_when_it_is_set) {
  unit.set_default(a_random_number);
  ASSERT_THAT(unit.pop(), Eq(a_random_number));
}

TEST_F(StackFixture, reset_default_clears_default_value) {
  unit.set_default(a_random_number);
  unit.clear_default();

  ASSERT_THROW(unit.pop(), std::out_of_range);
}
