add_executable(HjulmundLoggerTests Core/LoggerTests.cpp)
target_link_libraries(HjulmundLoggerTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundLoggerTests COMMAND HjulmundLoggerTests)

add_executable(HjulmundTimeTests Core/TimeTests.cpp)
target_link_libraries(HjulmundTimeTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundTimeTests COMMAND HjulmundTimeTests)

add_executable(HjulmundMathTests Math/VectorTests.cpp)
target_link_libraries(HjulmundMathTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundMathTests COMMAND HjulmundMathTests)


add_executable(HjulmundEventInputTests Platform/EventInputTests.cpp)
target_link_libraries(HjulmundEventInputTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundEventInputTests COMMAND HjulmundEventInputTests)

add_executable(HjulmundCameraTests Scene/CameraTests.cpp)
target_link_libraries(HjulmundCameraTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundCameraTests COMMAND HjulmundCameraTests)

add_executable(HjulmundApplicationTests Runtime/ApplicationTests.cpp)
target_link_libraries(HjulmundApplicationTests PRIVATE Hjulmund::Engine)
add_test(NAME HjulmundApplicationTests COMMAND HjulmundApplicationTests)
