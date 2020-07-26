#ifndef FILES_RETREIVER
#define FILES_RETREIVER

#include <vector>
#include <string>

#include <boost/filesystem.hpp>

class files_retreiver {
  public:
  static std::vector<boost::filesystem::path> getAllFilesWithSpecificExtensionRecursivelyInADirectory(
    const std::string directory_path, const std::string search_extension);
};

#endif
