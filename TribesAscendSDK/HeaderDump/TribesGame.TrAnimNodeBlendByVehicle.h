#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByVehicle : public TrAnimNodeBlendList
	{
	public:
		enum EVehicleAnims : byte
		{
			VANIM_NoVehicle = 0,
			VANIM_Driving = 1,
			VANIM_Enter = 2,
			VANIM_Exit = 3,
			VANIM_ChangeSeat = 4,
			VANIM_MAX = 5,
		};
		ADD_OBJECT(TrPawn, m_TrPawn, 292)
		void PlayNoVehicleAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByVehicle.PlayNoVehicleAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDrivingAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByVehicle.PlayDrivingAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayEnterAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByVehicle.PlayEnterAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayExitAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByVehicle.PlayExitAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayChangeSeatAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByVehicle.PlayChangeSeatAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
