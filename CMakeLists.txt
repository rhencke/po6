cmake_minimum_required (VERSION 3.3)

project (po6)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/m4
)

# VS Solution Folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#################################### Source ####################################

add_library(po6
  barrier.cc
  cond.cc
  errno.cc
  # fd.cc
  # hostname.cc
  # location.cc
  # ipaddr.cc
  # mmap.cc
  mutex.cc
  # path.cc
  # rwlock.cc
  # socket.cc
  # thread.cc
  # time.cc
)

##################################### Tests ####################################

enable_testing()

set(TESTS
  test/errno
  # test/io/fd
  # test/net/hostname
  # test/net/ipaddr
  # test/net/location
  # test/net/socket
  # test/pathname
  # test/threads/cond
  # test/threads/mutex
  # test/threads/rwlock
  # test/threads/thread
)

set(th_sources test/runner.cc th.cc)

set(test_errno_SOURCES test/errno.cc)
set(test_errno_LDADD_Windows po6)

# set(test_io_fd_SOURCES test/io/fd.cc)
# set(test_io_fd_LDADD_Windows Ws2_32 po6)
# set(test_net_hostname_SOURCES test/net/hostname.cc)
# set(test_net_hostname_LDADD_Windows Ws2_32)
# set(test_net_ipaddr_SOURCES test/net/ipaddr.cc)
# set(test_net_ipaddr_LDADD_Windows Ws2_32)
# set(test_net_location_SOURCES test/net/location.cc)
# set(test_net_location_LDADD_Windows Ws2_32)
# set(test_net_socket_SOURCES test/net/socket.cc)
# set(test_net_socket_LDADD_Windows Ws2_32)
# set(test_pathname_SOURCES test/pathname.cc)
# set(test_pathname_LDADD_Windows Ws2_32)
# set(test_threads_cond_SOURCES test/threads/cond.cc)
# set(test_threads_cond_LDADD_Linux pthread)
# set(test_threads_cond_LDADD_Darwin pthread)
# set(test_threads_mutex_SOURCES test/threads/mutex.cc)
# set(test_threads_mutex_LDADD_Linux pthread)
# set(test_threads_mutex_LDADD_Darwin pthread)
# set(test_threads_thread_SOURCES test/threads/thread.cc)
# set(test_threads_rwlock_SOURCES test/threads/rwlock.cc)
# set(test_threads_rwlock_LDADD_Linux pthread)
# set(test_threads_rwlock_LDADD_Darwin pthread)

function(add_th_test test_path)
  string(REPLACE / _ test_ident ${test_path})
  get_filename_component(test_dir ${test_path} DIRECTORY)
  get_filename_component(test_name ${test_path} NAME)
  add_executable(${test_ident} ${${test_ident}_SOURCES} ${th_sources})
  set_target_properties(${test_ident} PROPERTIES FOLDER ${test_dir} PROJECT_LABEL ${test_name})
  target_link_libraries(${test_ident} ${${test_ident}_LDADD_${CMAKE_SYSTEM_NAME}})
  add_test(${test_ident} ${test_ident})
endfunction()

foreach(test_path ${TESTS})
  add_th_test(${test_path})
endforeach()
