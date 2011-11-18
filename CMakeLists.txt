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
    functions/tanhfunction.cpp
    functions/thresholdfunction.cpp
    core/neuron.cpp
    core/network.cpp
    core/link.cpp
    core/layers/layer.cpp
    core/layers/inputlayer.cpp
    core/layers/outputlayer.cpp
    algos/algo.cpp
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
    functions/tanhfunction.h
    functions/thresholdfunction.h
    config.h
    core/neuron.h
    core/network.h
    core/link.h
    core/layers/layer.h
    core/layers/inputlayer.h
    core/layers/outputlayer.h
    algos/algo.h
    )

set(TESTS
    test_networkdata
    test_networkdata_array
    test_networkdata_csv
    test_network_creation)

include_directories( . data functions )

add_library(neurino_shared SHARED ${LIB_SOURCE} ${LIB_HEADERS})

set_target_properties(neurino_shared PROPERTIES OUTPUT_NAME "neurino")

foreach (program ${TESTS})
    add_executable(${program} tests/${program}.cpp)
    target_link_libraries(${program} neurino_shared)
    add_custom_command(TARGET ${program} POST_BUILD COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${program} ${CMAKE_CURRENT_SOURCE_DIR})
endforeach(program)

SET(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/include/neurino)
INSTALL(FILES ${LIB_HEADERS} ${PUGIXML_SOURCE} DESTINATION include/neurino)
INSTALL(TARGETS neurino_shared DESTINATION lib)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
