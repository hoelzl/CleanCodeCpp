#include <iostream>
#include <string>
#include "complex_function.h"

int main()
{
    std::string formatted_text { format_text(
        "This is the text to format\n",
        "<<< A header >>>\n",
        "<<< A footer >>>\n",
        10) };
    std::cout << formatted_text << std::endl;

    FormatText format_text_object(
        "This is the text to format with the object\n",
        "<<< A header >>>\n",
        "<<< A footer >>>\n",
        10);

    formatted_text = format_text_object.compute(); 
    
    std::cout << formatted_text << std::endl;

}