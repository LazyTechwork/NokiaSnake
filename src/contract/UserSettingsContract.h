#ifndef NOKIASNAKE_USERSETTINGSCONTRACT_H
#define NOKIASNAKE_USERSETTINGSCONTRACT_H

#include <string>
#include <iostream>
#include <map>
#include "../common/InputAction.h"

namespace Contract {
#pragma pack(push, 1)

    struct UserSettingsContract {
        char name[24];
        uint16_t keyMappingsLen;
        std::map<int, Common::InputAction> keyMappings;

        friend std::ostream &operator<<(std::ostream &os, const UserSettingsContract &contract);

        friend std::istream &operator>>(std::istream &s, UserSettingsContract &contract);
    };

#pragma pack(pop)

} // Contract

#endif //NOKIASNAKE_USERSETTINGSCONTRACT_H
