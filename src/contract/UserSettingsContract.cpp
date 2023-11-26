#include "UserSettingsContract.h"

namespace Contract {
    std::ostream &operator<<(std::ostream &s, const UserSettingsContract &contract) {
        s.write((char *) &contract.name, sizeof(contract.name));
        auto kML = contract.keyMappings.size();
        s.write((char *) &kML, sizeof(kML));
        for (const auto &mapping: contract.keyMappings) {
            s.write((char *) &mapping.first, sizeof(mapping.first));
            s.write((char *) &mapping.second, sizeof(mapping.second));
        }
        return s;
    }

    std::istream &operator>>(std::istream &s, UserSettingsContract &contract) {
        s.read((char *) &contract.name, sizeof(contract.name));
        s.read((char *) &contract.keyMappingsLen, sizeof(size_t));
        for (int i = 0; i < contract.keyMappingsLen; ++i) {
            std::pair<int, Common::InputAction> p;
            s.read((char *) &p.first, sizeof(p.first));
            s.read((char *) &p.second, sizeof(p.second));
            contract.keyMappings[p.first] = p.second;
        }
        return s;
    }
} // Contract