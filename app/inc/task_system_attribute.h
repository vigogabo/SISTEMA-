/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file   : task_system_attribute.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_
#define TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/
/* System Statechart - State Transition Table */
/* 	------------------------|  			  Statechart System - State Transition Table 			|--------------------
Current State-----------|------------Event-----------|---[Guard]---|-------Next State-------|------Actions----------------------------------------|
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_AUTO_PRESENTE	|            ACTIVARPARLANTE (1 pulso)                |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_STANDBY      	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_STANDBY      	|                                                     |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |         	   |ST_SYS_AUTO_PRESENTE	|			                                          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |         	   |ST_SYS_TICKET_DISPONIBLE|tick_sys=DEL_SYS_01_MAX && IMPRIMIR TICKET (2 pulsos)|
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_AUTO_PRESENTE	|EV_SYS_01_TOMO_TICKET    	 |             |ST_SYS_AUTO_PRESENTE	| 			                                          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_AUTO_PRESENTE	|			                                          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |         	   |ST_SYS_AUTO_PRESENTE	|        			                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |         	   |ST_SYS_AUTO_PRESENTE	|        			                                  |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |         	   |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |         	   |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_TICKET_DISPONIBLE|EV_SYS_01_TOMO_TICKET    	 |             |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |         	   |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |         	   |ST_SYS_TICKET_TIMER		|               tick_sys=DEL_SYS_01_MAX               |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP  			 |[tick_sys>0] |ST_SYS_TICKET_TIMER		|                     tick_sys--                      |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET	|	      RECUPERAR EL TICKET (2 pulsos)   	          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN    	 |[tick_sys>0] |ST_SYS_TICKET_TIMER		|                     tick_sys--                      |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET 	|	      RECUPERAR EL TICKET (2 pulsos)   	          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_TOMO_TICKET		 |[tick_sys>0] |ST_SYS_TOMO_TICKET     	|                                                     |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET 	|	      RECUPERAR EL TICKET (2 pulsos)   	          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_TICKET_TIMER		|EV_SYS_01_BARRERA_ARRIBA	 |[tick_sys>0] |ST_SYS_TICKET_TIMER		|                     tick_sys--                      |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET	|	      RECUPERAR EL TICKET (2 pulsos)   	          |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO		 |[tick_sys>0] |ST_SYS_TICKET_TIMER    	|                     tick_sys--                      |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET	|	      RECUPERAR EL TICKET (2 pulsos)              |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO	 |[tick_sys>0] |ST_SYS_TICKET_TIMER		|                     tick_sys--                      |
						|							 |-------------|------------------------|-----------------------------------------------------|
						|                			 |[tick_sys==0]|ST_SYS_DEVOLVIO_TICKET	|	      RECUPERAR EL TICKET (2 pulsos)   	          |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_STANDBY			|					                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_DEVOLVIO_TICKET 	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_STANDBY      	|                                                     |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_ABRIENDO_BARRERA	|		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_ABRIENDO_BARRERA	|		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_TOMO_TICKET 		|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_ABRIENDO_BARRERA |		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_ABRIENDO_BARRERA |		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_ABRIENDO_BARRERA |		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_ABRIENDO_BARRERA |		 INICIAR LA APERTURA DE LA BARRERA (blink)    |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_ABRIENDO_BARRERA	|	                                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_ABRIENDO_BARRERA	|	                                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_ABRIENDO_BARRERA	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_ABRIENDO_BARRERA |	                                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_ABRIO_BARRERA 	|	         DEJAR LA BARRERA ARRIBA (Stay ON)        |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_ABRIENDO_BARRERA |	                                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_ABRIENDO_BARRERA |	                                                  |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_ABRIO_BARRERA	|		                                              |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_ABRIO_BARRERA	|		                                              |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_ABRIO_BARRERA	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_ABRIO_BARRERA	|		                                              |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_ABRIO_BARRERA 	|		                                              |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_CERRANDO_BARRERA	|		 INCIAR EL CIERRE DE LA BARRERA (blink)       |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_ABRIO_BARRERA	|		                                              |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_CERRANDO_BARRERA	|					                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_CERRANDO_BARRERA	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_CERRANDO_BARRERA	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_CERRANDO_BARRERA |                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_CERRANDO_BARRERA	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_CERRANDO_BARRERA |                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_BARRERA_CERRADA  |            DAR POR CERRADA LA BARRERA (LED OFF)     |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_LOOP				 |   	       |ST_SYS_STANDBY			|					                                  |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BOTON_DOWN   	 |       	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
ST_SYS_BARRERA_CERRADA 	|EV_SYS_01_TOMO_TICKET    	 |        	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ARRIBA    |         	   |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_INFRARROJO    	 |             |ST_SYS_STANDBY      	|                                                     |
						|----------------------------|-------------|------------------------|-----------------------------------------------------|
						|EV_SYS_01_BARRERA_ABAJO     |       	   |ST_SYS_STANDBY      	|                                                     |
------------------------|----------------------------|-------------|------------------------|-----------------------------------------------------|
 */

/* Events to excite Task System */
typedef enum task_system_ev {EV_SYS_XX_IDLE,
							 EV_SYS_XX_ACTIVE,
							 EV_SYS_LOOP_IDLE,
							 EV_SYS_LOOP_ACTIVE,
							 EV_SYS_PANEL_IDLE,
							 EV_SYS_PANEL_ACTIVE,
							 EV_SYS_TICKET_IDLE,
							 EV_SYS_TICKET_ACTIVE,
							 EV_SYS_FC_ABIERTO_IDLE,
							 EV_SYS_FC_ABIERTO_ACTIVE,
							 EV_SYS_INFRA_IDLE,
							 EV_SYS_INFRA_ACTIVE,
							 EV_SYS_FC_CERRADO_IDLE,
							 EV_SYS_FC_CERRADO_ACTIVE} task_system_ev_t;

/* State of Task System */
typedef enum task_system_st {ST_SYS_XX_STANDBY,
					         ST_SYS_XX_AUTOPRESENTE,
							 ST_SYS_XX_TICKETDISPONIBLE,
							 ST_SYS_XX_TICKETTIMER,
							 ST_SYS_XX_DEVOLVIOTICKET,
							 ST_SYS_XX_TOMOTICKET,
							 ST_SYS_XX_ABRIENDOBARRERA,
							 ST_SYS_XX_ABRIOBARRERA,
							 ST_SYS_XX_CERRANDOBARRERA,
							 ST_SYS_XX_BARRERACERRADA} task_system_st_t;

typedef struct
{
	uint32_t			tick;
	task_system_st_t	state;
	task_system_ev_t	event;
	bool				flag;
} task_system_dta_t;


/********************** external data declaration ****************************/
extern task_system_dta_t task_system_dta;

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_ */

/********************** end of file ******************************************/
