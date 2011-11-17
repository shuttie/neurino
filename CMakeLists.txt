cmake_minimum_required(VERSION 2.6)

project(neurino)

set(LIB_SOURCE 
    data/networkdata.cpp
    data/networkdataarray.cpp
    data/networkdatacsv.cpp
    data/sample.cpp
    functions/elliottfunction.cpp
    functions/elliottsymmfunction.cpp
    functions/function.cpp
    functions/linearfunction.cpp
    functions/sigmoidfunction.cpp
    functions/tanhfunctions.cpp
    functions/thresholdfunctions.cpp
    )

set(LIB_HEADERS 
    data/networkdata.h
    data/networkdataarray.h
    data/networkdatacsv.h
    data/sample.h
    functions/elliottfunction.h
    functions/elliottsymmfunction.h
    functions/function.h
    functions/linearfunction.h
    functions/sigmoidfunction.h
    functions/tanhfunctions.h
    functions/thresholdfunctions.h
    config.h
    )

set(TESTS test_networkdata.cpp test_networkdata_array.cpp test_networkdata_csv.cpp)

include_directories( . data functions )

add_library(neurino_shared SHARED ${LIB_SOURCE} ${LIB_HEADERS})

set_target_properties(neurino_shared PROPERTIES OUTPUT_NAME "neurino")

foreach (program ${TESTS})
    add_executable(${program} tests/${program}.cpp)
    target_link_libraries(${program} neurino_shared)
endforeach(program)    

SET(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include/neurino)
INSTALL(FILES ${LIB_HEADERS} ${PUGIXML_SOURCE} DESTINATION include/neurino)
INSTALL(TARGETS neurino_shared DESTINATION lib)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
