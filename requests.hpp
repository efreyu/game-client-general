#ifndef MGPROJECT_REQUESTS_HPP
#define MGPROJECT_REQUESTS_HPP

namespace mg::inline network::requests {
    namespace client {
        // setting server time on client
        constexpr auto set_server_time = "set_server_time";
    }

    namespace server {
        // get or create user on server
        constexpr auto get_or_create_user = "get_or_create_user";
    }
}  // namespace mg::inline network::requests

#endif  // MGPROJECT_REQUESTS_HPP
