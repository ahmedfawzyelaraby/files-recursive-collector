#include <string>
#include <vector>

#include <boost/filesystem.hpp>

#include "files-retreiver.h"
#include "files-collector.h"
#include "cli-parser.h"

int main(int argc, char** argv) {
  cli_parser parser;
  parser.parse(argc, argv);

  std::string input_directory = parser.getInputDirectory();
  std::string output_directory = parser.getOutputDirectory();
  std::string search_extension = parser.getSearchExtension();

  std::vector<boost::filesystem::path> found_files = 
    files_retreiver::getAllFilesWithSpecificExtensionRecursivelyInADirectory(
      input_directory, search_extension);

  files_collector::createOutputDirectoryRecurisvely(output_directory);
  files_collector::copyAllFilesToOutputDirectory(found_files, output_directory);
}