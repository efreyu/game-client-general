#ifndef MGPROJECT_NETWORK_GENERAL_EVENT_INFO_HPP
#define MGPROJECT_NETWORK_GENERAL_EVENT_INFO_HPP

#include <map>
#include <string>

namespace mg::inline network {

    struct eventInfo {
        std::string type;
        float start_time;
        float end_time;
        std::map<std::string, int> score;  // key: user_id, value: score
        bool is_ended = false;
        int user_limit = 5;

        // User defined object types require serialized the members like this:
        template <class Archive>
        void serialize(Archive& ar) {
            ar(type);
            ar(start_time);
            ar(end_time);
            ar(score);
            ar(is_ended);
            ar(user_limit);
        }
    };

}  // namespace mgserver

#endif  // MGPROJECT_EVENT_INFO_HPP
