#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPaperDollMainMenu.h"
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
	class TrMainMenuContentData : public Object
	{
	public:
		struct MeshData
		{
		public:
			ADD_OBJECT(TrMainMenuMeshInfo, MainMeshInfo, 4)
			ADD_STRUCT(TrObject::EContentDataType, ContentDataType, 0)
		};
		ADD_STRUCT(ScriptArray<TrMainMenuContentData::MeshData>, m_MeshData, 60)
		void SendPaperDollANewMesh(class TrPaperDollMainMenu* MainMenuPaperDoll, TrObject::EContentDataType ContentDataType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98683);
			byte params[5] = { NULL };
			*(class TrPaperDollMainMenu**)params = MainMenuPaperDoll;
			*(TrObject::EContentDataType*)&params[4] = ContentDataType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreloadTextures(float ForceDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98687);
			byte params[4] = { NULL };
			*(float*)params = ForceDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
