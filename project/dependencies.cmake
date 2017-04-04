#               Copyright Marek Dalewski 2017
# Distributed under the Boost Software License, Version 1.0.
#        (See accompanying file LICENSE.md or copy at
#           http://www.boost.org/LICENSE_1_0.txt)



##### Boost --------------------------------------------------------------------

# Set options
set(Boost_NO_BOOST_CMAKE     ON)
set(Boost_USE_STATIC_LIBS    ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED  ON)

# Set requied components (by main executable)
set(Boost_COMPONENTS)

# Set requied components (by test executables)
if(ENABLE_TESTING)
    set(Boost_COMPONENTS ${Boost_COMPONENTS})
endif()

# Find package
find_package(Boost 1.56.0 COMPONENTS ${Boost_COMPONENTS} REQUIRED)

# Set include directories
list(APPEND project.include ${Boost_INCLUDE_DIRS})

# Set libraries to link
list(APPEND project.link)
