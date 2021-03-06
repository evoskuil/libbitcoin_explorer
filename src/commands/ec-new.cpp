/**
 * Copyright (c) 2011-2019 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/explorer/commands/ec-new.hpp>

#include <iostream>
#include <bitcoin/system.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/utility.hpp>


// The BX_EC_NEW_INVALID_KEY condition is not covered by test.
// This is because is not known what seed will produce an invalid key.
namespace libbitcoin {
namespace explorer {
namespace commands {

using namespace bc::system;

console_result ec_new::invoke(std::ostream& output, std::ostream& error)
{
    // Bound parameters.
    const data_chunk& entropy = get_seed_argument();

    if (entropy.size() < minimum_seed_size)
    {
        error << BX_EC_NEW_SHORT_SEED << std::endl;
        return console_result::failure;
    }

    // Use hd_private to derive and validate a secret from entropy.
    const wallet::hd_private key(entropy);

    if (!key)
    {
        error << BX_EC_NEW_INVALID_KEY << std::endl;
        return console_result::failure;
    }

    output << encode_base16(key.secret()) << std::endl;
    return console_result::okay;
}

} //namespace commands
} //namespace explorer
} //namespace libbitcoin
