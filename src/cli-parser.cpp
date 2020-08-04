#include "cli-parser.h"

cli_parser::cli_parser() {
  this->available_options_map.add_options()((this->help_option_long + this->options_separator + 
    this->help_option).c_str(), this->help_option_description.c_str())(
    (this->output_directory_option_long + this->options_separator + this->output_directory_option).c_str(),
    boost::program_options::value<std::string>(), this->output_directory_option_description.c_str())(
    (this->input_directory_option_long + this->options_separator + this->input_directory_option).c_str(),
    boost::program_options::value<std::string>(), this->input_directory_option_description.c_str())(
    (this->search_extension_option_long + this->options_separator + this->search_extension_option).c_str(),
    boost::program_options::value<std::string>(), this->search_extension_option_description.c_str());
}

cli_parser::~cli_parser() {}

void cli_parser::parse(int args_count, char** args_list) {
  boost::program_options::store(boost::program_options::parse_command_line(
    args_count, args_list, this->available_options_map), this->parsed_options_map);
  boost::program_options::notify(this->parsed_options_map);

  if(this->parsed_options_map.count(this->help_option_long)) {
    std::cout << this->available_options_map << std::endl;
    exit(EXIT_SUCCESS);
  }

  if(!(this->parsed_options_map.count(this->output_directory_option_long))) {
    std::cout << "Specify output directory" << std::endl;
    std::cout << this->available_options_map << std::endl;
    exit(EXIT_SUCCESS);
  }

  if(!(this->parsed_options_map.count(this->input_directory_option_long))) {
    std::cout << "Specify input directory" << std::endl;
    std::cout << this->available_options_map << std::endl;
    exit(EXIT_SUCCESS);
  }

  if(!(this->parsed_options_map.count(this->search_extension_option_long))) {
    std::cout << "Specify file extension to search for" << std::endl;
    std::cout << this->available_options_map << std::endl;
    exit(EXIT_SUCCESS);
  }
}

std::string cli_parser::getOutputDirectory() {
  return this->parsed_options_map[this->output_directory_option_long].as<std::string>();
}

std::string cli_parser::getInputDirectory() {
  return this->parsed_options_map[this->input_directory_option_long].as<std::string>();
}

std::string cli_parser::getSearchExtension() {
  return this->parsed_options_map[this->search_extension_option_long].as<std::string>();
}