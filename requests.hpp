#ifndef MGPROJECT_NETWORK_GENERAL_REQUESTS_HPP
#define MGPROJECT_NETWORK_GENERAL_REQUESTS_HPP

namespace mg::inline network::requests {
    namespace client {
        // setting server time on client
        constexpr auto set_server_time = "set_server_time";
    }  // namespace client

    namespace server {
        // get or create user on server
        namespace usersService {
            constexpr auto get_or_create_user = "get_or_create_user";
        }
    }  // namespace server
}  // namespace mg::inline network::requests

#endif  // MGPROJECT_REQUESTS_HPP
