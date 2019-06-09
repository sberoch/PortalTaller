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
	p1Tex("chell.png", window), p2Tex("chell.png", window),
	p3Tex("chell.png", window), p4Tex("chell.png", window),
	miscTex("miscelanea.png", window),
	puertaTex("puertas.png", window),
	efectosTex("efectos.png", window),
	pinToolTex("pin.png", window),
	tortaTex("cake.png", window),
	portalesTex("portales.png", window) {
		contadorID = 0;
		iniciarColores();
}

std::shared_ptr<VistaObjeto> CreadorTexturas::crear(int tipo, int x, int y, int angulo) {
	std::shared_ptr<VistaObjeto> vo;
	switch (tipo) {
		case ID_BLOQUE_METAL: vo.reset(new VistaBloqueMetal(bloqueTex)); break;
		case ID_BLOQUE_PIEDRA: vo.reset(new VistaBloquePiedra(bloqueTex)); break;
		case ID_ACIDO: vo.reset(new VistaAcido(miscTex)); break;
		case ID_EMISOR: vo.reset(new VistaEmisor(emisRecpTex, angulo)); break;
		case ID_RECEPTOR: vo.reset(new VistaReceptor(emisRecpTex, angulo)); break;
		case ID_BOTON: vo.reset(new VistaBoton(miscTex)); break;
		case ID_PUERTA: vo.reset(new VistaPuerta(puertaTex)); break;
		case ID_PIEDRA_MOVIL: vo.reset(new VistaPiedraMovil(efectosTex)); break;
		case ID_BARRERA_ENERGIA: vo.reset(new VistaBarreraEnergia(miscTex, angulo)); break;
		case ID_BOLA_ENERGIA: vo.reset(new VistaBolaEnergia(efectosTex, angulo)); break;
		case ID_PERSONAJE_1: vo.reset(new VistaPersonaje(p1Tex)); break;
		case ID_PERSONAJE_2: vo.reset(new VistaPersonaje(p2Tex)); break;
		case ID_PERSONAJE_3: vo.reset(new VistaPersonaje(p3Tex)); break;
		case ID_PERSONAJE_4: vo.reset(new VistaPersonaje(p4Tex)); break;
		case ID_BLOQUE_DIAGONAL_METAL: vo.reset(new VistaBloqueMetalDiagonal(bloqueTex, angulo)); break;
		case ID_PIN_TOOL: vo.reset(new VistaPinTool(pinToolTex)); break;
		case ID_TORTA: vo.reset(new VistaTorta(tortaTex)); break;
		case ID_PORTAL_AZUL: vo.reset(new VistaPortalAzul(portalesTex, angulo)); break;
		case ID_PORTAL_NARANJA: vo.reset(new VistaPortalNaranja(portalesTex, angulo)); break;
		default: throw std::runtime_error("Error obteniendo vista del objeto debido a id incorrecto");
	}
	++contadorID;
	vo->setPosInicial(x, y);
	vo->setId(contadorID);
	return vo;
}

void CreadorTexturas::iniciarColores() {
	p1Tex.setColor(255,64,64);
	p2Tex.setColor(96,96,255);
	p3Tex.setColor(64,255,64);
	p4Tex.setColor(255,255,64);
}