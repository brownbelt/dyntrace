include(arch/${arch}/arch_src.cmake)

add_library(fasttp SHARED
    arch/tracepoint.hpp
    ${${arch}_src}
        error.hpp
    fasttp.cpp fasttp.hpp
    location.cpp location.hpp
    options.hpp)
target_include_directories(fasttp PRIVATE ${CAPSTONE_INCLUDE_DIRS})
target_link_libraries(fasttp process tracer ${CAPSTONE_LIBRARIES})