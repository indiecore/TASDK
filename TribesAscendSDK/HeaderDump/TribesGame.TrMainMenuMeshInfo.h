#pragma once
#include "Core.Object.h"
#include "TribesGame.TrObject.h"
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
	class TrMainMenuMeshInfo : public Object
	{
	public:
		struct ParticleSystemInfo
		{
		public:
			ADD_STRUCT(ScriptName, SocketName, 4)
			ADD_OBJECT(ParticleSystem, ParticleSystem, 0)
		};
		ADD_STRUCT(ScriptArray<class TrMainMenuMeshInfo*>, Children, 116)
		ADD_STRUCT(ScriptArray<TrMainMenuMeshInfo::ParticleSystemInfo>, AttachedParticleSystems, 136)
		ADD_STRUCT(ScriptName, ParentSocketName, 128)
		ADD_STRUCT(TrObject::PaperDollInfo, MeshInfo, 60)
		void PreloadTextures(float ForceDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98700);
			byte params[4] = { NULL };
			*(float*)params = ForceDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
