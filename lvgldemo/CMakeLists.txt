#
# Copyright (C) 2024 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#

if(CONFIG_XMSDEMO_LVGLDEMO)

  set(CURRENT_DIR ${CMAKE_CURRENT_LIST_DIR})
  set(PROGNAME xmslvgl)
  set(CUR_TARGET xmslvgldemo)
  set(STACKSIZE 16384)

  nuttx_add_prebuilt(BIN_TARGETS ${CUR_TARGET} APP_TARGETS ${PROGNAME})

  nuttx_library_ifndef(SKIP_PREBUILT ${CUR_TARGET})
  nuttx_add_dependencies(TARGET ${CUR_TARGET} DEPENDS android_binder
                         activity_manager)

  set(INCDIR ${CURRENT_DIR} ${CURRENT_DIR}/../)
  file(GLOB_RECURSE CXXRCS ${CURRENT_DIR}/src/*.cpp)
  list(REMOVE_ITEM CXXRCS ${CURRENT_DIR}/src/LvglDemoApplication.cpp)

  nuttx_compile_options(${CFLAGS})
  nuttx_sources(${CXXRCS})
  nuttx_include_directories(${INCDIR})

  set(DSTPATH
      ${NUTTX_APPS_DIR}/vendor/sim/boards/common/resource/app/${PROGNAME})
  execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${DSTPATH})

  execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${CURRENT_DIR}/manifest.json
                          ${DSTPATH})

  # xmslvgl command tool
  if(CONFIG_SYSTEM_PACKAGE_SERVICE_COMMAND)
    nuttx_add_application(
      NAME
      ${PROGNAME}
      STACKSIZE
      ${STACKSIZE}
      PRIORITY
      SCHED_PRIORITY_DEFAULT
      SRCS
      src/LvglDemoApplication.cpp
      INCLUDE_DIRECTORIES
      ${INCDIR}
      DEPENDS
      ${CUR_TARGET})
  endif()

endif()
