#ifndef MGPROJECT_PLAYER_INFO_HPP
#define MGPROJECT_PLAYER_INFO_HPP

#include <map>
#include <string>

namespace mg::inline network {

    enum class eDeviceInfo : unsigned {
        UNIQUE_ID = 0, //get_unique_id string
        OS_NAME, //get_name string
        OS_VERSION, //get_version string
        DISTRIBUTION_NAME, //get_distribution_name string
        MODEL_NAME, //get_model_name string
        PROCESSOR_NAME, //get_processor_name string
        LOCALE, //get_locale string
        MEMORY_INFO_PHYSICAL, //get_memory_info dictionary "physical"
        MEMORY_INFO_FREE, //get_memory_info dictionary "free"
        MEMORY_INFO_AVAILABLE, //get_memory_info dictionary "available"
        DEBUG_BUILD, //is_debug_build bool
        SANDBOXED, //is_sandboxed bool
        STDOUT_VERBOSE //is_stdout_verbose bool
    };

    struct playerInfo {
        std::string name;
        std::string device_id;
        std::string user_id;
        bool is_online = false;
        unsigned session_count = 0;
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
    };

}  // namespace mg::inline network

#endif  // MGPROJECT_PLAYER_INFO_HPP
