
#ifndef MEMORYLEDREQUIRED_H_
#define MEMORYLEDREQUIRED_H_

#include "sc_types.h"
#include "Memoryled.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- memoryledIface_del
	- memoryledIfaceLED_kikapcs
	- memoryledIfaceLED_indulj
	- memoryledIfaceLED_veletlenVillanasok
	- memoryledIfaceLED_partyTime
	- memoryledIfaceLED_szomoru
	- memoryledIfaceLED_ujSzintKezdes
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void memoryledIface_del(const Memoryled* handle, const sc_integer time);

extern void memoryledIfaceLED_kikapcs(const Memoryled* handle);
extern void memoryledIfaceLED_indulj(const Memoryled* handle);
extern void memoryledIfaceLED_veletlenVillanasok(const Memoryled* handle, const sc_integer level);
extern void memoryledIfaceLED_partyTime(const Memoryled* handle);
extern void memoryledIfaceLED_szomoru(const Memoryled* handle);
extern void memoryledIfaceLED_ujSzintKezdes(const Memoryled* handle);






#ifdef __cplusplus
}
#endif 

#endif /* MEMORYLEDREQUIRED_H_ */
