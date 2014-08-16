/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include "command.hpp"

SX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(address_decode__invoke)

BOOST_AUTO_TEST_CASE(address_decode__invoke__valid_value__okay_output)
{
    // $ sx address-decode 3J98t1WpEZ73CNmQviecrnyiWrnqRhWNLy
    SX_DECLARE_COMMAND(address_decode);
    command.set_bitcoin_address_argument({ "3J98t1WpEZ73CNmQviecrnyiWrnqRhWNLy" });
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT("b472a266d0bd89c13706a4132ccfb16f7c3b9fcb\n");
}

BOOST_AUTO_TEST_SUITE_END()