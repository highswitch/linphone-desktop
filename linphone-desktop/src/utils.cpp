/*
 * utils.cpp
 * Copyright (C) 2017  Belledonne Communications, Grenoble, France
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *  Created on: March 24, 2017
 *      Author: Ronan Abhamon
 */

 #include "utils.hpp"

// =============================================================================

char *Utils::rstrstr (const char *a, const char *b) {
  size_t a_len = strlen(a);
  size_t b_len = strlen(b);
  const char *s;

  if (b_len > a_len)
    return nullptr;

  for (s = a + a_len - b_len; s >= a; --s) {
    if (!strncmp(s, b, b_len))
      return const_cast<char *>(s);
  }

  return nullptr;
}
