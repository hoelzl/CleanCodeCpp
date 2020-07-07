#pragma once
#include <vector>
#include <optional>

class Stack {
private:
    std::vector<int> elements;
    std::optional<int> default;

public:
    bool is_empty() const noexcept;
    void push(int element);
    int pop();
    std::size_t size() const noexcept;
    std::size_t count(int element) const noexcept;
    int pop_default(int default) noexcept;
    void set_default(int default) noexcept;
    void clear_default() noexcept;
};