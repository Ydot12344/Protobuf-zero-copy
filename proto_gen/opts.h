#pragma once
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include <map>

inline unsigned int stoui(const std::string& s)
{
    std::istringstream reader(s);
    unsigned int val = 0;
    reader >> val;
    return val;
}

class TOpts {
public:
    void AddOpt(const std::string& name, std::string* storeVal) {
        opts[name] = storeVal;
    }

    void Parse(int argc, char** argv) {
        if (argc != opts.size() + 1)
            throw std::runtime_error("Not enought args");

        for (size_t i = 1; i < argc; i++) {
            ProcessOneArg(argv[i]);
        }
    }

private:
    std::map<std::string, std::string*> opts;

    void ProcessOneArg(std::string arg) {
        if (arg.size() < 5) {
            throw std::runtime_error("arg should be --<arg_name>=<arg_val>");
        }

        if (arg[0] != '-' || arg[1] != '-') {
            throw std::runtime_error("arg should be --<arg_name>=<arg_val>");
        }

        auto pos = arg.find('=', 2);

        if (pos == std::string::npos || pos + 1 == arg.size()) {
            throw std::runtime_error("arg should be --<arg_name>=<arg_val>");
        }

        std::string argName = arg.substr(2, pos - 2);
        
        if (opts.count(argName) == 0) {
            throw std::runtime_error("No such argument registered");
        }

        *opts[argName] = arg.substr(pos+1, arg.size() - pos);
    }
};