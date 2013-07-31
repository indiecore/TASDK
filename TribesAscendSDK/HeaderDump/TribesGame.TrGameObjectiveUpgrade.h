#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrGameObjectiveUpgrade : public Object
	{
	public:
		ADD_STRUCT(float, m_fNewValue, 68)
		ADD_STRUCT(ScriptName, m_nmClassPropertyName, 60)
		ADD_OBJECT(TrGameObjective, m_Owner, 76)
		ADD_STRUCT(Object::Pointer, m_ClassPropertyPointer, 72)
		void InitUpgrade(class TrGameObjective* OwnerObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91139);
			byte params[4] = { NULL };
			*(class TrGameObjective**)params = OwnerObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
