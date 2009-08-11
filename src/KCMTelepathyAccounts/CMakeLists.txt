project (libkcmtelepathyaccounts)

include_directories (${CMAKE_CURRENT_BINARY_DIR}
                     ${CMAKE_CURRENT_SOURCE_DIR}
)

set (libkcmtelepathyaccounts_SRCS
     abstract-account-ui-plugin.cpp
     abstract-account-ui.cpp
     abstract-account-parameters-widget.cpp
     integer-edit.cpp
     unsigned-integer-edit.cpp
     protocol-select-widget.cpp
     protocol-list-model.cpp
     connection-manager-item.cpp
     protocol-item.cpp
     parameter-edit-widget.cpp
     parameter-edit-delegate.cpp
     parameter-edit-model.cpp
     parameter-item.cpp
     mandatory-parameter-edit-widget.cpp
     optional-parameter-edit-widget.cpp
     dictionary.cpp
     plugin-manager.cpp
)

set (libkcmtelepathyaccounts_HDRS
     abstract-account-ui-plugin.h
     abstract-account-ui.h
     abstract-account-parameters-widget.h
     plugin-macros.h
     integer-edit.h
     unsigned-integer-edit.h
     connection-manager-item.h
     mandatory-parameter-edit-widget.h
     optional-parameter-edit-widget.h
     plugin-manager.h
     protocol-select-widget.h
     protocol-item.h
     parameter-edit-widget.h
)

set (libkcmtelepathyaccounts_PRETTY_HDRS
     include/AbstractAccountUiPlugin
     include/AbstractAccountUi
     include/AbstractAccountParametersWidget
     include/PluginMacros
     include/IntegerEdit
     include/UnsignedIntegerEdit
     include/ConnectionManagerItem
     include/MandatoryParameterEditWidget
     include/OptionalParameterEditWidget
     include/PluginManager
     include/ProtocolSelectWidget
     include/ProtocolItem
     include/ParameterEditWidget
)

kde4_add_ui_files (libkcmtelepathyaccounts_SRCS
                   parameter-edit-widget.ui
                   protocol-select-widget.ui
)

kde4_add_library (kcmtelepathyaccounts
                  SHARED
                  ${libkcmtelepathyaccounts_SRCS}
)

target_link_libraries (kcmtelepathyaccounts
                       ${QT_LIBRARIES}
                       ${KDE4_KDEUI_LIBS}
                       ${TELEPATHY_QT4_LIBRARIES}
)

set_target_properties (kcmtelepathyaccounts PROPERTIES
                       VERSION ${GENERIC_LIB_VERSION}
                       SOVERSION ${GENERIC_LIB_SOVERSION}
)

if (MSVC)
    set_target_properties (kcmtelepathyaccounts PROPERTIES
                           OUTPUT_NAME libkcmtelepathyaccounts
    )
endif (MSVC)

# Install:
install (TARGETS kcmtelepathyaccounts
         ${INSTALL_TARGETS_DEFAULT_ARGS}
)

install (FILES
         ${libkcmtelepathyaccounts_HDRS}
         ${libkcmtelepathyaccounts_PRETTY_HDRS}
         DESTINATION ${INCLUDE_INSTALL_DIR}/KCMTelepathyAccounts COMPONENT Devel
)

install (FILES
         kcmtelepathyaccounts-accountuiplugin.desktop
         DESTINATION ${SERVICETYPES_INSTALL_DIR}
)
