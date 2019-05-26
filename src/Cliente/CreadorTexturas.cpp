#include "CreadorTexturas.h"
#include <iostream>
#include "../Common/Constantes.h"

#include "VistaBloqueMetal.h"
#include "VistaBloquePiedra.h"
#include "VistaAcido.h"
#include "VistaEmisor.h"
#include "VistaReceptor.h"
#include "VistaBoton.h"
#include "VistaPuerta.h"
#include "VistaPiedraMovil.h"
#include "VistaBarreraEnergia.h"
#include "VistaBolaEnergia.h"
#include "VistaPersonaje.h"
#include "VistaBloqueMetalDiagonal.h"
#include "VistaPinTool.h"
#include "VistaTorta.h"
#include "VistaPortalAzul.h"
#include "VistaPortalNaranja.h"


CreadorTexturas::CreadorTexturas(const SdlWindow& window) :
	bloqueTex("bloque_metal_diag.png", window), 
	emisRecpTex("emisor_receptor.png", window),
	personajeTex("chell.png", window),
	miscTex("miscelanea.png", window),
	puertaTex("puertas.png", window),
	efectosTex("efectos.png", window),
	pinToolTex("pin.png", window), 
	tortaTex("cake.png", window),
	portalesTex("portales.png", window) {
}

VistaObjeto* CreadorTexturas::crear(int tipo, int x, int y) {
	VistaObjeto* vo;
	switch (tipo) {
		case ID_BLOQUE_METAL: vo = new VistaBloqueMetal(bloqueTex); break;
		case ID_BLOQUE_PIEDRA: vo = new VistaBloquePiedra(bloqueTex); break;
		case ID_ACIDO: vo = new VistaAcido(miscTex); break;
		case ID_EMISOR: vo = new VistaEmisor(emisRecpTex); break;
		case ID_RECEPTOR: vo = new VistaReceptor(emisRecpTex); break;
		case ID_BOTON: vo = new VistaBoton(miscTex); break;
		case ID_PUERTA: vo = new VistaPuerta(puertaTex); break;
		case ID_PIEDRA_MOVIL: vo = new VistaPiedraMovil(efectosTex); break;
		case ID_BARRERA_ENERGIA: vo = new VistaBarreraEnergia(miscTex); break;
		case ID_BOLA_ENERGIA: vo = new VistaBolaEnergia(efectosTex); break;
		case ID_PERSONAJE: vo = new VistaPersonaje(personajeTex); break;
		case ID_BLOQUE_DIAGONAL_METAL: vo = new VistaBloqueMetalDiagonal(bloqueTex); break;
		case ID_PIN_TOOL: vo = new VistaPinTool(pinToolTex); break;
		case ID_TORTA: vo = new VistaTorta(tortaTex); break;
		case ID_PORTAL_AZUL: vo = new VistaPortalAzul(portalesTex); break;
		case ID_PORTAL_NARANJA: vo = new VistaPortalNaranja(portalesTex); break;
		default: std::cout << "Error obteniendo vista del objeto: " << tipo << std::endl; break;
	}
	vo->setPosInicial(x, y);
	return vo;
}

CreadorTexturas::~CreadorTexturas() {
}