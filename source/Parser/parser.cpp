#include "../../include/Parser/parser.hpp"

void SVGParser::skip_whitespace(){
    while(pos < content.size() && (content[pos] == ' ' || content[pos] == '\n' || content[pos] == '\t' || content[pos] == '\r')){
        pos++;
    }
}
size_t SVGParser::find_next(char target){
    int temp_pos = pos;
    while(temp_pos < content.size()){
        if(content[temp_pos] == target){
            return temp_pos;
        }
        temp_pos++;
    }
    return std::string::npos; //return npos if target character is not found
}
std::string SVGParser::extract_substring(size_t start, size_t end){
    if(start < content.size() && end <= content.size() && start <= end){
        return content.substr(start, end - start);
    }
    return ""; //return empty string if indices are out of bounds
}
SVGParser::SVGParser(const std::string& m_svg_content) : content(m_svg_content), pos(0) {}
std::vector<GraphicsObject> SVGParser::parse(){
    std::vector<GraphicsObject> objects;
    int curr_state = 0;//numbers based on last character - 0 empty space; 1 < ; 2 tag name; 3 attribute name;
    while(pos < content.size()){
        skip_whitespace();
        if(pos >= content.size())
            break;
        
        if(content[pos] == '<'){
            curr_state = 1;
            pos++;
        }
        else if(content[pos] == '/'){
            pos = find_next('>') + 1;
            curr_state = 0;
            //now need to apply the storage for that particular shape object in the objects vector
        }
        else if(curr_state == 1){
            if(content[pos] == '?' || content[pos] == '!'){
                pos = find_next('>') + 1;//discarding useless tag
                curr_state = 0;
            }
            else{
                int temp_pos = find_next(' ');
                if(temp_pos != std::string::npos){
                    curr_state = 2;
                    std::string temp_tag_name = extract_substring(pos, temp_pos);
                    pos = temp_pos;
                }
                else{
                    break;
                }
            }
        }
        else if(curr_state == 2){
            int temp_pos = find_next('=');
            if(temp_pos != std::string::npos){
                curr_state = 3;
                std::string temp_attr_name = extract_substring(pos, temp_pos);
                temp_attr_name = temp_attr_name.strip(); //to remove any leading or trailing whitespace
                pos = temp_pos + 1;
            }
            else{
                break;
            }
        }
        else if(curr_state == 3){
            if(content[pos] == '"'){
                pos++;
                int temp_pos = find_next('"');
                if(temp_pos != std::string::npos){
                    std::string temp_attr_value = extract_substring(pos, temp_pos);
                    temp_attr_value = temp_attr_value.strip(); //to remove any leading or trailing whitespace
                    pos = temp_pos + 1;
                    curr_state = 2;
                }
                else{
                    break;
                }
            }
        }
    }
}

