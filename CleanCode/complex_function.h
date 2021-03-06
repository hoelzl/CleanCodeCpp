#pragma once
#include <string>

std::string format_text(std::string text, std::string header, std::string footer, std::size_t num_separator_chars);

class FormatText {
    std::string text; 
    std::string header;
    std::string footer;
    std::size_t num_separator_chars;
    std::size_t min_num_separator_chars { 6 };
    bool include_headers { num_separator_chars > min_num_separator_chars };
    std::string separator { static_cast<char>(num_separator_chars), '=' };
    std::string result {};

public:
    FormatText(std::string text, std::string header, std::string footer, std::size_t num_separator_chars)
    {
        this->text = text;
        this->header = header;
        this->footer = footer;
        this->num_separator_chars = num_separator_chars;
    }

    std::string compute()
    {
        if (include_headers) {
            result += header;
        }
        result += text;
        result += footer;

        return result;
    }
};