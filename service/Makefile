############################################################################
# apps/frameworks/base/xmsdemo/service/Make.defs
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

PROGNAME  = xmsservice
PRIORITY  = 100
STACKSIZE = 16384

# Hello, World! Example
CXXEXT := .cpp

CXXSRCS += src/MainActivity.cpp
CXXSRCS += src/SettingsService.cpp
CXXSRCS += src/MusicService.cpp
MAINSRC = src/DemoApplication.cpp

LDLIBPATH += -L$(NUTTXLIB)

dstpath="$(APPDIR)/vendor/sim/boards/common/resource/app/$(PROGNAME)/"
${shell if [ ! -d "$(dstpath)" ]; then \
    mkdir -p "$(dstpath)"; \
    fi \
}
${shell cp manifest.json $(dstpath)}

include $(APPDIR)/Application.mk