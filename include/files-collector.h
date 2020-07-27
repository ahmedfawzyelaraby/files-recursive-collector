#ifndef FILES_COLLECTOR
#define FILES_COLLECTOR

#include <vector>
#include <string>

#include <boost/filesystem.hpp>

class files_collector {
  public:
  static void createOutputDirectoryRecurisvely(std::string output_directory_path);
  static void copyAllFilesToOutputDirectory(std::vector<boost::filesystem::path> files_pathes,
        std::string output_directory_path);
};

#endif
