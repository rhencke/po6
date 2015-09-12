// Copyright (c) 2015, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided withs the distribution.
//     * Neither the name of po6 nor the names of its contributors may be used
//       to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// po6
#include "th.h"
#include "po6/errno.h"

namespace
{

TEST(StrerrorTest, KnownErrorString)
{
    // Exact error message is locale/platform specific.
    // Pick a common error type, and just ensure we found some string for it.
    std::string perm_str = po6::strerror(EPERM);

    int cmp = perm_str.compare("unknown error");

    ASSERT_NE(cmp, 0);
}

TEST(StrerrnoTest, KnownErrno)
{
    const char* perm_str = po6::strerrno(EPERM);

    int cmp = strcmp("EPERM", perm_str);

    ASSERT_EQ(cmp, 0);
}

TEST(StrerrnoTest, UnknownErrno)
{
    // Pick something highly unlikely to be an error.
    const char* unknown_str = po6::strerrno(0xBEEFFACE);

    int cmp = strcmp("unknown error", unknown_str);

    ASSERT_EQ(cmp, 0);
}

} // namespace
