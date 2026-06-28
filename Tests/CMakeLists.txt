add_executable(HjulmundLoggerTests Core/LoggerTests.cpp)
target_link_libraries(HjulmundLoggerTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundLoggerTests COMMAND HjulmundLoggerTests)

add_executable(HjulmundTimeTests Core/TimeTests.cpp)
target_link_libraries(HjulmundTimeTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundTimeTests COMMAND HjulmundTimeTests)

add_executable(HjulmundMathTests Math/VectorTests.cpp)
target_link_libraries(HjulmundMathTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundMathTests COMMAND HjulmundMathTests)
