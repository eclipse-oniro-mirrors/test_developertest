/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "detector.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/stat.h>

using namespace std;
namespace DetectorTest {
    const int HALF = 2;
    const int START_INDEX = 3;
}

namespace{
bool IsPrime(int n)
{
    if (n <= 1) {
        return false;
    }

    if (!(n % DetectorTest::HALF)) {
        return n == DetectorTest::HALF;
    }

    for (int i = DetectorTest::START_INDEX;; i += DetectorTest::HALF) {
        if (i > (n / i)) {
            break;
        }
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

bool FileExist(const char* fileName)
{
    if (fileName == nullptr) {
        return false;
    }
    struct stat myStat;
    return (!stat(fileName, &myStat));
}
}
