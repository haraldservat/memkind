/*
 * Copyright (C) 2014 Intel Corporation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice(s),
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice(s),
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <fstream>
#include <algorithm>
#include <numa.h>
#include <errno.h>
#include <stdlib.h>
#include "common.h"
#include "check.h"
#include "omp.h"
#include "memkind.h"


class EnvTest: public :: testing::Test
{

protected:
    void SetUp()
    {}

    void TearDown()
    {}

};

TEST_F(EnvTest, ErrorEnviron)
{
    int ret = 0;
    int err = MEMKIND_ERROR_ENVIRON;
    unsigned long *nodemask=NULL;
    ret = setenv("MEMKIND_HBW_NODES","-1",1);
    if (-1 == ret) {
        fprintf (stderr, "Error in setting the env variable \n");
        EXPECT_EQ(0, ret);
    }
    ret = MEMKIND_HBW->ops->get_mbind_nodemask(MEMKIND_HBW, nodemask, NUMA_NUM_NODES);
    EXPECT_EQ(err, ret);
}
