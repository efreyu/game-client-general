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
        std::string name;
        std::string device_id;
        std::string user_id;
        bool is_online = false;
        int session_count = 0;
        std::map<int, std::string> device_info;

        template <class Archive>
        void serialize(Archive& ar) {
            ar(name);
            ar(device_id);
            ar(user_id);
            ar(is_online);
            ar(session_count);
            ar(device_info);
        }

        // used to serialize the object to bsoncxx document stream
        template <class Output>
        Output to_stream() const {
            Output output{};
            output << "name" << name << "device_id" << device_id << "user_id" << user_id
                   << "is_online" << is_online << "session_count" << session_count;
            Output device_info_map{};
            for (auto& [kay, val] : device_info) {
//                Output device_info_item{};
//                device_info_item << "id" << kay << "key" << val;
//                device_info_map << device_info_item;
            }
            output << "device_info" << device_info_map;
            return output;
        }

        template <class Input>
        static playerInfo from_bson(const Input& doc) {
            playerInfo p;
            if (doc["name"])
                p.name = doc["name"].get_string().value.to_string();
            if (doc["device_id"])
                p.device_id = doc["device_id"].get_string().value.to_string();
            if (doc["user_id"])
                p.user_id = doc["user_id"].get_string().value.to_string();
            if (doc["is_online"])
                p.is_online = doc["is_online"].get_bool().value;
            if (doc["session_count"])
                p.session_count = doc["session_count"].get_int32().value;
            if (doc["device_info"]) {
                auto dict = doc["device_info"].get_document().view();
                for (auto&& element : dict) {
                    if (dict["id"] && dict["key"]) {
                        int key = dict["key"].get_int32().value;
                        p.device_info[key] = dict["value"].get_string().value.to_string();
                    }
                }
            }

            return p;
        }
    };

}  // namespace mg::inline network

#endif  // MGPROJECT_PLAYER_INFO_HPP
