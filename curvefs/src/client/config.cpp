/*
 *  Copyright (c) 2021 NetEase Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*
 * Project: curve
 * Created Date: Thur May 27 2021
 * Author: xuchaojie
 */

#include <string>
#include <gflags/gflags.h>
#include "curvefs/src/client/config.h"

namespace brpc {
DECLARE_int32(defer_close_second);
}  // namespace brpc


namespace curvefs {
namespace client {

void InitMdsOption(Configuration *conf, MdsOption *mdsOpt) {
    LOG_IF(FATAL, !conf->GetStringValue("mds.mdsaddr", &mdsOpt->mdsaddr));
    LOG_IF(FATAL,
           !conf->GetUInt64Value("mds.rpcTimeoutMs", &mdsOpt->rpcTimeoutMs));
}

void InitMetaServerOption(Configuration *conf, MetaServerOption *metaOpt) {
    LOG_IF(FATAL, !conf->GetStringValue("metaserver.msaddr", &metaOpt->msaddr));
    LOG_IF(FATAL, !conf->GetUInt64Value("metaserver.rpcTimeoutMs",
                                        &metaOpt->rpcTimeoutMs));
}

void InitSpaceServerOption(Configuration *conf,
                           SpaceAllocServerOption *spaceOpt) {
    LOG_IF(FATAL, !conf->GetStringValue("spaceserver.spaceaddr",
                                        &spaceOpt->spaceaddr));
    LOG_IF(FATAL, !conf->GetUInt64Value("spaceserver.rpcTimeoutMs",
                                        &spaceOpt->rpcTimeoutMs));
}

void InitBlockDeviceOption(Configuration *conf,
                           BlockDeviceClientOptions *bdevOpt) {
    LOG_IF(FATAL, !conf->GetStringValue("bdev.confpath", &bdevOpt->configPath));
}

void InitS3Option(Configuration *conf,
    S3Option *s3Opt) {
    LOG_IF(FATAL, !conf->)
}

void SetBrpcOpt(Configuration *conf) {
    LOG_IF(FATAL, !conf->GetIntValue("defer.close.second",
                                     brpc::FLAGS_defer_close_second));
}



void InitFuseClientOption(Configuration *conf, FuseClientOption *clientOption) {
    InitMdsOption(conf, &clientOption->mdsOpt);
    InitMetaServerOption(conf, &clientOption->metaOpt);
    InitSpaceServerOption(conf, &clientOption->spaceOpt);
    InitBlockDeviceOption(conf, &clientOption->bdevOpt);
    SetBrpcOpt(conf);
}


}  // namespace client
}  // namespace curvefs
