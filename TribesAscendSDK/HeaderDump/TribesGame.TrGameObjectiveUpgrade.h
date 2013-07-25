#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameObjectiveUpgrade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrGameObjectiveUpgrade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameObjectiveUpgrade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameObjectiveUpgrade : public Object
	{
	public:
		ADD_VAR(::FloatProperty, m_fNewValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmClassPropertyName, 0xFFFFFFFF)
		ADD_OBJECT(TrGameObjective, m_Owner)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'm_ClassPropertyPointer'!
		void InitUpgrade(class TrGameObjective* OwnerObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjectiveUpgrade.InitUpgrade");
			byte* params = (byte*)malloc(4);
			*(class TrGameObjective**)params = OwnerObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
