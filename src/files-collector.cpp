#include "files-collector.h"

void files_collector::createOutputDirectoryRecurisvely(std::string output_directory_path) {
  boost::filesystem::create_directories(output_directory_path);
}

void files_collector::copyAllFilesToOutputDirectory(std::vector<boost::filesystem::path> files_pathes,
        std::string output_directory_path) {
  for(int files_iterator = 0; files_iterator < files_pathes.size(); files_iterator++) {
    boost::filesystem::copy_file(files_pathes[files_iterator], output_directory_path + "/" +
          std::to_string(files_iterator) + files_pathes[files_iterator].extension().string());
  }
}