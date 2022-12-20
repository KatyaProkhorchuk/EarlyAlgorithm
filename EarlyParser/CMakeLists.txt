add_library(EarlyParser SHARED Grammar.cpp EarlyAlgorithm.cpp RuleEarly.cpp)

install(TARGETS EarlyParser
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
)