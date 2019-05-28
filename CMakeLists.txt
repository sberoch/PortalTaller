cmake_minimum_required(VERSION 2.8)

project(qt-sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_library(sdldemo
  src/Cliente/Audio.cpp
  src/Cliente/VistaObjeto.cpp
  src/Cliente/VistaObjetoMovil.cpp
  src/Cliente/VistaAcido.cpp
  src/Cliente/VistaEmisor.cpp
  src/Cliente/VistaReceptor.cpp
  src/Cliente/VistaBoton.cpp
  src/Cliente/VistaPuerta.cpp
  src/Cliente/VistaBloqueMetal.cpp
  src/Cliente/VistaBloqueMetalDiagonal.cpp
  src/Cliente/VistaBloquePiedra.cpp
  src/Cliente/VistaPiedraMovil.cpp
  src/Cliente/VistaBarreraEnergia.cpp
  src/Cliente/VistaBolaEnergia.cpp
  src/Cliente/VistaPinTool.cpp
  src/Cliente/VistaTorta.cpp
  src/Cliente/VistaPortalAzul.cpp
  src/Cliente/VistaPortalNaranja.cpp
  src/Cliente/VistaPersonaje.cpp
  src/Cliente/AnimacionPersonaje.cpp
  src/Cliente/Area.cpp
  src/Cliente/SdlTexture.cpp
  src/Cliente/SdlException.cpp
  src/Cliente/SdlWindow.cpp
  src/Cliente/Escena.cpp
  src/Cliente/CreadorTexturas.cpp
  src/Cliente/EnviadorEventos.cpp
  src/Cliente/RecibidorEventos.cpp
  src/Common/Lock.cpp
  src/Common/Thread.cpp
  src/Common/Socket.cpp
  src/Common/Evento.cpp
  src/Common/Cola.cpp
  src/Common/cola_bloqueante.cpp
  src/Common/value_protected.cpp
)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes") 
include_directories(${PROJECT_BINARY_DIR})

add_executable (cliente src/Cliente/mainCliente.cpp)
target_link_libraries(cliente sdldemo SDL2 SDL2_image SDL2_mixer yaml-cpp)


install(FILES assets/emisor_receptor.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/bloque_metal_diag.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/chell.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/miscelanea.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/puertas.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/efectos.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/pin.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/cake.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/portales.png DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/escenario.yaml DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/musica_fondo.mp3 DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/disparo_portal.wav DESTINATION ${CMAKE_BINARY_DIR})
install(FILES assets/salto.wav DESTINATION ${CMAKE_BINARY_DIR})

