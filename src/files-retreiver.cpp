#include "files-retreiver.h"

std::vector<boost::filesystem::path> files_retreiver::getAllFilesWithSpecificExtensionRecursivelyInADirectory(
                          const std::string directory_path, const std::string search_extension) {
  boost::filesystem::path boost_directory_path(directory_path);
  std::vector<boost::filesystem::path> retreived_files;

  if(!(boost::filesystem::exists(boost_directory_path) && 
      boost::filesystem::is_directory(boost_directory_path))) {
    return retreived_files;
  }

  for(auto const & current_path : boost::filesystem::recursive_directory_iterator(
      boost_directory_path)) {
    if(boost::filesystem::is_regular_file(current_path) && 
      current_path.path().extension() == search_extension) {
      retreived_files.push_back(current_path.path());
    }
  }

  return retreived_files;
}