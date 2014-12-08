// ============================================================================
// cmd.cpp
// ~~~~~~~
// author : hqn
// - implement the two main commands: validate and display
// - this is the only file you can modify and submit
// ============================================================================

#include <iostream>
#include <sstream>
#include <stack>
#include <map>

#include "cmd.h"
#include "Lexer.h"
#include "term_control.h"
#include "error_handling.h"

using namespace std;

struct TagMap
{
    map<string, term_attrib_t> attributes;
    map<string, term_colors_t> colors;
    TagMap() // the constructor
    {
        colors["red"]     = RED;
        colors["green"]   = GREEN;
        colors["yellow"]  = YELLOW;
        colors["blue"]    = BLUE;
        colors["magenta"] = MAGENTA;
        colors["cyan"]    = CYAN;

        attributes["dim"]       = DIM;
        attributes["underline"] = UNDERLINE;
        attributes["bright"]    = BRIGHT;
    }
};

// return whether expression is valid, report error in error_msg
bool valid(const string& expression, string& error_msg)
{
    // your code goes here
    Lexer lexer;
    Token tok;            
    ostringstream oss;
    stack<string> tag_stack;
    string tag;
    TagMap tm;

    lexer.set_input(expression);

    while (lexer.has_more_token()) 
    {
        tok = lexer.next_token();
        switch (tok.type) 
        {
            case ERRTOK:
                error_msg = "INVALID TOKEN";
                return false;
            case TAG:
                if (tok.value.empty()) {
                    error_msg = "UNKNOWN TAG";
                    return false;
                }
                tag = (tok.value[0] == '/')?  tok.value.substr(1) : tok.value;
                if ( tm.attributes.find(tag) != tm.attributes.end() ||
                     tm.colors.find(tag) != tm.colors.end() ) 
                {
                    if (tok.value[0] != '/') { // valid open tag
                        tag_stack.push(tag);
                    } else {                   // valid close tag
                        if (!tag_stack.empty() && tag == tag_stack.top()) {
                            tag_stack.pop();
                        } else {
                            oss << "EXPRESSION NOT WELL-FORMED";
                            error_msg = oss.str();
                            return false;
                        }
                    }
                } else {
                    error_msg = "UNKNOWN TAG";
                    return false;
                }
                break;
            default:
                break;
        }
    }
    
    if (!tag_stack.empty()) {
        error_msg = "EXPRESSION NOT WELL-FORMED";
        return false;
    }

    error_msg = "";
    return true;
}

// a helper function: reprint all attributes' control codes on the stack
string reprint_attributes(stack<string> tag_stack)
{
    ostringstream oss;
    TagMap tm;
    stack<string> reversedStack;
    while (!tag_stack.empty()) {
        reversedStack.push(tag_stack.top());
        tag_stack.pop();
    }

    oss << term_attrib();
    while (!reversedStack.empty()) {
        oss << term_attrib(tm.attributes[reversedStack.top()]);
        reversedStack.pop();
    }
    return oss.str();
}


string display(const string& expression) 
{
    string error_msg;
    if (!valid(expression, error_msg))
        return error_msg;

    string tag;
    Lexer lexer;
    Token tok;
    stack<string> color_stack;
    stack<string> attribute_stack;
    stack<string> *tag_stack_ptr;
    TagMap tm;
    ostringstream oss;

    lexer.set_input(expression);
    while (lexer.has_more_token()) {
        tok = lexer.next_token();
        if (tok.type == TAG) {
            if (tok.value[0] != '/') 
                tag = tok.value;           // open tag
            else              
                tag = tok.value.substr(1); // close tag

            tag_stack_ptr = (tm.colors.find(tag) != tm.colors.end()?  
                             &color_stack : &attribute_stack);

            if (tok.value[0] != '/') {
                tag_stack_ptr->push(tag);
            } else {
                tag_stack_ptr->pop();
                tag = (tag_stack_ptr->empty()? "" : tag_stack_ptr->top());
            }

            if (tag_stack_ptr == &color_stack) {
                if (tag_stack_ptr->empty())
                    oss << term_fg();
                else
                    oss << term_fg(tm.colors[tag_stack_ptr->top()]);
            } else {
                if (tag_stack_ptr->empty()) {
                    oss << term_attrib();
                    if (!color_stack.empty())
                        oss << term_fg(tm.colors[color_stack.top()]);
                } else {
                    oss << reprint_attributes(*tag_stack_ptr);
                    if (!color_stack.empty())
                        oss << term_fg(tm.colors[color_stack.top()]);
                }
            }
        } else {
            oss << tok.value;
        }
    }
    return oss.str();
}

string validate(const string& expression)
{
    string error_msg;
    if (!valid(expression, error_msg))
        return error_msg;
    else
        return "VALID";
}
