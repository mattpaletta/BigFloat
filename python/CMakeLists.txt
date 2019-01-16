find_package(SWIG REQUIRED)
include(UseSWIG)
set(CMAKE_SWIG_FLAGS "")

# Include python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

include_directories(../src)

# Add swig module
set_source_files_properties(../src/BigFloat.i PROPERTIES CPLUSPLUS ON)
swig_add_library(BigFloat LANGUAGE python SOURCES ../src/BigFloat.i)
swig_link_libraries(BigFloat ${PYTHON_LIBRARIES})

# Files to install with Python
set(PYTHON_INSTALL_FILES
        ${CMAKE_CURRENT_BINARY_DIR}/BigInteger.py
        ${CMAKE_CURRENT_BINARY_DIR}/_BigInteger.so)

# Configure setup.py and copy to output directory
#set(SETUP_PY_IN ${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in)
#set(SETUP_PY_OUT ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
#configure_file(${SETUP_PY_IN} ${SETUP_PY_OUT})

# Declare install target for python
#install(TARGETS swig_example
#        COMMAND "${PYTHON_EXECUTABLE} setup.py"
#        COMPONENT swig-python)

# Install target to call setup.py
add_custom_target(install-python
        DEPENDS _swig_example
        COMMAND python ${SETUP_PY_OUT} install)