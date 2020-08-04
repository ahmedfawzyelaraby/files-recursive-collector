#ifndef CLI_PARSER
#define CLI_PARSER

#include <string>
#include <iostream>
#include <vector>

#include <boost/program_options.hpp>
#include "boost/filesystem.hpp"

class cli_parser {
  public:
    cli_parser();
    ~cli_parser();
    void parse(int args_count, char** args_list);
    std::string getOutputDirectory();
    std::string getInputDirectory();
    std::string getSearchExtension();
  private:
    boost::program_options::options_description available_options_map;
    boost::program_options::variables_map parsed_options_map;
    const std::string options_separator = ",";
    const std::string help_option = "h";
    const std::string help_option_long = "help";
    const std::string help_option_description = "print help message";
    const std::string output_directory_option = "o";
    const std::string output_directory_option_long = "output-directory";
    const std::string output_directory_option_description = "directory to save files to";
    const std::string input_directory_option = "i";
    const std::string input_directory_option_long = "input-directory";
    const std::string input_directory_option_description = "directory to search for files in";
    const std::string search_extension_option = "e";
    const std::string search_extension_option_long = "search-extension";
    const std::string search_extension_option_description = "extension to search recursively for";
};

#endif