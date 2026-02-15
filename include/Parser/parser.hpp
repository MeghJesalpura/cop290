#ifndef parser_hpp
#define parser_hpp
#include <string>
#include <vector>
class SVGParser{
    private:
        std::string content;
        size_t pos;
        void skip_whitespace();
        size_t find_next(char target);
        std::string extract_substring(size_t start, size_t end);
    public:
        SVGParser(const std::string& m_svg_content);
        std::vector<GraphicsObject> parse(const std::string& svg_content);
};

#endif