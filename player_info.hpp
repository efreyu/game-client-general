#ifndef MGPROJECT_PLAYER_INFO_HPP
#define MGPROJECT_PLAYER_INFO_HPP

#include <map>
#include <string>

namespace mg::inline network {

    struct playerInfo {
        std::string name;
        std::string device_id;
        std::string user_id;
        bool is_online = false;
        std::map<int, std::string> purview;

        // User defined object types require serialized the members like this:
        template <class Archive>
        void serialize(Archive& ar) {
            ar(name);
            ar(device_id);
            ar(user_id);
            ar(is_online);
            ar(purview);
        }
    };

}  // namespace mg::inline network

#endif  // MGPROJECT_PLAYER_INFO_HPP
