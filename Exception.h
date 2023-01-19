#ifndef EXCEPTION_H
#define EXCEPTION_H


class DeckFileNotFound : public std::exception
{
    std::string m_error="Deck File Error: File not found";

    public:
    const char* what() const noexcept override
    {
        return m_error.c_str();
    }
};

class DeckFileFormatError : public std::exception
{
    std::string m_error ="File format error in line ";
    public:
    DeckFileFormatError(int LineNumber)
    {
        m_error += std::to_string(LineNumber);

    }
    const char* what() const noexcept override
    {
        return m_error.c_str();
    
    }
};

class DeckFileInvalidSize : public std::exception
{
    std::string m_error="Deck File Error: Deck size is invalid";

    public:
    const char* what() const noexcept override
    {
        return m_error.c_str();
    }

};

#endif