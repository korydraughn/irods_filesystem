#ifndef IRODS_FILESYSTEM_DETAIL_HPP
#define IRODS_FILESYSTEM_DETAIL_HPP

#include <irods/filesystem/path.hpp>
#include <irods/filesystem/filesystem_error.hpp>

#include <irods/rodsDef.h>

namespace irods::filesystem::detail
{
    inline void throw_if_path_length_exceeds_limit(const irods::filesystem::path& _p)
    {
        if (_p.string().size() > MAX_NAME_LEN) {
            throw irods::filesystem::filesystem_error{"path length exceeds max path size"};
        }
    }

    inline auto is_separator(path::value_type _c) noexcept -> bool
    {
        return path::separator == _c;
    }
} // irods::filesystem::detail

#endif // IRODS_FILESYSTEM_DETAIL_HPP
