cmake_minimum_required(VERSION 2.8)

project(qt-sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(sdldemo
  src/VistaObjeto.cpp
  src/VistaAcido.cpp
  src/VistaEmisor.cpp
  src/VistaReceptor.cpp
  src/VistaBoton.cpp
  src/VistaPuerta.cpp
  src/VistaBloqueMetal.cpp
  src/VistaBloquePiedra.cpp
  src/Area.cpp
  src/SdlTexture.cpp
  src/SdlException.cpp
  src/SdlWindow.cpp
)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

add_executable (portal src/mainTestTerreno.cpp)
target_link_libraries(portal sdldemo SDL2 SDL2_image)


install(FILES assets/emisor_receptor.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/bloque_metal_diag.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/chell.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/miscelanea.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/puertas.png DESTINATION ${CMAKE_BINARY_DIR})
