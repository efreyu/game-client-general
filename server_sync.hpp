#ifndef MGPROJECT_SERVER_SYNC_HPP
#define MGPROJECT_SERVER_SYNC_HPP

namespace mg::inline network {

    struct connectSync {
        unsigned server_time = 0U;

        // User defined object types require serialized the members like this:
        template <class Archive>
        void serialize(Archive& ar) {
            ar(server_time);
        }
    };

}  // namespace mg::inline network

#endif  // MGPROJECT_SERVER_SYNC_HPP
