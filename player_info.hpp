#ifndef MGPROJECT_PLAYER_INFO_HPP
#define MGPROJECT_PLAYER_INFO_HPP

#include <iostream>
#include <map>
#include <string>

namespace mg::inline network {

    enum class eDeviceInfo : unsigned {
        UNIQUE_ID = 0,
        OS_NAME,
        OS_VERSION,
        DISTRIBUTION_NAME,
        MODEL_NAME,
        PROCESSOR_NAME,
        LOCALE,
        MEMORY_INFO_PHYSICAL,
        MEMORY_INFO_FREE,
        MEMORY_INFO_AVAILABLE,
        DEBUG_BUILD,
        SANDBOXED,
        STDOUT_VERBOSE
    };

    struct playerInfo {
        playerInfo() {};
        std::string name;
        std::string device_id;
        std::string user_id;
        bool is_online = false;
        int session_count = 0;
        std::map<unsigned, std::string> device_info;

        template <class Archive>
        void serialize(Archive& ar) {
            ar(name);
            ar(device_id);
            ar(user_id);
            ar(is_online);
            ar(session_count);
            ar(device_info);
        }

        // move constructor
        playerInfo(playerInfo&& other) noexcept
            : name(other.name)
            , device_id(other.device_id)
            , user_id(other.user_id)
            , is_online(other.is_online)
            , session_count(other.session_count)
            , device_info(other.device_info) {
        }

        // used to serialize the object to bsoncxx document stream
        template <class Output>
        Output to_stream() const {
            Output output{};
            output << "name" << name << "device_id" << device_id << "user_id" << user_id
                   << "is_online" << is_online << "session_count" << session_count;
            return output;
        }
    };

}  // namespace mg::inline network

#endif  // MGPROJECT_PLAYER_INFO_HPP
