#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "stack::stack" for configuration "Debug"
set_property(TARGET stack::stack APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(stack::stack PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libstackd.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS stack::stack )
list(APPEND _IMPORT_CHECK_FILES_FOR_stack::stack "${_IMPORT_PREFIX}/lib/libstackd.a" )

# Import target "stack::demo" for configuration "Debug"
set_property(TARGET stack::demo APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(stack::demo PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/demo"
  )

list(APPEND _IMPORT_CHECK_TARGETS stack::demo )
list(APPEND _IMPORT_CHECK_FILES_FOR_stack::demo "${_IMPORT_PREFIX}/bin/demo" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
