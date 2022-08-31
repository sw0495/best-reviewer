#include <iostream>

class LibraryBook
{
public:
    LibraryBook(std::string title_,
                std::string author_,
                int available_copies_,
                std::string language_,
                int pages_,
                std::string isbn_)
        : title(title_)
        , author(author_)
        , available_copies(available_copies_)
        , language(language_)
        , pages(pages_)
        , isbn(isbn_)
    {
    }
    // Data public for simplicity of test demo case.
    // In production code, we would have accessors instead.
    std::string title;
    std::string author;
    int available_copies;
    std::string language;
    int pages;
    std::string isbn;
};