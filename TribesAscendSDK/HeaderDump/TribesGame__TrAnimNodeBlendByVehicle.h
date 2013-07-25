#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByVehicle : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn)
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
