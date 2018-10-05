
#include "Memoryled.h"
#include "sc_types.h"
#include "MemoryledRequired.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'memoryled'
*/

/* prototypes of all internal functions */
static sc_boolean check_d_Inditas_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Indulas_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_LED_villogtatas_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2_tr2(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3_tr3(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4_tr4(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5_tr5(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Nyertunk_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s_Vesztettunk_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_0_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_0_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_1_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_1_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_2_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_2_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_3_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_3_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_4_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_4_tr0_tr0(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_5_tr1_tr1(const Memoryled* handle);
static sc_boolean check_d_Fut_a_jatek_s__choice_5_tr0_tr0(const Memoryled* handle);
static void effect_d_Inditas_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Indulas_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_LED_villogtatas_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Nyertunk_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s_Vesztettunk_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_0_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_0_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_1_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_1_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_2_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_2_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_3_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_3_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_4_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_4_tr0(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_5_tr1(Memoryled* handle);
static void effect_d_Fut_a_jatek_s__choice_5_tr0(Memoryled* handle);
static void enact_d_Inditas(Memoryled* handle);
static void enact_d_Fut_a_jatek_s_Indulas(Memoryled* handle);
static void enact_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle);
static void enact_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle);
static void enact_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle);
static void exact_d_Inditas(Memoryled* handle);
static void exact_d_Fut_a_jatek_s_Indulas(Memoryled* handle);
static void enseq_d_Inditas_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_Indulas_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_LED_villogtatas_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_Nyertunk_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_Vesztettunk_default(Memoryled* handle);
static void enseq_d_default(Memoryled* handle);
static void enseq_d_Fut_a_jatek_s_default(Memoryled* handle);
static void exseq_d_Inditas(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s_Indulas(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle);
static void exseq_d(Memoryled* handle);
static void exseq_d_Fut_a_jatek_s(Memoryled* handle);
static void react_d_Inditas(Memoryled* handle);
static void react_d_Fut_a_jatek_s_Indulas(Memoryled* handle);
static void react_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle);
static void react_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(Memoryled* handle);
static void react_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle);
static void react_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_0(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_1(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_2(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_3(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_4(Memoryled* handle);
static void react_d_Fut_a_jatek_s__choice_5(Memoryled* handle);
static void react_d__entry_Default(Memoryled* handle);
static void react_d_Fut_a_jatek_s__entry_Default(Memoryled* handle);
static void clearInEvents(Memoryled* handle);
static void clearOutEvents(Memoryled* handle);


void memoryled_init(Memoryled* handle)
{
		sc_integer i;
	
		for (i = 0; i < MEMORYLED_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Memoryled_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart memoryled */
		handle->iface.szml = 0;
		handle->ifaceVLSZ.kov = 0;
		handle->ifaceVLSZ.szintSzml = 1;
		handle->ifaceVLSZ.max = 42;
}

void memoryled_enter(Memoryled* handle)
{
	/* Default enter sequence for statechart memoryled */
	enseq_d_default(handle);
}

void memoryled_runCycle(Memoryled* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < MEMORYLED_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Memoryled_d_Inditas:
		{
			react_d_Inditas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Indulas:
		{
			react_d_Fut_a_jatek_s_Indulas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_LED_villogtatas:
		{
			react_d_Fut_a_jatek_s_LED_villogtatas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra:
		{
			react_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Nyertunk:
		{
			react_d_Fut_a_jatek_s_Nyertunk(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Vesztettunk:
		{
			react_d_Fut_a_jatek_s_Vesztettunk(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void memoryled_exit(Memoryled* handle)
{
	/* Default exit sequence for statechart memoryled */
	exseq_d(handle);
}

sc_boolean memoryled_isActive(const Memoryled* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < MEMORYLED_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Memoryled_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean memoryled_isFinal(const Memoryled* handle)
{
   return bool_false;
}

sc_boolean memoryled_isStateActive(const Memoryled* handle, MemoryledStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Memoryled_d_Inditas :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_INDITAS] == Memoryled_d_Inditas
			);
			break;
		case Memoryled_d_Fut_a_jatek :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK] >= Memoryled_d_Fut_a_jatek
				&& handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK] <= Memoryled_d_Fut_a_jatek_s_Vesztettunk);
			break;
		case Memoryled_d_Fut_a_jatek_s_Indulas :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK_S_INDULAS] == Memoryled_d_Fut_a_jatek_s_Indulas
			);
			break;
		case Memoryled_d_Fut_a_jatek_s_LED_villogtatas :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK_S_LED_VILLOGTATAS] == Memoryled_d_Fut_a_jatek_s_LED_villogtatas
			);
			break;
		case Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK_S_VARUNK_A_GOMBNYOMASRA] == Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra
			);
			break;
		case Memoryled_d_Fut_a_jatek_s_Nyertunk :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK_S_NYERTUNK] == Memoryled_d_Fut_a_jatek_s_Nyertunk
			);
			break;
		case Memoryled_d_Fut_a_jatek_s_Vesztettunk :
			result = (sc_boolean) (handle->stateConfVector[SCVI_MEMORYLED_D_FUT_A_JATEK_S_VESZTETTUNK] == Memoryled_d_Fut_a_jatek_s_Vesztettunk
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Memoryled* handle)
{
	handle->ifaceGMB.gmb1_raised = bool_false;
	handle->ifaceGMB.gmb2_raised = bool_false;
	handle->ifaceGMB.gmb3_raised = bool_false;
	handle->ifaceGMB.gmb4_raised = bool_false;
	handle->ifaceGMB.gmb5_raised = bool_false;
}

static void clearOutEvents(Memoryled* handle)
{
}



sc_integer memoryledIface_get_szml(const Memoryled* handle)
{
	return handle->iface.szml;
}
void memoryledIface_set_szml(Memoryled* handle, sc_integer value)
{
	handle->iface.szml = value;
}


void memoryledIfaceGMB_raise_gmb1(Memoryled* handle)
{
	handle->ifaceGMB.gmb1_raised = bool_true;
}
void memoryledIfaceGMB_raise_gmb2(Memoryled* handle)
{
	handle->ifaceGMB.gmb2_raised = bool_true;
}
void memoryledIfaceGMB_raise_gmb3(Memoryled* handle)
{
	handle->ifaceGMB.gmb3_raised = bool_true;
}
void memoryledIfaceGMB_raise_gmb4(Memoryled* handle)
{
	handle->ifaceGMB.gmb4_raised = bool_true;
}
void memoryledIfaceGMB_raise_gmb5(Memoryled* handle)
{
	handle->ifaceGMB.gmb5_raised = bool_true;
}




sc_integer memoryledIfaceVLSZ_get_kov(const Memoryled* handle)
{
	return handle->ifaceVLSZ.kov;
}
void memoryledIfaceVLSZ_set_kov(Memoryled* handle, sc_integer value)
{
	handle->ifaceVLSZ.kov = value;
}
sc_integer memoryledIfaceVLSZ_get_szintSzml(const Memoryled* handle)
{
	return handle->ifaceVLSZ.szintSzml;
}
void memoryledIfaceVLSZ_set_szintSzml(Memoryled* handle, sc_integer value)
{
	handle->ifaceVLSZ.szintSzml = value;
}
sc_integer memoryledIfaceVLSZ_get_max(const Memoryled* handle)
{
	return handle->ifaceVLSZ.max;
}
void memoryledIfaceVLSZ_set_max(Memoryled* handle, sc_integer value)
{
	handle->ifaceVLSZ.max = value;
}

/* implementations of all internal functions */

static sc_boolean check_d_Inditas_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s_Indulas_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s_LED_villogtatas_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0_tr0(const Memoryled* handle)
{
	return (handle->iface.szml == handle->ifaceVLSZ.szintSzml) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1_tr1(const Memoryled* handle)
{
	return handle->ifaceGMB.gmb1_raised;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2_tr2(const Memoryled* handle)
{
	return handle->ifaceGMB.gmb2_raised;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3_tr3(const Memoryled* handle)
{
	return handle->ifaceGMB.gmb3_raised;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4_tr4(const Memoryled* handle)
{
	return handle->ifaceGMB.gmb4_raised;
}

static sc_boolean check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5_tr5(const Memoryled* handle)
{
	return handle->ifaceGMB.gmb5_raised;
}

static sc_boolean check_d_Fut_a_jatek_s_Nyertunk_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s_Vesztettunk_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_0_tr0_tr0(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.szintSzml > handle->ifaceVLSZ.max) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_0_tr1_tr1(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_1_tr1_tr1(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.kov == 1) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_1_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_2_tr1_tr1(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.kov == 2) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_2_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_3_tr1_tr1(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.kov == 3) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_3_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_4_tr1_tr1(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.kov == 4) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_4_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_5_tr1_tr1(const Memoryled* handle)
{
	return (handle->ifaceVLSZ.kov == 5) ? bool_true : bool_false;
}

static sc_boolean check_d_Fut_a_jatek_s__choice_5_tr0_tr0(const Memoryled* handle)
{
	return bool_true;
}

static void effect_d_Inditas_tr0(Memoryled* handle)
{
	exseq_d_Inditas(handle);
	enseq_d_Fut_a_jatek_default(handle);
}

static void effect_d_Fut_a_jatek_s_Indulas_tr0(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Indulas(handle);
	enseq_d_Fut_a_jatek_s_LED_villogtatas_default(handle);
}

static void effect_d_Fut_a_jatek_s_LED_villogtatas_tr0(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_LED_villogtatas(handle);
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = 0;
	handle->ifaceVLSZ.szintSzml = handle->ifaceVLSZ.szintSzml + 1;
	react_d_Fut_a_jatek_s__choice_0(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = handle->iface.szml + 1;
	react_d_Fut_a_jatek_s__choice_1(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = handle->iface.szml + 1;
	react_d_Fut_a_jatek_s__choice_2(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = handle->iface.szml + 1;
	react_d_Fut_a_jatek_s__choice_3(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = handle->iface.szml + 1;
	react_d_Fut_a_jatek_s__choice_4(handle);
}

static void effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
	handle->iface.szml = handle->iface.szml + 1;
	react_d_Fut_a_jatek_s__choice_5(handle);
}

static void effect_d_Fut_a_jatek_s_Nyertunk_tr0(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Nyertunk(handle);
	enseq_d_Fut_a_jatek_s_Nyertunk_default(handle);
}

static void effect_d_Fut_a_jatek_s_Vesztettunk_tr0(Memoryled* handle)
{
	exseq_d_Fut_a_jatek_s_Vesztettunk(handle);
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_0_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Nyertunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_0_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Indulas_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_1_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_1_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_2_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_2_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_3_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_3_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_4_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_4_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_5_tr1(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(handle);
}

static void effect_d_Fut_a_jatek_s__choice_5_tr0(Memoryled* handle)
{
	enseq_d_Fut_a_jatek_s_Vesztettunk_default(handle);
}

/* Entry action for state 'Inditas'. */
static void enact_d_Inditas(Memoryled* handle)
{
	/* Entry action for state 'Inditas'. */
	memoryledIfaceLED_indulj(handle);
}

/* Entry action for state 'Indulas'. */
static void enact_d_Fut_a_jatek_s_Indulas(Memoryled* handle)
{
	/* Entry action for state 'Indulas'. */
	memoryledIfaceLED_ujSzintKezdes(handle);
}

/* Entry action for state 'LED villogtatas'. */
static void enact_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle)
{
	/* Entry action for state 'LED villogtatas'. */
	memoryledIfaceLED_veletlenVillanasok(handle, handle->ifaceVLSZ.szintSzml - 1);
}

/* Entry action for state 'Nyertunk'. */
static void enact_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle)
{
	/* Entry action for state 'Nyertunk'. */
	memoryledIfaceLED_partyTime(handle);
}

/* Entry action for state 'Vesztettunk'. */
static void enact_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle)
{
	/* Entry action for state 'Vesztettunk'. */
	memoryledIfaceLED_szomoru(handle);
}

/* Exit action for state 'Inditas'. */
static void exact_d_Inditas(Memoryled* handle)
{
	/* Exit action for state 'Inditas'. */
	memoryledIface_del(handle, 500);
}

/* Exit action for state 'Indulas'. */
static void exact_d_Fut_a_jatek_s_Indulas(Memoryled* handle)
{
	/* Exit action for state 'Indulas'. */
	memoryledIface_del(handle, 500);
}

/* 'default' enter sequence for state Inditas */
static void enseq_d_Inditas_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Inditas */
	enact_d_Inditas(handle);
	handle->stateConfVector[0] = Memoryled_d_Inditas;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Fut a jatek */
static void enseq_d_Fut_a_jatek_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Fut a jatek */
	enseq_d_Fut_a_jatek_s_default(handle);
}

/* 'default' enter sequence for state Indulas */
static void enseq_d_Fut_a_jatek_s_Indulas_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Indulas */
	enact_d_Fut_a_jatek_s_Indulas(handle);
	handle->stateConfVector[0] = Memoryled_d_Fut_a_jatek_s_Indulas;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LED villogtatas */
static void enseq_d_Fut_a_jatek_s_LED_villogtatas_default(Memoryled* handle)
{
	/* 'default' enter sequence for state LED villogtatas */
	enact_d_Fut_a_jatek_s_LED_villogtatas(handle);
	handle->stateConfVector[0] = Memoryled_d_Fut_a_jatek_s_LED_villogtatas;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Varunk a gombnyomasra */
static void enseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Varunk a gombnyomasra */
	handle->stateConfVector[0] = Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Nyertunk */
static void enseq_d_Fut_a_jatek_s_Nyertunk_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Nyertunk */
	enact_d_Fut_a_jatek_s_Nyertunk(handle);
	handle->stateConfVector[0] = Memoryled_d_Fut_a_jatek_s_Nyertunk;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Vesztettunk */
static void enseq_d_Fut_a_jatek_s_Vesztettunk_default(Memoryled* handle)
{
	/* 'default' enter sequence for state Vesztettunk */
	enact_d_Fut_a_jatek_s_Vesztettunk(handle);
	handle->stateConfVector[0] = Memoryled_d_Fut_a_jatek_s_Vesztettunk;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region d */
static void enseq_d_default(Memoryled* handle)
{
	/* 'default' enter sequence for region d */
	react_d__entry_Default(handle);
}

/* 'default' enter sequence for region s */
static void enseq_d_Fut_a_jatek_s_default(Memoryled* handle)
{
	/* 'default' enter sequence for region s */
	react_d_Fut_a_jatek_s__entry_Default(handle);
}

/* Default exit sequence for state Inditas */
static void exseq_d_Inditas(Memoryled* handle)
{
	/* Default exit sequence for state Inditas */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
	exact_d_Inditas(handle);
}

/* Default exit sequence for state Indulas */
static void exseq_d_Fut_a_jatek_s_Indulas(Memoryled* handle)
{
	/* Default exit sequence for state Indulas */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
	exact_d_Fut_a_jatek_s_Indulas(handle);
}

/* Default exit sequence for state LED villogtatas */
static void exseq_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle)
{
	/* Default exit sequence for state LED villogtatas */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Varunk a gombnyomasra */
static void exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(Memoryled* handle)
{
	/* Default exit sequence for state Varunk a gombnyomasra */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Nyertunk */
static void exseq_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle)
{
	/* Default exit sequence for state Nyertunk */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Vesztettunk */
static void exseq_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle)
{
	/* Default exit sequence for state Vesztettunk */
	handle->stateConfVector[0] = Memoryled_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region d */
static void exseq_d(Memoryled* handle)
{
	/* Default exit sequence for region d */
	/* Handle exit of all possible states (of memoryled.d) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Memoryled_d_Inditas :
		{
			exseq_d_Inditas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Indulas :
		{
			exseq_d_Fut_a_jatek_s_Indulas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_LED_villogtatas :
		{
			exseq_d_Fut_a_jatek_s_LED_villogtatas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra :
		{
			exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Nyertunk :
		{
			exseq_d_Fut_a_jatek_s_Nyertunk(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Vesztettunk :
		{
			exseq_d_Fut_a_jatek_s_Vesztettunk(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region s */
static void exseq_d_Fut_a_jatek_s(Memoryled* handle)
{
	/* Default exit sequence for region s */
	/* Handle exit of all possible states (of memoryled.d.Fut_a_jatek.s) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Memoryled_d_Fut_a_jatek_s_Indulas :
		{
			exseq_d_Fut_a_jatek_s_Indulas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_LED_villogtatas :
		{
			exseq_d_Fut_a_jatek_s_LED_villogtatas(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Varunk_a_gombnyomasra :
		{
			exseq_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Nyertunk :
		{
			exseq_d_Fut_a_jatek_s_Nyertunk(handle);
			break;
		}
		case Memoryled_d_Fut_a_jatek_s_Vesztettunk :
		{
			exseq_d_Fut_a_jatek_s_Vesztettunk(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Inditas. */
static void react_d_Inditas(Memoryled* handle)
{
	/* The reactions of state Inditas. */
	effect_d_Inditas_tr0(handle);
}

/* The reactions of state Indulas. */
static void react_d_Fut_a_jatek_s_Indulas(Memoryled* handle)
{
	/* The reactions of state Indulas. */
	effect_d_Fut_a_jatek_s_Indulas_tr0(handle);
}

/* The reactions of state LED villogtatas. */
static void react_d_Fut_a_jatek_s_LED_villogtatas(Memoryled* handle)
{
	/* The reactions of state LED villogtatas. */
	effect_d_Fut_a_jatek_s_LED_villogtatas_tr0(handle);
}

/* The reactions of state Varunk a gombnyomasra. */
static void react_d_Fut_a_jatek_s_Varunk_a_gombnyomasra(Memoryled* handle)
{
	/* The reactions of state Varunk a gombnyomasra. */
	if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0_tr0(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr0(handle);
	}  else
	{
		if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1_tr1(handle) == bool_true)
		{ 
			effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr1(handle);
		}  else
		{
			if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2_tr2(handle) == bool_true)
			{ 
				effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr2(handle);
			}  else
			{
				if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3_tr3(handle) == bool_true)
				{ 
					effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr3(handle);
				}  else
				{
					if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4_tr4(handle) == bool_true)
					{ 
						effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr4(handle);
					}  else
					{
						if (check_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5_tr5(handle) == bool_true)
						{ 
							effect_d_Fut_a_jatek_s_Varunk_a_gombnyomasra_tr5(handle);
						} 
					}
				}
			}
		}
	}
}

/* The reactions of state Nyertunk. */
static void react_d_Fut_a_jatek_s_Nyertunk(Memoryled* handle)
{
	/* The reactions of state Nyertunk. */
	effect_d_Fut_a_jatek_s_Nyertunk_tr0(handle);
}

/* The reactions of state Vesztettunk. */
static void react_d_Fut_a_jatek_s_Vesztettunk(Memoryled* handle)
{
	/* The reactions of state Vesztettunk. */
	effect_d_Fut_a_jatek_s_Vesztettunk_tr0(handle);
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_0(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_0_tr0(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_0_tr1(handle);
	}
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_1(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_1_tr1_tr1(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_1_tr1(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_1_tr0(handle);
	}
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_2(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_2_tr1_tr1(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_2_tr1(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_2_tr0(handle);
	}
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_3(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_3_tr1_tr1(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_3_tr1(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_3_tr0(handle);
	}
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_4(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_4_tr1_tr1(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_4_tr1(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_4_tr0(handle);
	}
}

/* The reactions of state null. */
static void react_d_Fut_a_jatek_s__choice_5(Memoryled* handle)
{
	/* The reactions of state null. */
	if (check_d_Fut_a_jatek_s__choice_5_tr1_tr1(handle) == bool_true)
	{ 
		effect_d_Fut_a_jatek_s__choice_5_tr1(handle);
	}  else
	{
		effect_d_Fut_a_jatek_s__choice_5_tr0(handle);
	}
}

/* Default react sequence for initial entry  */
static void react_d__entry_Default(Memoryled* handle)
{
	/* Default react sequence for initial entry  */
	enseq_d_Inditas_default(handle);
}

/* Default react sequence for initial entry  */
static void react_d_Fut_a_jatek_s__entry_Default(Memoryled* handle)
{
	/* Default react sequence for initial entry  */
	enseq_d_Fut_a_jatek_s_Indulas_default(handle);
}


