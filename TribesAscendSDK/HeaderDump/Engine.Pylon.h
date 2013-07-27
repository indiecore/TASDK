#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Volume.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class Pylon : public NavigationPoint
	{
	public:
		enum ENavMeshEdgeType : byte
		{
			NAVEDGE_Normal = 0,
			NAVEDGE_Mantle = 1,
			NAVEDGE_Coverslip = 2,
			NAVEDGE_SwatTurn = 3,
			NAVEDGE_DropDown = 4,
			NAVEDGE_PathObject = 5,
			NAVEDGE_BackRefDummy = 6,
			NAVEDGE_Jump = 7,
			NAVEDGE_MAX = 8,
		};
		class PolyReference
		{
		public:
			ADD_STRUCT(int, PolyId, 20)
			ADD_STRUCT(Actor::ActorReference, OwningPylon, 0)
		};
		ADD_STRUCT(ScriptArray<Object::Vector>, NextPassSeedList, 716)
		ADD_STRUCT(ScriptArray<class Volume*>, ExpansionVolumes, 744)
		ADD_STRUCT(ScriptArray<class Pylon*>, ImposterPylons, 792)
		ADD_STRUCT(ScriptArray<class Actor*>, OnBuild_DisableCollisionForThese, 804)
		ADD_STRUCT(ScriptArray<class Actor*>, OnBuild_EnableCollisionForThese, 816)
		ADD_STRUCT(int, DebugEdgeCount, 828)
		ADD_STRUCT(Object::Vector, ExpansionSphereCenter, 772)
		ADD_BOOL(bForceObstacleMeshCollision, 768, 0x400)
		ADD_BOOL(bDisabled, 768, 0x200)
		ADD_BOOL(bBuildThisPylon, 768, 0x100)
		ADD_BOOL(bDrawObstacleSurface, 768, 0x80)
		ADD_BOOL(bDrawWalkableSurface, 768, 0x40)
		ADD_BOOL(bRenderInShowPaths, 768, 0x20)
		ADD_BOOL(bDrawPolyBounds, 768, 0x10)
		ADD_BOOL(bDrawEdgePolys, 768, 0x8)
		ADD_BOOL(bNeedsCostCheck, 768, 0x4)
		ADD_BOOL(bUseExpansionSphereOverride, 768, 0x2)
		ADD_BOOL(bImportedMesh, 768, 0x1)
		ADD_STRUCT(float, MaxExpansionRadius, 760)
		ADD_STRUCT(float, ExpansionRadius, 756)
		ADD_OBJECT(Pylon, NextPylon, 740)
		ADD_STRUCT(Object::Pointer, OctreeIWasAddedTo, 736)
		ADD_STRUCT(Object::OctreeElementId, OctreeId, 728)
		ADD_STRUCT(Object::Pointer, PathObjectsThatAffectThisPylon, 712)
		ADD_STRUCT(Object::Pointer, WorkingSetPtr, 708)
		ADD_STRUCT(Object::Pointer, DynamicObstacleMesh, 704)
		ADD_STRUCT(Object::Pointer, ObstacleMesh, 700)
		ADD_STRUCT(Object::Pointer, NavMeshPtr, 696)
		ADD_STRUCT(Object::Pointer, VfTable_IEditorLinkSelectionInterface, 692)
		void OnPylonStatusChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.OnPylonStatusChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.IsEnabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanReachPylon(class Pylon* DestPylon, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pylon.CanReachPylon");
			byte params[12] = { NULL };
			*(class Pylon**)&params[0] = DestPylon;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
