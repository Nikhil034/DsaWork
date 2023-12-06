#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

std::string simplifyPath(std::string path) {
    std::stringstream ss(path);
    std::vector<std::string> directories;
    std::string dir;
    
    while (getline(ss, dir, '/')) {
        if (dir == "..") {
            if (!directories.empty()) {
                directories.pop_back();
            }
        } else if (dir != "." && !dir.empty()) {
            directories.push_back(dir);
        }
    }

    std::string canonicalPath = "/";
    for (const std::string& directory : directories) {
        canonicalPath += directory + "/";
    }

    if (!directories.empty()) {
        canonicalPath.pop_back(); // Remove the trailing '/'
    }

    return canonicalPath;
}

int main() {
    std::string inputPath = "/a/./b/../../c/";
    std::string simplifiedPath = simplifyPath(inputPath);
    std::cout << "Simplified canonical path: " << simplifiedPath << std::endl;
    return 0;
}
