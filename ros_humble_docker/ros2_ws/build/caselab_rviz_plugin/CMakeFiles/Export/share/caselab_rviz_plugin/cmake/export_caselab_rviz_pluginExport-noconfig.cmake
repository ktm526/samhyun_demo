#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "caselab_rviz_plugin::caselab_rviz_plugin" for configuration ""
set_property(TARGET caselab_rviz_plugin::caselab_rviz_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(caselab_rviz_plugin::caselab_rviz_plugin PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcaselab_rviz_plugin.so"
  IMPORTED_SONAME_NOCONFIG "libcaselab_rviz_plugin.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS caselab_rviz_plugin::caselab_rviz_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_caselab_rviz_plugin::caselab_rviz_plugin "${_IMPORT_PREFIX}/lib/libcaselab_rviz_plugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
