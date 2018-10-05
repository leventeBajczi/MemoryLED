
#ifndef MEMORYLED_H_
#define MEMORYLED_H_

#include "sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'memoryled'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define MEMORYLED_MAX_ORTHOGONAL_STATES 1


/*! Define indices of states in the StateConfVector */
#define SCVI_MEMORYLED_D_INDITAS 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK_S_INDULAS 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK_S_LED_VILLOGTATAS 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK_S_VARUNK_A_GOMBNYOMASRA 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK_S_NYERTUNK 0
#define SCVI_MEMORYLED_D_FUT_A_JATEK_S_VESZTETTUNK 0

/*! Enumeration of all states */ 
typedef enum
{
	Memoryled_last_state,
	Memoryled_d_Inditas,
	Memoryled_d_Fut_a_jatek,
	Memoryled_d_Fut_a_jatek_s_Indulas,
	Memoryled_d_Fut_a_jatek_s_LED_villogtatas,
	Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra,
	Memoryled_d_Fut_a_jatek_s_Nyertunk,
	Memoryled_d_Fut_a_jatek_s_Vesztettunk
} MemoryledStates;

/*! Type definition of the data structure for the MemoryledIface interface scope. */
typedef struct
{
	sc_integer szml;
} MemoryledIface;





/*! Type definition of the data structure for the MemoryledIfaceGMB interface scope. */
typedef struct
{
	sc_boolean gmb1_raised;
	sc_boolean gmb2_raised;
	sc_boolean gmb3_raised;
	sc_boolean gmb4_raised;
	sc_boolean gmb5_raised;
} MemoryledIfaceGMB;



/*! Type definition of the data structure for the MemoryledIfaceVLSZ interface scope. */
typedef struct
{
	sc_integer kov;
	sc_integer szintSzml;
	sc_integer max;
} MemoryledIfaceVLSZ;




/*! 
 * Type definition of the data structure for the Memoryled state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	MemoryledStates stateConfVector[MEMORYLED_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	MemoryledIface iface;
	MemoryledIfaceGMB ifaceGMB;
	MemoryledIfaceVLSZ ifaceVLSZ;
} Memoryled;



/*! Initializes the Memoryled state machine data structures. Must be called before first usage.*/
extern void memoryled_init(Memoryled* handle);

/*! Activates the state machine */
extern void memoryled_enter(Memoryled* handle);

/*! Deactivates the state machine */
extern void memoryled_exit(Memoryled* handle);

/*! Performs a 'run to completion' step. */
extern void memoryled_runCycle(Memoryled* handle);


/*! Gets the value of the variable 'szml' that is defined in the default interface scope. */ 
extern sc_integer memoryledIface_get_szml(const Memoryled* handle);
/*! Sets the value of the variable 'szml' that is defined in the default interface scope. */ 
extern void memoryledIface_set_szml(Memoryled* handle, sc_integer value);
/*! Raises the in event 'gmb1' that is defined in the interface scope 'GMB'. */ 
extern void memoryledIfaceGMB_raise_gmb1(Memoryled* handle);

/*! Raises the in event 'gmb2' that is defined in the interface scope 'GMB'. */ 
extern void memoryledIfaceGMB_raise_gmb2(Memoryled* handle);

/*! Raises the in event 'gmb3' that is defined in the interface scope 'GMB'. */ 
extern void memoryledIfaceGMB_raise_gmb3(Memoryled* handle);

/*! Raises the in event 'gmb4' that is defined in the interface scope 'GMB'. */ 
extern void memoryledIfaceGMB_raise_gmb4(Memoryled* handle);

/*! Raises the in event 'gmb5' that is defined in the interface scope 'GMB'. */ 
extern void memoryledIfaceGMB_raise_gmb5(Memoryled* handle);

/*! Gets the value of the variable 'kov' that is defined in the interface scope 'VLSZ'. */ 
extern sc_integer memoryledIfaceVLSZ_get_kov(const Memoryled* handle);
/*! Sets the value of the variable 'kov' that is defined in the interface scope 'VLSZ'. */ 
extern void memoryledIfaceVLSZ_set_kov(Memoryled* handle, sc_integer value);
/*! Gets the value of the variable 'szintSzml' that is defined in the interface scope 'VLSZ'. */ 
extern sc_integer memoryledIfaceVLSZ_get_szintSzml(const Memoryled* handle);
/*! Sets the value of the variable 'szintSzml' that is defined in the interface scope 'VLSZ'. */ 
extern void memoryledIfaceVLSZ_set_szintSzml(Memoryled* handle, sc_integer value);
/*! Gets the value of the variable 'max' that is defined in the interface scope 'VLSZ'. */ 
extern sc_integer memoryledIfaceVLSZ_get_max(const Memoryled* handle);
/*! Sets the value of the variable 'max' that is defined in the interface scope 'VLSZ'. */ 
extern void memoryledIfaceVLSZ_set_max(Memoryled* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean memoryled_isActive(const Memoryled* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean memoryled_isFinal(const Memoryled* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean memoryled_isStateActive(const Memoryled* handle, MemoryledStates state);


#ifdef __cplusplus
}
#endif 

#endif /* MEMORYLED_H_ */
