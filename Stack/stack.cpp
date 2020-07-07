#include "stack.h"
#include <stdexcept>

bool Stack::is_empty() const noexcept
{
    return elements.empty();
}

void Stack::push(int element)
{
    elements.push_back(element);
}

int Stack::pop()
{
    if (is_empty()) {
        if (default.has_value()) {
            return default.value();
        }
        throw std::out_of_range("Cannot pop an empty stack.");
    }
    int result { elements.back() };
    elements.pop_back();
    return result;
}

std::size_t Stack::size() const noexcept
{
    return elements.size();
}

std::size_t Stack::count(int element) const noexcept
{
    return std::count(std::cbegin(elements), std::cend(elements), element);
}

int Stack::pop_default(int default) noexcept
{
    if (is_empty()) {
        return default;
    }
    return pop();
}

void Stack::set_default(int default) noexcept
{
    this->default = default;
}

void Stack::clear_default() noexcept
{
    default.reset();
}
